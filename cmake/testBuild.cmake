# Part of Project EasyLibraries
# Copyright (C) Harith Manoj
# Licensed under Apache License, Version 2.0
# Date: 09 August 2023

file(WRITE "${CMAKE_BINARY_DIR}/run_test_gen.bat" "echo off\necho Run tests with pipe out enabled, and divert output to files\n")

# Function to add executable and test for given sources
# Executable: ${moduleId}Test_${targetName}
# Compiled Sources: ${sourceList}
# Linked Libraries: ${dependancyList}
# Param:
#   [in]    moduleId        : ID to differentiate test of different module / lib.
#   [in]    targetName      : Name of executable to differentiate b/w executables of same module.
#   [in]    sourceList      : List of sources to build relative to the directory.
#   [in]    dependancyList  : List of dependancy.
# Compile Definitions:
#   TEST_${upperCase(moduleId)}_${upperCase(targetName)}
#   TEST_NAME               = ${moduleId}Test_${targetName}
function(unitTestTemplate moduleId targetName sourceList dependancyList createPipe)

    if(${createPipe})
        set(TEST_BUILDER_PIPE_STATUS "PIPED OUT")
    else()
        set(TEST_BUILDER_PIPE_STATUS "")
    endif(${createPipe})

    message(STATUS "-   ${TEST_BUILDER_PIPE_STATUS} Test for ${moduleId}: ${targetName}")
    message(VERBOSE "        Source: ${sourceList} with libraries ${dependancyList}")

    set(TEST_BUILDER_EX_TARGET ${moduleId}Test_${targetName})

    # Create Executable.
    add_executable(${TEST_BUILDER_EX_TARGET} ${sourceList})

    string(TOUPPER ${moduleId} TEST_BUILDER_UPPER_ID)
    string(TOUPPER ${targetName} TEST_BUILDER_UPPER_NAME)

    # Define Macro to provide information to compiled files about the type of build 
    # (That an test is being built, name of test being built).
    target_compile_definitions(${TEST_BUILDER_EX_TARGET} PUBLIC TEST_${TEST_BUILDER_UPPER_ID}_${TEST_BUILDER_UPPER_NAME})
    target_compile_definitions(${TEST_BUILDER_EX_TARGET} PUBLIC TEST_NAME="${TEST_BUILDER_EX_TARGET}")

    foreach(X ${dependancyList})
        target_link_libraries(${TEST_BUILDER_EX_TARGET} PUBLIC ${X}) 
        message(VERBOSE "        Test ${moduleId}> ${targetName}: linking to ${X}")       
    endforeach(X ${dependancyList})
    
    if(${createPipe})
        message(VERBOSE "        Test ${moduleId}> ${targetName}: creating piped output\n")
        file(APPEND "${CMAKE_BINARY_DIR}/run_test_gen.bat" "\necho ${moduleId} : ${targetName}\n")
        file(APPEND "${CMAKE_BINARY_DIR}/run_test_gen.bat" "$<TARGET_FILE:${TEST_BUILDER_EX_TARGET}> > ${CMAKE_CURRENT_SOURCE_DIR}/${targetName}.out.txt\n")
    endif(${createPipe})

    # Add test, fail: FAIL_REGULAR_EXPRESSION "FAIL*"
    add_test(NAME ${TEST_BUILDER_EX_TARGET}_unitTest COMMAND ${TEST_BUILDER_EX_TARGET})
    set_tests_properties(${TEST_BUILDER_EX_TARGET}_unitTest PROPERTIES FAIL_REGULAR_EXPRESSION "FAIL*")
    
endfunction(unitTestTemplate)

# Function to generate batch file to run all test targets and write output to file.
# Script: ${CMAKE_BINARY_DIR}/Pipe/$<CONFIG>_run_test.bat
# Input: ${CMAKE_BINARY_DIR}/run_test_gen.bat
function(pipeTestOutScript)
    file(
        GENERATE 
        OUTPUT
            ${CMAKE_BINARY_DIR}/Pipe/$<CONFIG>_run_test.bat
        INPUT
            ${CMAKE_BINARY_DIR}/run_test_gen.bat
        TARGET
            EasyLibrary
    )
endfunction(pipeTestOutScript)


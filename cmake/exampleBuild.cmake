# Part of Project EasyLibrary
# Copyright (C) Harith Manoj
# Licensed under Apache License, Version 2.0
# Date Created: 09 August 2023

file(WRITE "${CMAKE_BINARY_DIR}/run_ex_gen.bat" "echo off\necho Run examples with pipe out enabled, and divert output to files\n")

# Function to add executable for given sources
# Executable: ${moduleId}Ex_${targetName}
# Compiled Sources: ${sourceList}
# Linked Libraries: ${dependancyList}
# Param:
#   [in]    moduleId        : ID to differentiate examples of different module / lib
#   [in]    targetName      : Name of executable to differentiate b/w executables of same module
#   [in]    sourceList      : List of sources to build relative to the directory.
#   [in]    dependancyList  : List of dependancy.
# Compile Definitions:
#   EX_${upperCase(moduleId)}_${upperCase(targetName)}
#   EXAMPLE_NAME            = ${moduleId}Ex_${targetName}
function(exampleBuildTemplate moduleId targetName sourceList dependancyList createPipe)

    if(${createPipe})
        set(EXAMPLE_BUILDER_PIPE_STATUS "PIPED OUT")
    else()
        set(EXAMPLE_BUILDER_PIPE_STATUS "")
    endif(${createPipe})

    message(STATUS "-   ${EXAMPLE_BUILDER_PIPE_STATUS} Example for ${moduleId}: ${targetName}")
    message(VERBOSE "        Source: ${sourceList} with libraries ${dependancyList}")

    set(EXAMPLE_BUILDER_EX_TARGET ${moduleId}Ex_${targetName})


    add_executable(${EXAMPLE_BUILDER_EX_TARGET} ${sourceList})

    string(TOUPPER ${moduleId} EXAMPLE_BUILDER_UPPER_ID)
    string(TOUPPER ${targetName} EXAMPLE_BUILDER_UPPER_NAME)



    target_compile_definitions(${EXAMPLE_BUILDER_EX_TARGET} PUBLIC EX_${EXAMPLE_BUILDER_UPPER_ID}_${EXAMPLE_BUILDER_UPPER_NAME})
    target_compile_definitions(${EXAMPLE_BUILDER_EX_TARGET} PUBLIC EXAMPLE_NAME="${EXAMPLE_BUILDER_EX_TARGET}")

    foreach(X ${dependancyList})
        target_link_libraries(${EXAMPLE_BUILDER_EX_TARGET} PUBLIC ${X}) 
        message(VERBOSE "        Example ${moduleId}> ${targetName}: linking to ${X}")       
    endforeach(X ${dependancyList})

    
    if(${createPipe})
        message(VERBOSE "        Example ${moduleId}> ${targetName}: creating piped output\n")
        file(APPEND "${CMAKE_BINARY_DIR}/run_ex_gen.bat" "\necho ${moduleId} : ${targetName}\n")
        file(APPEND "${CMAKE_BINARY_DIR}/run_ex_gen.bat" "$<TARGET_FILE:${EXAMPLE_BUILDER_EX_TARGET}> > ${CMAKE_CURRENT_SOURCE_DIR}/${targetName}.out.txt\n")
    endif(${createPipe})

endfunction(exampleBuildTemplate)


# Function to generate batch file to run all example targets and write output to file.
# Script: ${CMAKE_BINARY_DIR}/Pipe/$<CONFIG>_run_ex.bat
# Input: ${CMAKE_BINARY_DIR}/run_ex_gen.bat
function(pipeExampleOutScript)
    file(
        GENERATE 
        OUTPUT
            ${CMAKE_BINARY_DIR}/Pipe/$<CONFIG>_run_ex.bat
        INPUT
            ${CMAKE_BINARY_DIR}/run_ex_gen.bat
        TARGET
            EasyLibrary
    )
endfunction(pipeExampleOutScript)


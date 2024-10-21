# Part of Project EasyLibrary
# Copyright (C) Harith Manoj
# Licensed under Apache License, Version 2.0
# Date: 14 August 2024

cmake_minimum_required(VERSION 3.10)

option(EASY_LIBRARY_BUILD_TEST "Should Build tests along with library" OFF)
option(EASY_LIBRARY_BUILD_EXAMPLE "Should Build examples along with library" OFF)
option(EASY_LIBRARY_BUILD_MATH "Should add easyMath library (OFF if using partial copy of EasyLibrary without source files of easyMath)" ON)
option(EASY_LIBRARY_BUILD_PARSE "Should add easyParse library (OFF is using partial copy of EasyLibrary without source files of easyParse)" ON)
option(EASY_LIBRARY_EXAMPLE_PIPE_OUT "Should pipe output of examples to file" OFF)
option(EASY_LIBRARY_TEST_PIPE_OUT "Should pipe output of tests to file" OFF)

set(EASY_LIBRARY_VERSION 1.0.1)
set(EASY_LIBRARY_BUILD_TYPE alpha)

if(EASY_LIBRARY_BUILD_EXAMPLE)
    if(EASY_LIBRARY_BUILD_TEST)
        # TEST
        # EXAMPLE
        set(EASY_LIBRARY_BUILD_CONFIG "ALL")
    else()
        # NOT TEST
        # EXAMPLE
        set(EASY_LIBRARY_BUILD_CONFIG "LIB_EXAMPLE")
    endif(EASY_LIBRARY_BUILD_TEST)
else()
    if(EASY_LIBRARY_BUILD_TEST)
        # TEST
        # NOT EXAMPLE
        set(EASY_LIBRARY_BUILD_CONFIG "LIB_TEST")
    else()
        # NOT TEST
        # NOT EXAMPLE
        set(EASY_LIBRARY_BUILD_CONFIG "LIB")
    endif(EASY_LIBRARY_BUILD_TEST)
endif(EASY_LIBRARY_BUILD_EXAMPLE)

message(STATUS "CMAKE Now at EasyLibrary Building Variant:    ${EASY_LIBRARY_BUILD_CONFIG}")
message(STATUS "    Configuring for EasyLibrary version:         ${EASY_LIBRARY_VERSION}.${EASY_LIBRARY_BUILD_TYPE}")

set(
    EASY_LIBRARY_INCLUDE_LIST
    include/easyLib/version.h
)

set(
    EASY_MATH_INCLUDE_LIST 
    include/easyMathLib/easyMath.h
)

set(
    EASY_MATH_SOURCE_LIST 
)

set(
    EASY_PARSE_INCLUDE_LIST 
    include/easyParseLib/easyParse.h
    include/easyParseLib/ArgParser.h
)

set(
    EASY_PARSE_SOURCE_LIST 
    src/easyParseLib/easyParse.cpp
    src/easyParseLib/argParser.cpp
)

foreach(file ${EASY_LIBRARY_INCLUDE_LIST})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        message(VERBOSE "      For easyLibrary ${file} found")
    else()
        message(FATAL_ERROR "       For easyLibrary ${file} not found")
    endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
endforeach()

if(EASY_LIBRARY_BUILD_PARSE)
    message(STATUS "    Configuring with EasyParse")
    set(EASY_LIBRARY_BUILD_MATH ON)

    foreach(file ${EASY_PARSE_INCLUDE_LIST})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
            message(VERBOSE "      For easyParse ${file} found")
        else()
            message(FATAL_ERROR "       For easyParse ${file} not found")
        endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    endforeach()
    foreach(file ${EASY_PARSE_SOURCE_LIST})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
            message(VERBOSE "      For easyParse ${file} found")
        else()
            message(FATAL_ERROR "       For easyParse ${file} not found")
        endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    endforeach()

endif(EASY_LIBRARY_BUILD_PARSE)

if(EASY_LIBRARY_BUILD_MATH)
    message(STATUS "    Configuring with EasyMath")

    foreach(file ${EASY_MATH_INCLUDE_LIST})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
            message(VERBOSE "      For easyMath ${file} found")
        else()
            message(FATAL_ERROR "       For easyMath ${file} not found")
        endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    endforeach()
    foreach(file ${EASY_MATH_SOURCE_LIST})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
            message(VERBOSE "      For easyMath ${file} found")
        else()
            message(FATAL_ERROR "       For easyMath ${file} not found")
        endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
    endforeach()

    list(APPEND SOURCE_LIST ${EASY_MATH_SOURCE_LIST})
endif(EASY_LIBRARY_BUILD_MATH)

project(EasyLibrary DESCRIPTION "Collection of C++ libraries")

file(WRITE "${CMAKE_BINARY_DIR}/EasyLibrary.version" "${EASY_LIBRARY_VERSION}.${EASY_LIBRARY_BUILD_TYPE}")



if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    message(STATUS "    Configuring STANDALONE for EasyLibrary")    
    # specify the C++ standard
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED True)

    if(EASY_LIBRARY_BUILD_TEST)
        enable_testing()
    endif(EASY_LIBRARY_BUILD_TEST)

endif(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)


if(CMAKE_CXX_STANDARD LESS 20)
    message(FATAL_ERROR "    Standard minimum of c++20")
endif()

add_library(
    easyLibrary
    INTERFACE
)

target_include_directories(
    easyLibrary INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(easyLibrary PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(easyLibrary PROPERTIES VERSION ${EASY_LIBRARY_VERSION})

if(EASY_LIBRARY_BUILD_MATH)

    add_library(
        easyMath
        INTERFACE
    )

    target_include_directories(
        easyMath INTERFACE 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
    set_target_properties(easyMath PROPERTIES LINKER_LANGUAGE CXX)
    set_target_properties(easyMath PROPERTIES VERSION ${EASY_LIBRARY_VERSION})

    target_link_libraries(
        easyMath INTERFACE
        easyLibrary
    )

endif(EASY_LIBRARY_BUILD_MATH)

if(EASY_LIBRARY_BUILD_PARSE)

    add_library(
        easyParse
        ${EASY_PARSE_SOURCE_LIST}
    )

    target_include_directories(
        easyParse PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
    set_target_properties(easyParse PROPERTIES LINKER_LANGUAGE CXX)
    set_target_properties(easyParse PROPERTIES VERSION ${EASY_LIBRARY_VERSION})

    target_link_libraries(
        easyParse PUBLIC
        easyLibrary
    )

    target_link_libraries(
        easyParse PUBLIC
        easyMath
    )

endif(EASY_LIBRARY_BUILD_PARSE)

if(EASY_LIBRARY_BUILD_EXAMPLE)
    add_subdirectory(example)    
endif(EASY_LIBRARY_BUILD_EXAMPLE)

if(EASY_LIBRARY_BUILD_TEST)
    add_subdirectory(test)    
endif(EASY_LIBRARY_BUILD_TEST)



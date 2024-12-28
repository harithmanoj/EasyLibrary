# Part of Project EasyLibrary
# Copyright (C) Harith Manoj
# Licensed under Apache License, Version 2.0
# Date: 14 August 2024

cmake_minimum_required(VERSION 3.21)

# Basic options
option(EASY_LIBRARY_DEVELOPMENT_BUILD "Build tests, enable warnings, etc" OFF)
option(EASY_LIBRARY_BUILD_MATH "Should add easyMath library (OFF if using partial copy of EasyLibrary without source files of easyMath)" ON)
option(EASY_LIBRARY_BUILD_PARSE "Should add easyParse library (OFF is using partial copy of EasyLibrary without source files of easyParse)" ON)
option(EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT "Use local version of easyCMakeScrripts modules rathar than installed versions" OFF)
option(EASY_LIBRARY_PREPARE_RELEASE "Prepare release scripts" OFF)

include(CMakeDependentOption)

# Development Build Options
cmake_dependent_option(EASY_LIBRARY_BUILD_TEST "Should Build tests along with library" ON EASY_LIBRARY_DEVELOPMENT_BUILD OFF)
cmake_dependent_option(EASY_LIBRARY_TEST_PIPE_OUT "Should pipe output of tests to file" ON EASY_LIBRARY_DEVELOPMENT_BUILD OFF)
cmake_dependent_option(EASY_LIBRARY_BUILD_EXAMPLE "Should Build examples along with library" ON EASY_LIBRARY_DEVELOPMENT_BUILD OFF)
cmake_dependent_option(EASY_LIBRARY_EXAMPLE_PIPE_OUT "Should pipe output of examples to file" ON EASY_LIBRARY_DEVELOPMENT_BUILD OFF)

# Version Info
set(EASY_LIBRARY_VERSION_MAJOR 1)
set(EASY_LIBRARY_VERSION_MINOR 0)
set(EASY_LIBRARY_VERSION_REVISION 1)
set(EASY_LIBRARY_VERSION ${EASY_LIBRARY_VERSION_MAJOR}.${EASY_LIBRARY_VERSION_MINOR}.${EASY_LIBRARY_VERSION_REVISION})
set(EASY_LIBRARY_RELEASE_TYPE alpha)
set(EASY_LIBRARY_RELEASE_CODE 0)


project(EasyLibrary VERSION ${EASY_LIBRARY_VERSION} DESCRIPTION "Collection of C++ libraries")

# Packages
if(NOT EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT)
    find_package(EasyCMakeScripts 1.0.3 REQUIRED)
    set(EASY_CMAKE_SCRIPTS_LOCATION "${EasyCMakeScripts_DIR}")
else()
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/${EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT}")
    set(EASY_CMAKE_SCRIPTS_LOCATION "${CMAKE_SOURCE_DIR}/${EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT}")
endif(NOT EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT)

include(easyCMakeVersion)

message(STATUS "CMAKE Now at EasyLibrary version:         ${EASY_LIBRARY_VERSION}.${EASY_LIBRARY_RELEASE_TYPE}")

if(EASY_LIBRARY_BUILD_PARSE)
    message(STATUS "    Configuring with EasyParse")
    set(EASY_LIBRARY_BUILD_MATH ON)
endif(EASY_LIBRARY_BUILD_PARSE)

if(EASY_LIBRARY_BUILD_MATH)
    message(STATUS "    Configuring with EasyMath")
endif(EASY_LIBRARY_BUILD_MATH)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    message(STATUS "    Configuring STANDALONE for EasyLibrary") 

    if(EASY_LIBRARY_BUILD_TEST)
        enable_testing()
    endif(EASY_LIBRARY_BUILD_TEST)

    set(EASY_LIBRARY_STANDALONE_BUILD ON)
else()
    set(EASY_LIBRARY_STANDALONE_BUILD OFF)
endif(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)

add_library(
    easyLibraryFlags
    INTERFACE
)

easyCMake_targetDefineVersion(
    TARGET easyLibraryFlags
    SCOPE INTERFACE
    MAJOR ${EASY_LIBRARY_VERSION_MAJOR}
    MINOR ${EASY_LIBRARY_VERSION_MINOR}
    REVISION ${EASY_LIBRARY_VERSION_REVISION}
    BUILD_CODE ${EASY_LIBRARY_RELEASE_CODE}
    FULLSTRING "${EASY_LIBRARY_VERSION}.${EASY_LIBRARY_RELEASE_CODE}"
    NAME_PREFIX "EASY_LIBRARY_VERSION"
)

add_library(easyLibrary::easyLibraryFlags ALIAS easyLibraryFlags)

target_compile_features(easyLibraryFlags INTERFACE cxx_std_20)

target_include_directories(
    easyLibraryFlags INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(easyLibraryFlags PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(easyLibraryFlags PROPERTIES VERSION ${EASY_LIBRARY_VERSION})



if(EASY_LIBRARY_BUILD_MATH)

    add_library(
        easyMath
        INTERFACE
    )

    add_library(
        easyLibrary::easyMath
        ALIAS
        easyMath
    )
    

    target_include_directories(
        easyMath INTERFACE 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
    set_target_properties(easyMath PROPERTIES LINKER_LANGUAGE CXX)
    set_target_properties(easyMath PROPERTIES VERSION ${EASY_LIBRARY_VERSION})

    target_link_libraries(
        easyMath INTERFACE
        easyLibraryFlags
    )

endif(EASY_LIBRARY_BUILD_MATH)

if(EASY_LIBRARY_BUILD_PARSE)

    add_library(
        easyParse
        src/easyParseLib/argParser.cpp
        src/easyParseLib/easyParse.cpp
    )

    add_library(
        easyLibrary::easyParse
        ALIAS
        easyParse
    )

    target_include_directories(
        easyParse PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
    set_target_properties(easyParse PROPERTIES LINKER_LANGUAGE CXX)
    set_target_properties(easyParse PROPERTIES VERSION ${EASY_LIBRARY_VERSION})

    target_link_libraries(
        easyParse PUBLIC
        easyMath easyLibraryFlags
    )

endif(EASY_LIBRARY_BUILD_PARSE)

if(EASY_LIBRARY_BUILD_EXAMPLE)
    add_subdirectory(example)    
endif(EASY_LIBRARY_BUILD_EXAMPLE)

if(EASY_LIBRARY_BUILD_TEST)
    add_subdirectory(test)    
endif(EASY_LIBRARY_BUILD_TEST)

if(EASY_LIBRARY_PREPARE_RELEASE)
    configure_file(res/compressRelease.py.in compressRelease.py)
endif(EASY_LIBRARY_PREPARE_RELEASE)



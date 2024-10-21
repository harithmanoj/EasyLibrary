# Part of Project EasyLibrary
# Copyright (C) Harith Manoj
# Licensed under Apache License, Version 2.0
# Date: 14 August 2024

include(../cmake/testBuild.cmake)

message(STATUS "CMAKE Now at EasyLibrary Tests Configuration")

if(EASY_LIBRARY_TEST_PIPE_OUT)
    message(STATUS "    Test piped output to file")
else()
    message(STATUS "    Test no piped output")
endif(EASY_LIBRARY_TEST_PIPE_OUT)

if(EASY_LIBRARY_BUILD_MATH)

    message(STATUS "    Configuring for EasyMath tests")

    function(unitTestEasyMath targetName sourceList createPipe)
        if(createPipe AND EASY_LIBRARY_TEST_PIPE_OUT)
            set(TEST_BUILDER_CREATE_PIPE ON)
        else()
            set(TEST_BUILDER_CREATE_PIPE OFF)
        endif(createPipe AND EASY_LIBRARY_TEST_PIPE_OUT)
        unitTestTemplate("easyMath" ${targetName} ${sourceList} easyMath TEST_BUILDER_CREATE_PIPE)
    endfunction(unitTestEasyMath)

    unitTestEasyMath(valueBetween valueBetween.cpp ON)

endif(EASY_LIBRARY_BUILD_MATH)

pipeTestOutScript()


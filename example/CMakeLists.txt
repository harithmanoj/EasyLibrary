# Part of Project EasyLibrary
# Copyright (C) Harith Manoj
# Licensed under Apache License, Version 2.0
# Date: 14 August 2024

include(../cmake/exampleBuild.cmake)

message(STATUS "CMAKE Now at EasyLibrary Examples Configuration")

if(EASY_LIBRARY_EXAMPLE_PIPE_OUT)
    message(STATUS "    Example piped output to file")
else()
    message(STATUS "    Example no piped output")
endif(EASY_LIBRARY_EXAMPLE_PIPE_OUT)

if(EASY_LIBRARY_BUILD_MATH)

    message(STATUS "    Configuring for EasyMath examples")

    function(exampleEasyMath targetName sourceList createPipe)
        if(createPipe AND EASY_LIBRARY_EXAMPLE_PIPE_OUT)
            set(EXAMPLE_BUILDER_CREATE_PIPE ON)
        else()
            set(EXAMPLE_BUILDER_CREATE_PIPE OFF)
        endif(createPipe AND EASY_LIBRARY_EXAMPLE_PIPE_OUT)

        exampleBuildTemplate("easyMath" ${targetName} ${sourceList} easyMath EXAMPLE_BUILDER_CREATE_PIPE)
    endfunction(exampleEasyMath)

    exampleEasyMath(valueBetween valueBetween.cpp ON)
    exampleEasyMath(overflowUnderFlow overflowUnderFlow.cpp ON)
    exampleEasyMath(divideRoundUp isPowerOfTwo.cpp ON)
    exampleEasyMath(nBitMask isPowerOfTwo.cpp ON)
    exampleEasyMath(extractBits isPowerOfTwo.cpp ON)

endif(EASY_LIBRARY_BUILD_MATH)

if(EASY_LIBRARY_BUILD_PARSE)

    function(exampleEasyParse targetName sourceList createPipe)
        if(createPipe AND EASY_LIBRARY_EXAMPLE_PIPE_OUT)
            set(EXAMPLE_BUILDER_CREATE_PIPE ON)
        else()
            set(EXAMPLE_BUILDER_CREATE_PIPE OFF)
        endif(createPipe AND EASY_LIBRARY_EXAMPLE_PIPE_OUT)
        
        exampleBuildTemplate("easyParse" ${targetName} ${sourceList} easyParse EXAMPLE_BUILDER_CREATE_PIPE)

    endfunction(exampleEasyParse)

    exampleEasyParse(binaryString stringConv.cpp ON)
    exampleEasyParse(hexString stringConv.cpp ON)
    exampleEasyParse(octString stringConv.cpp ON)
    exampleEasyParse(decString stringConv.cpp ON)
    exampleEasyParse(numString stringConv.cpp ON)
    exampleEasyParse(argParser argParser.cpp ON)
    exampleEasyParse(advanceOverText advance.cpp ON)

endif(EASY_LIBRARY_BUILD_PARSE)

pipeExampleOutScript()


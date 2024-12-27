# Part of Project EasyLibrary
# Copyright (C) Harith Manoj
# Licensed under Apache License, Version 2.0
# Date: 14 August 2024

include(easyCMakeExampleBuilder)

message(STATUS "CMAKE Now at EasyLibrary Examples Configuration")

if(EASY_LIBRARY_EXAMPLE_PIPE_OUT)
    message(STATUS "    Example piped output to file")
    easyCMake_setupExampleConfig()
else()
    message(STATUS "    Example no piped output")
endif(EASY_LIBRARY_EXAMPLE_PIPE_OUT)

function(exampleGen targetName sourceList createPipe module dep)
    if(createPipe AND EASY_LIBRARY_EXAMPLE_PIPE_OUT)
        easyCMake_configureExample(
            TARGET ${targetName}
            MODULE ${module}
            SRC ${sourceList}
            DEP ${dep}
            CREATE_PIPE
        )
    else()
        easyCMake_configureExample(
            TARGET ${targetName}
            MODULE ${module}
            SRC ${sourceList}
            DEP ${dep}
        )
    endif(createPipe AND EASY_LIBRARY_EXAMPLE_PIPE_OUT)
endfunction(exampleGen targetName sourceList createPipe module dep)


if(EASY_LIBRARY_BUILD_MATH)

    message(STATUS "    Configuring for EasyMath examples")

    function(exampleEasyMath targetName sourceList createPipe)
        exampleGen(${targetName} ${sourceList} ${createPipe} "easyMath" "easyMath")
    endfunction(exampleEasyMath)

    exampleEasyMath(valueBetween valueBetween.cpp ON)
    exampleEasyMath(overflowUnderFlow overflowUnderFlow.cpp ON)
    exampleEasyMath(divideRoundUp isPowerOfTwo.cpp ON)
    exampleEasyMath(nBitMask isPowerOfTwo.cpp ON)
    exampleEasyMath(extractBits isPowerOfTwo.cpp ON)

endif(EASY_LIBRARY_BUILD_MATH)

if(EASY_LIBRARY_BUILD_PARSE)

    function(exampleEasyParse targetName sourceList createPipe)
        exampleGen(${targetName} ${sourceList} ${createPipe} "easyParse" "easyParse")
    endfunction(exampleEasyParse)

    exampleEasyParse(binaryString stringConv.cpp ON)
    exampleEasyParse(hexString stringConv.cpp ON)
    exampleEasyParse(octString stringConv.cpp ON)
    exampleEasyParse(decString stringConv.cpp ON)
    exampleEasyParse(numString stringConv.cpp ON)
    exampleEasyParse(argParser argParser.cpp ON)
    exampleEasyParse(advanceOverText advance.cpp ON)

endif(EASY_LIBRARY_BUILD_PARSE)

if(EASY_LIBRARY_EXAMPLE_PIPE_OUT)
    easyCMake_generatePipeOutScript(easyLibraryFlags)
endif(EASY_LIBRARY_EXAMPLE_PIPE_OUT)



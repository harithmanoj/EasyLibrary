# EasyParse library

Collection of miscellaneous string parsing code and command line argument parser.

## Features

- Convert Hexadecimal, decimal digit characters to integer.
- Convert Hexadecimal, decimal, octal, binary string to integer.
- Validate digit characters, string for different bases.

- Strip whitespace, comment (based on delimiter character).

- Advance over escape sequences, advance and ignore quoted text.
- Check presence of sub-string, convert string to lowercase etc.

## Requirements

- easyMath library, see requirements in documentation of easyMath library.

- CMakeLists.txt            (for easy build).
- include/easyParseLib/easyParse.h
- include/easyParseLib/ArgParser.h
- src/easyParseLib/argParser.cpp
- src/easyParseLib/easyParse.cpp

For Examples if `EASY_LIBRARY_BUILD_EXAMPLE` set,
- cmake/exampleBuild.cmake
- example/CMakeLists.txt
- example/stringConv.cpp
- example/argParser.cpp
- example/advance.cpp

<b>Requires C++ 20</b>

<hr/>
<p style="text-align: center;">
Copyright &copy; Harith Manoj <br>
Licensed under Apache License, version 2.0 <br></p>

See [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0) for copy of license or attached LICENSE text file.

<hr/>
# EasyMath library

Collection of miscellaneous mathematical code.

## Features

- All `constexpr` methods.
- Concepts for numeric, integral, signed, unsigned etc types.
- Select most appropriate integral type based on bit-size or maximum representable value.
- Generate n-bit masks and extract n-bits from integer.
- Check if add or subtract will overflow / underflow.1
- Check of value is in an edge inclusive / exclusive range.

## Requirements

- CMakeLists.txt                    (if adding as subdirectory or building examples).
- include/easyMathLib/easyMath.h

For Examples if `EASY_LIBRARY_BUILD_EXAMPLE` set,
- cmake/exampleBuild.cmake
- example/CMakeLists.txt            
- example/isPowerOfTwo.cpp
- example/overflowUnderflow.cpp
- example/valueBetween.cpp

<b>Requires C++ 20</b>

<hr/>
<p style="text-align: center;">
Copyright &copy; Harith Manoj <br>
Licensed under Apache License, version 2.0 <br></p>

See [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0) for copy of license or attached LICENSE text file.

<hr/>
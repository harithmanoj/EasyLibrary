# EasyLibrary

Contains miscellaneous C++ libraries, too small to organize into it's own repository.

Latest Version: 1.0.1.alpha

## Quick Setup

### EasyMath Minimal

- Contains EasyMath library.
- Code, documentation and license files only.
- <b>Requires C++ 20</b>
- Download easyMath.minimal archive of the appropriate release.
- Place `include` folder in your code directory with your build system configured to recognise it as include path.

### EasyLibrary Minimal

- Contains EasyMath library, EasyParse library.
- Code, documentation and license files only.
- <b>Requires C++ 20</b>
- Download easyLibrary.minimal archive of the appropriate release.
- Place `include` folder in your code directory with your build system configured to recognise it as include path.
- Compile `src/*` source files along with your application.

### EasyLibrary Build

- Contains EasyMath library, EasyParse library.
- Code, documentation, license and build files only.
- <b>Requires C++ 20</b>
- Download easyLibrary.minimal archive of the appropriate release.
- Place extract archive contents as subdirectory of your root Cmake directory.
- In root `CMakeLists.txt`, use `add_subdirectory` to add libraries to your project.

### EasyLibrary Complete

- Contains EasyMath library, EasyParse library.
- Code, documentation, license, build files, example files and test files only.
- <b>Requires C++ 20</b>
- Download easyLibrary.minimal archive of the appropriate release.
- Place extract archive contents as subdirectory of your root Cmake directory.
- In root `CMakeLists.txt`, use `add_subdirectory` to add libraries to your project.

## CMake Build Options

Configs for each library:
- `ALL_BUILD` - Builds Test and Examples
- `LIB_EXAMPLE` - Builds Examples.
- `LIB_TEST` - Builds Tests
- `LIB` - No builds, header only library present.


Configurable options:
- `EASY_LIBRARY_BUILD_TEST` - Builds Tests, sets to config `LIB_TEST` or `ALL_BUILD`.
- `EASY_LIBRARY_BUILD_EXAMPLE` - Builds Tests, sets to config `LIB_EXAMPLE` or `ALL_BUILD`.
- `EASY_LIBRARY_BUILD_MATH` - Creates library `easyMath`.
- `EASY_LIBRARY_BUILD_PARSE` - Creates library `easyParse`, overrides `EASY_LIBRARY_BUILD_MATH` to `ON`.
- `EASY_LIBRARY_EXAMPLE_PIPE_OUT` - Creates script file to run each example and write output to file (for each config in `${CMAKE_BINARY_DIR0/Pipe/$<CONFIG>_run_ex.bat}`).
- `EASY_LIBRARY_TEST_PIPE_OUT` - Creates script file to run each test and write output to file (for each config in `${CMAKE_BINARY_DIR0/Pipe/$<CONFIG>_run_test.bat}`).

## Libraries available

- `easyLibrary` : Header only library, version info only.
- `easyMath`: Header only library, miscellaneous mathematical code. Depends on `easyLibrary`.
- `easyParse`: miscellaneous string parsing code, command line argument parser. Depends on `easyMath`, `easyLibrary`.

<hr/>
<p style="text-align: center;">
Copyright &copy; Harith Manoj <br>
Licensed under Apache License, version 2.0 <br></p>

See [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0) for copy of license or attached LICENSE text file.

<hr/>
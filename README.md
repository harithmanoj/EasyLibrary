# EasyLibrary

Contains miscellaneous C++ libraries, too small to organize into it's own repository.

Latest Version: 1.0.1.alpha

Requires EasyCMakeScripts package for 2 cmake scripts for version definition and example builder, specific files can be manually included by setting `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT` option to location of the cmake scripts required.

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

Configurable options:

| Option                            | Description                           | Default Value | Remarks   |
| ---                               | ---                                   | ---           | ---       |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`  | Enable building of tests, examples    | `OFF`         |           |
| `EASY_LIBRARY_BUILD_MATH`         | Configure and build easyMath library  | `ON`          |           |
| `EASY_LIBRARY_BUILD_PARSE`        | Configure and build easyParse library | `ON`          | sets `EASY_LIBRARY_BUILD_MATH` to `ON` |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT` | Directory in which EasyCMakeScripts scripts are located for manual inclusion | `"OFF"` | |

Options available if `EASY_LIBRARY_DEVELOPMENT_BUILD` is `ON`.

| Option                            | Description                                               | Default Value |
| ---                               | ---                                                       | ---           |
| `EASY_LIBRARY_BUILD_TEST`         | Builds Tests                                              | `ON`          |
| `EASY_LIBRARY_BUILD_EXAMPLE`      | Build Examples                                            | `ON`          |
| `EASY_LIBRARY_EXAMPLE_PIPE_OUT`   | Generate script to run examples and write output to file  | `ON`          |
| `EASY_LIBRARY_TEST_PIPE_OUT`      | Generate script to run test and write output to file      | `ON`          |

## CMake Configuration Presets

### easyMath

Minimal config needed for easyMath library, sets:

| Option | Value |
| ---    | ---  |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`  | `OFF` |   
| `EASY_LIBRARY_BUILD_MATH`         | `ON` |
| `EASY_LIBRARY_BUILD_PARSE`        | `OFF` |

### library

Minimal config needed for easyMath and easyParse library, sets:

| Option | Value |
| ---    | ---  |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`  | `OFF` |   
| `EASY_LIBRARY_BUILD_MATH`         | `ON` |
| `EASY_LIBRARY_BUILD_PARSE`        | `ON` |

### local-easyMath

Minimal config needed for easyMath library but with local EasyCMakeScripts provided files, sets:

| Option | Value |
| ---    | ---  |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`  | `OFF` |   
| `EASY_LIBRARY_BUILD_MATH`         | `ON` |
| `EASY_LIBRARY_BUILD_PARSE`        | `OFF` |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT`        | `"cmake"` |

### manual-library

Minimal config needed for easyMath and easyParse library but with local EasyCMakeScripts provided files, sets:

| Option | Value |
| ---    | ---  |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`  | `OFF` |   
| `EASY_LIBRARY_BUILD_MATH`         | `ON` |
| `EASY_LIBRARY_BUILD_PARSE`        | `ON` |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT`        | `"cmake"` |

### development

Development Build, sets:

| Option    | Value |
| ---       | ---   |
| `EASY_LIBRARY_DEVELOPMENT_BUILD` | `ON` |
| `EASY_LIBRARY_BUILD_MATH` | `ON` |
| `EASY_LIBRARY_BUILD_PARSE` | `ON` |
| `EASY_LIBRARY_BUILD_TEST` | `ON` |
| `EASY_LIBRARY_BUILD_EXAMPLE` | `ON` |
| `EASY_LIBRARY_TEST_PIPE_OUT` | `ON` |
| `EASY_LIBRARY_EXAMPLE_PIPE_OUT` | `ON` |
### local-development

Development Build, but with local EasyCMakeScripts provided files, sets:

| Option    | Value |
| ---       | ---   |
| `EASY_LIBRARY_DEVELOPMENT_BUILD` | `ON` |
| `EASY_LIBRARY_BUILD_MATH` | `ON` |
| `EASY_LIBRARY_BUILD_PARSE` | `ON` |
| `EASY_LIBRARY_BUILD_TEST` | `ON` |
| `EASY_LIBRARY_BUILD_EXAMPLE` | `ON` |
| `EASY_LIBRARY_TEST_PIPE_OUT` | `ON` |
| `EASY_LIBRARY_EXAMPLE_PIPE_OUT` | `ON` |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT`        | `"cmake"` |

## Libraries available

- `easyLibraryFlags` : Header only library, version info only, include under `easyLib`.
- `easyMath`: Header only library, miscellaneous mathematical code. Depends on `easyLibrary`. Include under `easyMathLib`.
- `easyParse`: miscellaneous string parsing code, command line argument parser. Depends on `easyMath`, `easyLibrary`. Include under `easyParseLib`.

<hr/>
<p style="text-align: center;">
Copyright &copy; Harith Manoj <br>
Licensed under Apache License, version 2.0 <br></p>

See [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0) for copy of license or attached LICENSE text file.

<hr/>
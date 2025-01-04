# EasyLibrary

Contains miscellaneous C++ libraries, too small to organize into it's own repository.

Latest Version: 1.0.1.alpha

Requires C++ 20

## Dependencies

### EasyCMakeScripts

- Needed for examples and builds that need to generate version header (instead of downloading release file).
- EasyCMakeScripts (minimum v1.0.4.release) [github](https://github.com/harithmanoj/EasyCMakeScripts) under Apache License v2
- Download only specific files needed and provide location to cmake through relevant options see [CMake build options](#cmake-build-options).
    - `easyCMakeVersion.cmake` for version header generation, not needed if generated header is acquired.
    - `easyCMakeExampleBuilder.cmake` for example target generator, not needed if examples are not build.
- If using installed EasyCMakeScripts package, use presets `easyMath`, `library` or `development`.
- If configured version header is provided, use presets `gen-easyMath` or `gen-library`.
- If `easyCMakeVersion.cmake` is available, use presets `easyMath`, `library` but override `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT` to location of script.
- If both scripts available,
    - Use presets `easyMath`, `library` but override `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT` to location of script.
    - Use preset `local-development` and place scripts in `cmake/` folder.
- If configured version header and `easyCMakeExampleBuilder.cmake` is available,
    - Use presets `gen-easyMath`, `gen-library`.
    - Use preset `local-development` and place script in `cmake/` folder, override `EASY_LIBRARY_HAS_CONFIGURED_VERSION_HEADER` to `ON`.


## Quick Setup

### Minimal (EasyMath)

- Download and extract `easyLibrary.minimal.easyMath` release.
- Files:
    - License
    - Readme
    - EasyMath headers
    - Configured version header
- Setup include path to find easyMath headers and configured version header (`C++20`).

### Minimal (EasyParse and EasyMath)

- Download and extract `easyLibrary.minimal` release.
- Files:
    - License
    - Readme
    - EasyMath headers
    - EasyParse headers
    - EasyParse source
    - Configured version header
- Setup include path to find easyMath, easyParse and version headers.
- Setup easyParse sources to be compiled with minimum `C++20`.

### Buildable (EasyParse and EasyMath)

- Download and extract `easyLibrary.build` release.
- Files:
    - License
    - Readme
    - EasyMath headers
    - EasyParse headers
    - EasyParse source
    - Configured version header
    - CMake files
- Use preset `gen-easyMath` to install easyMath library.
- Use preset `gen-library` to install easyParse and easyMath library.

### Development (EasyParse, EasyMath, examples)

- Download whole source or use git clone.
- Download cmake scripts from `EasyCMakeScripts` if not installed. Cmake scripts must be in `cmake/` folder.
- Files:
    - License
    - Readme
    - EasyMath headers
    - EasyParse headers
    - EasyParse source
    - CMake files
    - example files
- Use preset `easyMath` to install easyMath library (`gen-easyMath` if using downloaded version header).
- Use preset `library` to install easyMath and easyParse library (`gen-library` if using downloaded version header).
- Use preset `development` to install easyMath and easyParse library, and build all examples (`local-development` if using downloaded EasyCMakeScripts).


## CMake Build Options

Configurable options:

| Option                            | Description                           | Default Value | Remarks   |
| ---                               | ---                                   | ---           | ---       |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`  | Enable building of tests, examples    | `OFF`         |           |
| `EASY_LIBRARY_BUILD_MATH`         | Configure and build easyMath library  | `ON`          |           |
| `EASY_LIBRARY_BUILD_PARSE`        | Configure and build easyParse library | `ON`          | sets `EASY_LIBRARY_BUILD_MATH` to `ON` |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT` | Directory in which EasyCMakeScripts scripts are located for manual inclusion, `OFF` to use installed package / files already in module path. | `"OFF"` | |
| `EASY_LIBRARY_PREPARE_RELEASE`    | Generate release packing python script | `OFF`        |           |
| `EASY_LIBRARY_HAS_CONFIGURED_VERSION_HEADER` | Use `include/easyLib` as location for version header, avoids dependency on `EasyCMakeScripts::easyCMakeVersion` | |

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
| `EASY_LIBRARY_DEVELOPMENT_BUILD`                  | `OFF` |   
| `EASY_LIBRARY_BUILD_MATH`                         | `ON`  |
| `EASY_LIBRARY_BUILD_PARSE`                        | `OFF` |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT`              | `OFF` |
| `EASY_LIBRARY_PREPARE_RELEASE`                    | `OFF` |
| `EASY_LIBRARY_HAS_CONFIGURED_VERSION_HEADER`      | `OFF` |

### library

Minimal config needed for easyMath and easyParse library, sets:

| Option | Value |
| ---    | ---  |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`                  | `OFF` |   
| `EASY_LIBRARY_BUILD_MATH`                         | `ON`  |
| `EASY_LIBRARY_BUILD_PARSE`                        | `ON`  |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT`              | `OFF` |
| `EASY_LIBRARY_PREPARE_RELEASE`                    | `OFF` |
| `EASY_LIBRARY_HAS_CONFIGURED_VERSION_HEADER`      | `OFF` |

### gen-easyMath

Minimal config needed for easyMath library but with pre generated version header, sets:

| Option | Value |
| ---    | ---  |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`                  | `OFF` |   
| `EASY_LIBRARY_BUILD_MATH`                         | `ON`  |
| `EASY_LIBRARY_BUILD_PARSE`                        | `OFF` |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT`              | `OFF` |
| `EASY_LIBRARY_PREPARE_RELEASE`                    | `OFF` |
| `EASY_LIBRARY_HAS_CONFIGURED_VERSION_HEADER`      | `ON`  |

### manual-library

Minimal config needed for easyMath and easyParse library but with pre generated version header, sets:

| Option | Value |
| ---    | ---  |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`                  | `OFF` |   
| `EASY_LIBRARY_BUILD_MATH`                         | `ON`  |
| `EASY_LIBRARY_BUILD_PARSE`                        | `ON`  |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT`              | `OFF` |
| `EASY_LIBRARY_PREPARE_RELEASE`                    | `OFF` |
| `EASY_LIBRARY_HAS_CONFIGURED_VERSION_HEADER`      | `ON`  |

### development

Development Build, sets:

| Option    | Value |
| ---       | ---   |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`                  | `ON`  |
| `EASY_LIBRARY_BUILD_MATH`                         | `ON`  |
| `EASY_LIBRARY_BUILD_PARSE`                        | `ON`  |
| `EASY_LIBRARY_BUILD_TEST`                         | `ON`  |
| `EASY_LIBRARY_BUILD_EXAMPLE`                      | `ON`  |
| `EASY_LIBRARY_TEST_PIPE_OUT`                      | `ON`  |
| `EASY_LIBRARY_EXAMPLE_PIPE_OUT`                   | `ON`  |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT`              | `OFF` |
| `EASY_LIBRARY_PREPARE_RELEASE`                    | `OFF` |
| `EASY_LIBRARY_HAS_CONFIGURED_VERSION_HEADER`      | `OFF` |

### local-development

Development Build but with pre generated version header, sets:

| Option    | Value |
| ---       | ---   |
| `EASY_LIBRARY_DEVELOPMENT_BUILD`                  | `ON`  |
| `EASY_LIBRARY_BUILD_MATH`                         | `ON`  |
| `EASY_LIBRARY_BUILD_PARSE`                        | `ON`  |
| `EASY_LIBRARY_BUILD_TEST`                         | `ON`  |
| `EASY_LIBRARY_BUILD_EXAMPLE`                      | `ON`  |
| `EASY_LIBRARY_TEST_PIPE_OUT`                      | `ON`  |
| `EASY_LIBRARY_EXAMPLE_PIPE_OUT`                   | `ON`  |
| `EASY_LIBRARY_USE_LOCAL_EASY_SCRIPT`              | `cmake`|
| `EASY_LIBRARY_PREPARE_RELEASE`                    | `OFF` |
| `EASY_LIBRARY_HAS_CONFIGURED_VERSION_HEADER`      | `OFF` |

## Libraries available

- `easyLibraryFlags` : Header only library, version info only, include under `easyLib` (generated).
- `easyMath`: Header only library, miscellaneous mathematical code. Depends on `easyLibrary`. Include under `easyMathLib`.
- `easyParse`: miscellaneous string parsing code, command line argument parser. Depends on `easyMath`, `easyLibrary`. Include under `easyParseLib`.

<hr/>
<p style="text-align: center;">
Copyright &copy; Harith Manoj <br>
Licensed under Apache License, version 2.0 <br></p>

See [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0) for copy of license or attached LICENSE text file.

<hr/>
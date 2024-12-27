echo off
echo Package code into release packets

set /p version=<build\EasyLibrary.version

echo Package for version %version%
rmdir build\package /s /q
mkdir build\package

echo -------------------------------------------------

@rem EasyMath minimal package
echo Packaging EasyMath, code and readme
set easyMathMinimalDir=build\package\easyMath.minimal.%version%
echo %easyMathMinimalDir%

mkdir %easyMathMinimalDir%\include\easyMathLib
mkdir %easyMathMinimalDir%\include\easyLib

copy .\include\easyMathLib\* %easyMathMinimalDir%\include\easyMathLib\
copy .\include\easyLib\* %easyMathMinimalDir%\include\easyLib\
copy LICENSE %easyMathMinimalDir%
copy README.md %easyMathMinimalDir%
copy build\EasyLibrary.version %easyMathMinimalDir%

echo -------------------------------------------------

@rem EasyLibrary minimal package
echo Packaging EasyLibrary, code and readme
set easyLibraryMinimalDir=build\package\easyLibrary.minimal.%version%
echo %easyLibraryMinimalDir%

mkdir %easyLibraryMinimalDir%\include
mkdir %easyLibraryMinimalDir%\src

xcopy /e /k .\include\* %easyLibraryMinimalDir%\include
xcopy /e /k .\src\* %easyLibraryMinimalDir%\src
copy LICENSE %easyLibraryMinimalDir%
copy README.md %easyLibraryMinimalDir%
copy build\EasyLibrary.version %easyLibraryMinimalDir%

echo -------------------------------------------------

@rem EasyLibrary build package
echo Packaging EasyLibrary, code, readme and build files
set easyLibraryBuildDir=build\package\easyLibrary.build.%version%
echo %easyLibraryBuildDir%

mkdir %easyLibraryBuildDir%\include
mkdir %easyLibraryBuildDir%\src

xcopy /e /k .\include\* %easyLibraryBuildDir%\include
xcopy /e /k .\src\* %easyLibraryBuildDir%\src
copy LICENSE %easyLibraryBuildDir%
copy README.md %easyLibraryBuildDir%
copy CMakeLists.txt %easyLibraryBuildDir%
copy build\EasyLibrary.version %easyLibraryBuildDir%

echo -------------------------------------------------

@rem EasyLibrary complete package
echo Packaging EasyLibrary, code, readme, examples, tests and build files
set easyLibraryCompleteDir=build\package\easyLibrary.complete.%version%
echo %easyLibraryCompleteDir%

mkdir %easyLibraryCompleteDir%\include
mkdir %easyLibraryCompleteDir%\src
mkdir %easyLibraryCompleteDir%\test
mkdir %easyLibraryCompleteDir%\example

xcopy /e /k .\include\* %easyLibraryCompleteDir%\include
xcopy /e /k .\test\* %easyLibraryCompleteDir%\test
xcopy /e /k .\example\* %easyLibraryCompleteDir%\example
xcopy /e /k .\src\* %easyLibraryCompleteDir%\src
copy LICENSE %easyLibraryCompleteDir%
copy README.md %easyLibraryCompleteDir%
copy CMakeLists.txt %easyLibraryCompleteDir%
copy build\EasyLibrary.version %easyLibraryCompleteDir%

echo -------------------------------------------------
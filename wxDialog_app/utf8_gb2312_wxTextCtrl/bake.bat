	
@echo on

set WX_WIDGETS=wxWidgets-2.8.10
set WX_DEFINES=-IC:\works\%WX_WIDGETS%\build\bakefiles\wxpresets -DWX_DIR=C:\works\%WX_WIDGETS% -DWX_UNICODE=1

if "%1"=="" goto DEBUG
if not "%2"=="" goto ERROR

if "%1"=="release" goto RELEASE

:DEBUG
bakefile build.bkl -f msvc -o makefile.vc -DWX_DEBUG=1 -DWX_SHARED=1 -DBUILD=debug -DBUILDDIR=Debug %WX_DEFINES%
goto END

:RELEASE
bakefile build.bkl -f msvc -o makefile.vc -DWX_DEBUG=0 -DWX_SHARED=0 -DBUILD=release -DBUILDDIR=Release %WX_DEFINES%
goto END

:ERROR
echo Usage: bake [debug / release]

:END
nmake /f makefile.vc

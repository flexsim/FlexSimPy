@echo off

set "VSCMD_START_DIR=%CD%"
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\VsDevCmd.bat"

msbuild FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_10 /t:Rebuild
msbuild FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_9 /t:Rebuild
msbuild FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_8 /t:Rebuild
msbuild FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_7 /t:Rebuild

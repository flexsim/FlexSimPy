@echo off

set msbuildpath=%1
if "%msbuildpath%"=="" (
	set msbuildpath="C:\Program Files\Microsoft Visual Studio\2022\Professional\MSBuild\Current\Bin\MSBuild.exe"
)

%msbuildpath% FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_11 /t:Rebuild
%msbuildpath% FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_10 /t:Rebuild
%msbuildpath% FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_9 /t:Rebuild
%msbuildpath% PyConnector\PyConnectorInstaller.sln /p:Configuration=Release /t:Rebuild

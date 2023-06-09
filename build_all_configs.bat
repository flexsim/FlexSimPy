@echo off

set msbuildpath=%1
if "%msbuildpath%"=="" (
	set msbuildpath="C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\MSBuild\Current\Bin\MSBuild.exe"
)

%msbuildpath% FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_11 /t:Rebuild
%msbuildpath% FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_10 /t:Rebuild
%msbuildpath% FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_9 /t:Rebuild
%msbuildpath% FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_8 /t:Rebuild
%msbuildpath% FlexSimPy.sln /p:Platform=x64;Configuration=Rel_3_7 /t:Rebuild
%msbuildpath% PyConnector\PyConnectorInstaller.sln /p:Configuration=Release /t:Rebuild

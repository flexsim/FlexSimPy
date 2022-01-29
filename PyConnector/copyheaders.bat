IF NOT EXIST ..\flexsimcontent\ (
	MKDIR ..\flexsimcontent
)

IF EXIST ..\..\..\program\system\include (
	COPY /Y ..\..\..\program\system\include\*.h ..\flexsimcontent\
	COPY /Y ..\..\..\program\system\include\*.cpp ..\flexsimcontent\
)

IF EXIST ..\..\..\program\system\lib\flexsim.lib  (
	COPY /Y ..\..\..\program\system\lib\flexsim.lib ..\flexsimcontent\
)
IF EXIST ..\..\..\program\system\lib\flexsim_x86.lib  (
	COPY /Y ..\..\..\program\system\lib\flexsim_x86.lib ..\flexsimcontent\
)
IF EXIST ..\..\..\program\system\include\flexsimcontent.lib  (
	COPY /Y ..\..\..\program\system\include\flexsimcontent.lib ..\flexsimcontent\
)
IF EXIST ..\..\..\program\system\include\flexsimcontent_x86.lib  (
	COPY /Y ..\..\..\program\system\include\flexsimcontent_x86.lib ..\flexsimcontent\
)
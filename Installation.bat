@echo off
mkdir 	%HOMEDRIVE%\"program files (x86)"\"File Manager"

cd ..
xcopy .\"file manager"  %HOMEDRIVE%\"program files (x86)"\"File Manager"  /E /H /C /I
cd .\"file manager"
pause 
start SHORTCUT_CREATOR.bat


 

rem set CLASSIFYFOLDERPATH=C:\Users\PA\Desktop\Nru_class\Updateclassification
set CLASSIFYFOLDERPATH=%~dp0
if not exist "%CLASSIFYFOLDERPATH%\log" mkdir %CLASSIFYFOLDERPATH%\log
if not exist "%CLASSIFYFOLDERPATH%\old_data" mkdir %CLASSIFYFOLDERPATH%\old_data
call %CLASSIFYFOLDERPATH%\UpdateClassificationInfo.exe -u=infodba -pf=%TC_ROOT%\security\01TC_13_01_infodba.pwf  -g=dba -output=%CLASSIFYFOLDERPATH%\log\logfile.txt -type=ALL -Userdatafile=%CLASSIFYFOLDERPATH%\LastExecuted_UserData.txt -projdata=%CLASSIFYFOLDERPATH%


del "C:\Users\Administrator\Desktop\vc140.pdb"
del "C:\Users\Administrator\Desktop\testApp.obj"
del "C:\Users\Administrator\Desktop\testApp.ilk"
del "C:\Users\Administrator\Desktop\testApp.exe"
del "C:\Users\Administrator\Desktop\testApp.pdb"
start C:\Siemens\TC_ROOT\sample\compile -DIPLIB=none C:\Users\Administrator\Desktop\testApp.cpp
timeout 7
start C:\Siemens\TC_ROOT\sample\linkitk -o testApp C:\Users\Administrator\Desktop\testApp.obj
timeout 5
del "C:\Siemens\TC_ROOT\bin\testApp"
copy "C:\Users\Administrator\Desktop\testApp.exe" "C:\Siemens\TC_ROOT\bin"
set TC_ROOT=C:\Siemens\TC_ROOT
set TC_DATA=C:\Siemens\tcdata
call %TC_DATA%\tc_profilevars.bat
start C:\Siemens\TC_ROOT\bin\testApp.exe -u=infodba -p=infodba -g=dba
set test=C:\Program Files\Java

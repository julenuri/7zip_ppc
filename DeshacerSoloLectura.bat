@echo off
echo Copiando archivos...
xcopy "G:\7zip_ppc\*" "C:\WINNT\Profiles\Administrator\Desktop\7zip_ppc" /E /I /Y
echo Copia completada.
echo Arreglando permisos...
cd /d "C:\WINNT\Profiles\Administrator\Desktop\7zip_ppc"
attrib -r *.* /s
attrib -r * /s /d
echo Proceso finalizado.
pause
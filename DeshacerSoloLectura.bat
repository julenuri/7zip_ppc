@echo off
echo Borrando carpeta de PPCRel
rmdir "C:\WINNT\Profiles\Administrator\Desktop\7zip_ppc\CPP\7zip\Bundles\Alone\PPCRel" /s
echo Copiando archivos...
xcopy "G:\7zip_ppc\*" "C:\WINNT\Profiles\Administrator\Desktop\7zip_ppc" /E /I
echo Copia completada.
echo Arreglando permisos...
cd /d "C:\WINNT\Profiles\Administrator\Desktop\7zip_ppc"
attrib -r *.* /s
attrib -r * /s
echo Proceso finalizado.
pause
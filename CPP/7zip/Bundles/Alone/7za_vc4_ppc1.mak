# Microsoft Developer Studio Generated NMAKE File, Format Version 41001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (PPC) External Target" 0x0706

!IF "$(CFG)" == ""
CFG=7za_vc4_ppc1 - Win32 (PPC) Debug
!MESSAGE No configuration specified.  Defaulting to 7za_vc4_ppc1 - Win32 (PPC)\
 Debug.
!ENDIF 

!IF "$(CFG)" != "7za_vc4_ppc1 - Win32 (PPC) Release" && "$(CFG)" !=\
 "7za_vc4_ppc1 - Win32 (PPC) Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "7za_vc4_ppc1.mak" CFG="7za_vc4_ppc1 - Win32 (PPC) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "7za_vc4_ppc1 - Win32 (PPC) Release" (based on\
 "Win32 (PPC) External Target")
!MESSAGE "7za_vc4_ppc1 - Win32 (PPC) Debug" (based on\
 "Win32 (PPC) External Target")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project

!IF  "$(CFG)" == "7za_vc4_ppc1 - Win32 (PPC) Release"

# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "PPCRel"
# PROP BASE Intermediate_Dir "PPCRel"
# PROP BASE Target_Dir ""
# PROP BASE Cmd_Line "NMAKE /f 7za_vc4_ppc.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "7za_vc4_ppc.exe"
# PROP BASE Bsc_Name "7za_vc4_ppc.bsc"
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "PPCRel"
# PROP Intermediate_Dir "PPCRel"
# PROP Target_Dir ""
# PROP Cmd_Line "NMAKE /f 7za_vc4_ppc.mak"
# PROP Rebuild_Opt "/a"
# PROP Target_File "7za_vc4_ppc1.exe"
# PROP Bsc_Name "7za_vc4_ppc1.bsc"
OUTDIR=.\PPCRel
INTDIR=.\PPCRel

ALL : 

CLEAN : 
	-@erase 

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

!ELSEIF  "$(CFG)" == "7za_vc4_ppc1 - Win32 (PPC) Debug"

# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "PPCDbg"
# PROP BASE Intermediate_Dir "PPCDbg"
# PROP BASE Target_Dir ""
# PROP BASE Cmd_Line "NMAKE /f 7za_vc4_ppc.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "7za_vc4_ppc.exe"
# PROP BASE Bsc_Name "7za_vc4_ppc.bsc"
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "PPCDbg"
# PROP Intermediate_Dir "PPCDbg"
# PROP Target_Dir ""
# PROP Cmd_Line "NMAKE /f 7za_vc4_ppc.mak"
# PROP Rebuild_Opt "/a"
# PROP Target_File "7za_vc4_ppc1.exe"
# PROP Bsc_Name "7za_vc4_ppc1.bsc"
OUTDIR=.\PPCDbg
INTDIR=.\PPCDbg

ALL : 

CLEAN : 
	-@erase 

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

!ENDIF 

################################################################################
# Begin Target

# Name "7za_vc4_ppc1 - Win32 (PPC) Release"
# Name "7za_vc4_ppc1 - Win32 (PPC) Debug"

!IF  "$(CFG)" == "7za_vc4_ppc1 - Win32 (PPC) Release"

".\7za_vc4_ppc1.exe" : 
   CD C:\WINNT\Profiles\Administrator\Desktop\7zip_ppc\CPP\7zip\Bundles\Alone
   NMAKE /f 7za_vc4_ppc.mak

!ELSEIF  "$(CFG)" == "7za_vc4_ppc1 - Win32 (PPC) Debug"

".\7za_vc4_ppc1.exe" : 
   CD C:\WINNT\Profiles\Administrator\Desktop\7zip_ppc\CPP\7zip\Bundles\Alone
   NMAKE /f 7za_vc4_ppc.mak

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\7za_vc4_ppc.mak

!IF  "$(CFG)" == "7za_vc4_ppc1 - Win32 (PPC) Release"

!ELSEIF  "$(CFG)" == "7za_vc4_ppc1 - Win32 (PPC) Debug"

!ENDIF 

# End Source File
# End Target
# End Project
################################################################################

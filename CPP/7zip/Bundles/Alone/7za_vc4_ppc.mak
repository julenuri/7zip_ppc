# 7za.mak - NMAKE makefile para VC++ 4.0 / Windows NT 4 PowerPC
#
# Uso desde la linea de comandos de VC++ 4.0 (MSVC NT cross-compiler):
#   nmake /f 7za_vc4_ppc.mak
#
# O desde el IDE: File -> Open -> selecciona este .mak
#
# PREREQUISITO: copiar este archivo a CPP\7zip\Bundles\Alone\
# y haber aplicado el parche Types_patched.h -> C\Types.h

# ---------------------------------------------------------------------------
# Directorio de salida de objetos y ejecutable
# ---------------------------------------------------------------------------
O = PPCRel

# ---------------------------------------------------------------------------
# Herramientas
# ---------------------------------------------------------------------------
CPP  = cl.exe
LINK = link.exe
RC   = rc.exe

# ---------------------------------------------------------------------------
# Flags de compilador para VC++ 4.0 PPC
#
#   /nologo     sin banner
#   /W3         nivel de warning 3
#   /GX         habilitar C++ exceptions (equivalente a /EHsc en VC4)
#   /O1         optimizar para tamano (mas seguro que /O2 en cross-compile)
#   /c          solo compilar, no enlazar
#   /Fo$O/      directorio de salida de .obj
#   /I          include path raiz del proyecto (CPP/)
#
# Defines:
#   WIN32, _CONSOLE, _MBCS    - estandar de consola Win32
#   NDEBUG                    - release
#   COMPRESS_MT               - soporte multihilo para compresores
#   COMPRESS_BZIP2_MT         - bzip2 MT
#   COMPRESS_MF_MT            - match finder MT
#   BREAK_HANDLER             - manejo de Ctrl+C
#   BENCH_MT                  - benchmark MT
#   _7ZIP_ST                  - desactiva rutas de codigo que usan
#                               MEM_LARGE_PAGES (inexistente en NT4)
#
# NOTA: WIN_LONG_PATH y _7ZIP_LARGE_PAGES se omiten deliberadamente:
#   - WIN_LONG_PATH usa GetLongPathName (no existe en NT4)
#   - _7ZIP_LARGE_PAGES usa MEM_LARGE_PAGES (Win2003+)
# ---------------------------------------------------------------------------
CFLAGS = /nologo /W3 /GX /O1 /c /Fo$O\ \
  /I "..\..\..\\" \
  /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" \
  /D "COMPRESS_MT" /D "COMPRESS_BZIP2_MT" /D "COMPRESS_MF_MT" \
  /D "BREAK_HANDLER" /D "BENCH_MT"

# Flags para ficheros C puros (sin PCH)
CFLAGS_C = $(CFLAGS)

# Flags para ficheros C++ con PCH
CFLAGS_PCH_CREATE = $(CFLAGS) /Yc"StdAfx.h" /Fp$O\a.pch
CFLAGS_PCH_USE    = $(CFLAGS) /Yu"StdAfx.h" /Fp$O\a.pch

# ---------------------------------------------------------------------------
# Flags de linker para VC++ 4.0 PPC
#
#   /nologo          sin banner
#   /subsystem:console
#   /machine:PPC    target PowerPC NT
#   /out:...         ejecutable de salida
#
# NOTA: /OPT:NOWIN98 y /OPT:ICF son flags de VC6, no existen en VC4.
# ---------------------------------------------------------------------------
LFLAGS = /nologo /subsystem:console /machine:PPC /out:$O\7za.exe

LIBS = kernel32.lib user32.lib gdi32.lib advapi32.lib \
       shell32.lib ole32.lib oleaut32.lib uuid.lib

# ---------------------------------------------------------------------------
# Listas de objetos (una por grupo de directorios fuente)
# ---------------------------------------------------------------------------

CONSOLE_OBJS = \
  $O\ConsoleClose.obj \
  $O\ExtractCallbackConsole.obj \
  $O\List.obj \
  $O\Main.obj \
  $O\MainAr.obj \
  $O\OpenCallbackConsole.obj \
  $O\PercentPrinter.obj \
  $O\UpdateCallbackConsole.obj \
  $O\UserInputUtils.obj

COMMON_OBJS = \
  $O\CommandLineParser.obj \
  $O\CRC.obj \
  $O\IntToString.obj \
  $O\ListFileUtils.obj \
  $O\MyString.obj \
  $O\MyVector.obj \
  $O\MyWindows.obj \
  $O\NewHandler.obj \
  $O\Random.obj \
  $O\StdInStream.obj \
  $O\StdOutStream.obj \
  $O\StringConvert.obj \
  $O\StringToInt.obj \
  $O\UTFConvert.obj \
  $O\Wildcard.obj

WIN_OBJS = \
  $O\DLL.obj \
  $O\Error.obj \
  $O\FileDir.obj \
  $O\FileFind.obj \
  $O\FileIO.obj \
  $O\FileName.obj \
  $O\MemoryLock.obj \
  $O\PropVariant.obj \
  $O\PropVariantConversions.obj \
  $O\Synchronization.obj \
  $O\System.obj \
  $O\Time.obj

7ZIP_COMMON_OBJS = \
  $O\CreateCoder.obj \
  $O\FilePathAutoRename.obj \
  $O\FileStreams.obj \
  $O\FilterCoder.obj \
  $O\InBuffer.obj \
  $O\InOutTempBuffer.obj \
  $O\LimitedStreams.obj \
  $O\LockedStream.obj \
  $O\MemBlocks.obj \
  $O\MethodId.obj \
  $O\MethodProps.obj \
  $O\OffsetStream.obj \
  $O\OutBuffer.obj \
  $O\OutMemStream.obj \
  $O\ProgressMt.obj \
  $O\ProgressUtils.obj \
  $O\StreamBinder.obj \
  $O\StreamObjects.obj \
  $O\StreamUtils.obj \
  $O\VirtThread.obj

UI_COMMON_OBJS = \
  $O\ArchiveCommandLine.obj \
  $O\ArchiveExtractCallback.obj \
  $O\ArchiveOpenCallback.obj \
  $O\DefaultName.obj \
  $O\EnumDirItems.obj \
  $O\Extract.obj \
  $O\ExtractingFilePath.obj \
  $O\LoadCodecs.obj \
  $O\OpenArchive.obj \
  $O\PropIDUtils.obj \
  $O\SetProperties.obj \
  $O\SortUtils.obj \
  $O\TempFiles.obj \
  $O\Update.obj \
  $O\UpdateAction.obj \
  $O\UpdateCallback.obj \
  $O\UpdatePair.obj \
  $O\UpdateProduce.obj \
  $O\WorkDir.obj

AR_OBJS = \
  $O\ZHandler.obj

AR_COMMON_OBJS = \
  $O\CoderMixer2.obj \
  $O\CoderMixer2MT.obj \
  $O\CrossThreadProgress.obj \
  $O\DummyOutStream.obj \
  $O\FindSignature.obj \
  $O\HandlerOut.obj \
  $O\InStreamWithCRC.obj \
  $O\ItemNameUtils.obj \
  $O\MultiStream.obj \
  $O\OutStreamWithCRC.obj \
  $O\ParseProperties.obj

7Z_OBJS = \
  $O\7zCompressionMode.obj \
  $O\7zDecode.obj \
  $O\7zEncode.obj \
  $O\7zExtract.obj \
  $O\7zFolderInStream.obj \
  $O\7zFolderOutStream.obj \
  $O\7zHandler.obj \
  $O\7zHandlerOut.obj \
  $O\7zHeader.obj \
  $O\7zIn.obj \
  $O\7zOut.obj \
  $O\7zProperties.obj \
  $O\7zSpecStream.obj \
  $O\7zUpdate.obj \
  $O\7zRegister.obj

BZ2_OBJS = \
  $O\BZip2Handler.obj \
  $O\BZip2HandlerOut.obj \
  $O\BZip2Update.obj \
  $O\bz2Register.obj

CAB_OBJS = \
  $O\CabBlockInStream.obj \
  $O\CabHandler.obj \
  $O\CabHeader.obj \
  $O\CabIn.obj \
  $O\CabRegister.obj

GZ_OBJS = \
  $O\GZipHandler.obj \
  $O\GZipHandlerOut.obj \
  $O\GZipHeader.obj \
  $O\GZipIn.obj \
  $O\GZipOut.obj \
  $O\GZipUpdate.obj \
  $O\GZipRegister.obj

LZM_OBJS = \
  $O\LzmaArcRegister.obj \
  $O\LzmaFiltersDecode.obj \
  $O\LzmaHandler.obj \
  $O\LzmaIn.obj

SPLIT_OBJS = \
  $O\SplitHandler.obj \
  $O\SplitRegister.obj

TAR_OBJS = \
  $O\TarHandler.obj \
  $O\TarHandlerOut.obj \
  $O\TarHeader.obj \
  $O\TarIn.obj \
  $O\TarOut.obj \
  $O\TarUpdate.obj \
  $O\TarRegister.obj

ZIP_OBJS = \
  $O\ZipAddCommon.obj \
  $O\ZipHandler.obj \
  $O\ZipHandlerOut.obj \
  $O\ZipHeader.obj \
  $O\ZipIn.obj \
  $O\ZipItem.obj \
  $O\ZipOut.obj \
  $O\ZipUpdate.obj \
  $O\ZipRegister.obj

COMPRESS_OBJS = \
  $O\Bcj2Coder.obj \
  $O\Bcj2Register.obj \
  $O\BcjCoder.obj \
  $O\BcjRegister.obj \
  $O\BitlDecoder.obj \
  $O\BranchCoder.obj \
  $O\BranchMisc.obj \
  $O\BranchRegister.obj \
  $O\ByteSwap.obj \
  $O\ByteSwapRegister.obj \
  $O\BZip2Crc.obj \
  $O\BZip2Decoder.obj \
  $O\BZip2Encoder.obj \
  $O\BZip2Register.obj \
  $O\CopyCoder.obj \
  $O\CopyRegister.obj \
  $O\Deflate64Register.obj \
  $O\DeflateDecoder.obj \
  $O\DeflateEncoder.obj \
  $O\DeflateRegister.obj \
  $O\ImplodeDecoder.obj \
  $O\ImplodeHuffmanDecoder.obj \
  $O\LzmaDecoder.obj \
  $O\LzmaEncoder.obj \
  $O\LzmaRegister.obj \
  $O\LzOutWindow.obj \
  $O\Lzx86Converter.obj \
  $O\LzxDecoder.obj \
  $O\PpmdDecoder.obj \
  $O\PpmdEncoder.obj \
  $O\PpmdRegister.obj \
  $O\QuantumDecoder.obj \
  $O\ShrinkDecoder.obj \
  $O\ZDecoder.obj

LZMA_BENCH_OBJS = \
  $O\LzmaBench.obj \
  $O\LzmaBenchCon.obj

CRYPTO_OBJS = \
  $O\7zAes.obj \
  $O\7zAesRegister.obj \
  $O\HmacSha1.obj \
  $O\MyAes.obj \
  $O\Pbkdf2HmacSha1.obj \
  $O\RandGen.obj \
  $O\Sha1.obj \
  $O\WzAes.obj \
  $O\ZipCrypto.obj \
  $O\ZipStrong.obj

# C_OBJS: ficheros C puros, compilados sin PCH.
# NOTA: Se usa 7zCrc.c en lugar de los .asm de x86
# (no hay ensamblador PPC disponible para la version optimizada).
C_OBJS = \
  $O\7zCrc.obj \
  $O\Aes.obj \
  $O\Alloc.obj \
  $O\Bcj2.obj \
  $O\Bra.obj \
  $O\Bra86.obj \
  $O\BraIA64.obj \
  $O\BwtSort.obj \
  $O\HuffEnc.obj \
  $O\LzFind.obj \
  $O\LzFindMt.obj \
  $O\LzmaDec.obj \
  $O\LzmaEnc.obj \
  $O\Sha256.obj \
  $O\Sort.obj \
  $O\Threads.obj

# ---------------------------------------------------------------------------
# Lista completa de objetos
# ---------------------------------------------------------------------------
OBJS = \
  $O\StdAfx.obj \
  $O\GuidDefs.obj \
  $(CONSOLE_OBJS) \
  $(COMMON_OBJS) \
  $(WIN_OBJS) \
  $(7ZIP_COMMON_OBJS) \
  $(UI_COMMON_OBJS) \
  $(AR_OBJS) \
  $(AR_COMMON_OBJS) \
  $(7Z_OBJS) \
  $(BZ2_OBJS) \
  $(CAB_OBJS) \
  $(GZ_OBJS) \
  $(LZM_OBJS) \
  $(SPLIT_OBJS) \
  $(TAR_OBJS) \
  $(ZIP_OBJS) \
  $(COMPRESS_OBJS) \
  $(LZMA_BENCH_OBJS) \
  $(CRYPTO_OBJS) \
  $(C_OBJS) \
  $O\resource.res

# ---------------------------------------------------------------------------
# Target principal
# ---------------------------------------------------------------------------
all: $O $O\7za.exe

$O:
	if not exist "$O" mkdir "$O"

$O\7za.exe: $(OBJS)
	$(LINK) $(LFLAGS) $(LIBS) @<<
$(OBJS)
<<

$O\GuidDefs.obj: GuidDefs.cpp
	$(CPP) $(CFLAGS_C) GuidDefs.cpp

clean:
	-del /Q $O\*.obj $O\*.res $O\*.pch $O\*.exe

# ---------------------------------------------------------------------------
# Recursos
# ---------------------------------------------------------------------------
$O\resource.res: resource.rc
	$(RC) /fo$@ resource.rc

# ---------------------------------------------------------------------------
# StdAfx (crea la PCH)
# ---------------------------------------------------------------------------
$O\StdAfx.obj: StdAfx.cpp
	$(CPP) $(CFLAGS_PCH_CREATE) StdAfx.cpp

# ---------------------------------------------------------------------------
# Reglas de compilacion C++ (con PCH)
# ---------------------------------------------------------------------------
$(CONSOLE_OBJS): ..\..\UI\Console\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\UI\Console\$(*B).cpp

$(COMMON_OBJS): ..\..\..\Common\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\..\Common\$(*B).cpp

$(WIN_OBJS): ..\..\..\Windows\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\..\Windows\$(*B).cpp

$(7ZIP_COMMON_OBJS): ..\..\Common\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Common\$(*B).cpp

$(UI_COMMON_OBJS): ..\..\UI\Common\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\UI\Common\$(*B).cpp

$(AR_OBJS): ..\..\Archive\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Archive\$(*B).cpp

$(AR_COMMON_OBJS): ..\..\Archive\Common\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Archive\Common\$(*B).cpp

$(7Z_OBJS): ..\..\Archive\7z\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Archive\7z\$(*B).cpp

$(BZ2_OBJS): ..\..\Archive\BZip2\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Archive\BZip2\$(*B).cpp

$(CAB_OBJS): ..\..\Archive\Cab\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Archive\Cab\$(*B).cpp

$(GZ_OBJS): ..\..\Archive\GZip\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Archive\GZip\$(*B).cpp

$(LZM_OBJS): ..\..\Archive\Lzma\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Archive\Lzma\$(*B).cpp

$(SPLIT_OBJS): ..\..\Archive\Split\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Archive\Split\$(*B).cpp

$(TAR_OBJS): ..\..\Archive\Tar\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Archive\Tar\$(*B).cpp

$(ZIP_OBJS): ..\..\Archive\Zip\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Archive\Zip\$(*B).cpp

$(COMPRESS_OBJS): ..\..\Compress\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Compress\$(*B).cpp

$(LZMA_BENCH_OBJS): ..\..\Compress\LZMA_Alone\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Compress\LZMA_Alone\$(*B).cpp

$(CRYPTO_OBJS): ..\..\Crypto\$(*B).cpp
	$(CPP) $(CFLAGS_PCH_USE) ..\..\Crypto\$(*B).cpp

# ---------------------------------------------------------------------------
# Reglas de compilacion C puro (SIN PCH, /Fo especificado explicitamente)
# ---------------------------------------------------------------------------
$(C_OBJS): ..\..\..\..\C\$(*B).c
	$(CPP) $(CFLAGS_C) ..\..\..\..\C\$(*B).c

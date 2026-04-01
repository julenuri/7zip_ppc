/* GuidDefs.c - Explicit GUID definitions for 7za NT4 PPC port */
/* All GUIDs use the 7-zip base: 23170F69-40C1-278A-0000-00GG00SS0000 */

#include <windows.h>

const GUID IID_IProgress = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 0, 0, 5, 0, 0 }
};

const GUID IID_ISequentialInStream = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 3, 0, 1, 0, 0 }
};

const GUID IID_ISequentialOutStream = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 3, 0, 2, 0, 0 }
};

const GUID IID_IInStream = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 3, 0, 3, 0, 0 }
};

const GUID IID_IOutStream = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 3, 0, 4, 0, 0 }
};

const GUID IID_IStreamGetSize = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 3, 0, 6, 0, 0 }
};

const GUID IID_IOutStreamFlush = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 3, 0, 7, 0, 0 }
};

const GUID IID_ICompressProgressInfo = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 4, 0, 0 }
};

const GUID IID_ICompressCoder = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 5, 0, 0 }
};

const GUID IID_ICompressCoder2 = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 24, 0, 0 }
};

const GUID IID_ICompressSetCoderProperties = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 32, 0, 0 }
};

const GUID IID_ICompressSetDecoderProperties2 = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 34, 0, 0 }
};

const GUID IID_ICompressWriteCoderProperties = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 35, 0, 0 }
};

const GUID IID_ICompressGetInStreamProcessedSize = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 36, 0, 0 }
};

const GUID IID_ICompressSetCoderMt = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 37, 0, 0 }
};

const GUID IID_ICompressGetSubStreamSize = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 48, 0, 0 }
};

const GUID IID_ICompressSetInStream = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 49, 0, 0 }
};

const GUID IID_ICompressSetOutStream = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 50, 0, 0 }
};

const GUID IID_ICompressSetInStreamSize = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 51, 0, 0 }
};

const GUID IID_ICompressSetOutStreamSize = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 52, 0, 0 }
};

const GUID IID_ICompressFilter = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 64, 0, 0 }
};

const GUID IID_ICompressCodecsInfo = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 96, 0, 0 }
};

const GUID IID_ISetCompressCodecsInfo = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 97, 0, 0 }
};

const GUID IID_ICryptoProperties = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 128, 0, 0 }
};

const GUID IID_ICryptoResetSalt = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 136, 0, 0 }
};

const GUID IID_ICryptoResetInitVector = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 140, 0, 0 }
};

const GUID IID_ICryptoSetPassword = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 144, 0, 0 }
};

const GUID IID_ICryptoSetCRC = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 4, 0, 160, 0, 0 }
};

const GUID IID_ICryptoGetTextPassword = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 5, 0, 16, 0, 0 }
};

const GUID IID_ICryptoGetTextPassword2 = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 5, 0, 17, 0, 0 }
};

const GUID IID_IArchiveOpenCallback = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 16, 0, 0 }
};

const GUID IID_IArchiveExtractCallback = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 32, 0, 0 }
};

const GUID IID_IArchiveOpenVolumeCallback = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 48, 0, 0 }
};

const GUID IID_IInArchiveGetStream = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 64, 0, 0 }
};

const GUID IID_IArchiveOpenSetSubArchiveName = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 80, 0, 0 }
};

const GUID IID_IInArchive = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 96, 0, 0 }
};

const GUID IID_IArchiveUpdateCallback = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 128, 0, 0 }
};

const GUID IID_IArchiveUpdateCallback2 = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 130, 0, 0 }
};

const GUID IID_IOutArchive = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 160, 0, 0 }
};

const GUID IID_ISetProperties = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 3, 0, 0 }
};

const GUID IID_IFolderArchiveExtractCallback = {
  0x23170F69, 0x40C1, 0x278A,
  { 0, 0, 0, 6, 0, 48, 0, 0 }
};

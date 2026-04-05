// GuidDefs.cpp
// Instantiates all COM interface GUIDs used in 7za standalone bundle.
//
// INITGUID must be defined before including any interface header.
// When INITGUID is defined, DEFINE_GUID() generates storage (const GUID name = {...})
// instead of just extern declarations.
//
// This file must be compiled WITHOUT precompiled headers (/Yu disabled).

#include "StdAfx.h"

// Define INITGUID before anything else - this makes DEFINE_GUID emit definitions
#ifdef INITGUID
#undef INITGUID
#endif
#define INITGUID

// Pull in initguid.h which redefines DEFINE_GUID to emit storage
#include <initguid.h>

// Now include all interface headers - each DECL_INTERFACE/DEFINE_GUID call
// will emit a proper const GUID definition.
#include "../../IStream.h"
#include "../../IProgress.h"
#include "../../ICoder.h"
#include "../../IPassword.h"
#include "../../Archive/IArchive.h"
#include "../Common/IFileExtractCallback.h"

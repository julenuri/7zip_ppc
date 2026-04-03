// Vc4Compat.h
// Compatibilidad con Visual C++ 4.0 (_MSC_VER == 1000).
//
// IMPORTANTE: incluir este fichero antes que cualquier otro header
// del proyecto (lo hace StdAfx.h mediante /Yc"StdAfx.h").

#ifndef __VC4COMPAT_H
#define __VC4COMPAT_H

#if defined(_MSC_VER) && (_MSC_VER < 1100)

// -----------------------------------------------------------------
// 1. bool / true / false
//    VC++ 4.0 no tiene bool nativo (llega con VC5 / C++98).
//    Lo definimos como int para maxima compatibilidad ABI.
// -----------------------------------------------------------------
typedef int bool;

#ifndef true
#define true  1
#endif
#ifndef false
#define false 0
#endif

// -----------------------------------------------------------------
// 2. UINT_PTR / UINT32 / UINT64 / ULONG_PTR / INT64 / SIZE_T
//    El SDK de NT4 no define UINT_PTR (se añadio en el SDK de XP).
//    En PPC NT4 los punteros son de 32 bits.
//    UINT32 tampoco lo define windows.h de NT4; lo usan FileFind.h
//    y FileDir.h del arbol de 7-zip.
// -----------------------------------------------------------------

#ifndef INT64
typedef __int64 INT64;
#endif

#ifndef SIZE_T
typedef unsigned int SIZE_T;
#endif

#ifndef UINT_PTR
typedef unsigned int UINT_PTR;
#endif

#ifndef UINT32
typedef unsigned int UINT32;
#endif

#ifndef UINT64
typedef unsigned __int64 UINT64;
#endif

#ifndef ULONG_PTR
typedef unsigned long ULONG_PTR;
#endif

// -----------------------------------------------------------------
// 3. PROPVARIANT
//    En builds _WIN32 PROPVARIANT viene de <propidl.h>, pero el
//    windows.h del SDK de NT4 no lo incluye automaticamente.
//    Lo incluimos explicitamente aqui.
// -----------------------------------------------------------------
#ifdef _WIN32
// En el SDK de NT4, PROPVARIANT viene incluido a traves de ole2.h.
// propidl.h no existe como fichero separado en este SDK.
#include <ole2.h>
#endif
 
// -----------------------------------------------------------------
// 3b. PROPID / VARTYPE - tipos usados en STATPROPSTG.
//     Deben estar disponibles antes de la definicion de STATPROPSTG.
//     ole2.h de NT4 puede no definirlos si no incluye propidl.h.
// -----------------------------------------------------------------
#ifndef PROPID
typedef unsigned long PROPID;
#endif
#ifndef VARTYPE
typedef unsigned short VARTYPE;
#endif

// -----------------------------------------------------------------
// 4. FILE_ATTRIBUTE_ENCRYPTED
//    Constante anadida en el SDK de Windows 2000.
//    La definimos con su valor canonico (0x4000) para que el codigo
//    compile; en NT4 ningun fichero tendra este atributo activo,
//    pero la logica que lo comprueba funcionara sin fallos.
// -----------------------------------------------------------------
#ifndef FILE_ATTRIBUTE_ENCRYPTED
#define FILE_ATTRIBUTE_ENCRYPTED    0x4000
#endif
#ifndef FILE_ATTRIBUTE_OFFLINE
#define FILE_ATTRIBUTE_OFFLINE      0x1000
#endif
#ifndef FILE_ATTRIBUTE_REPARSE_POINT
#define FILE_ATTRIBUTE_REPARSE_POINT 0x0400
#endif
#ifndef FILE_ATTRIBUTE_SPARSE_FILE
#define FILE_ATTRIBUTE_SPARSE_FILE  0x0200
#endif

// -----------------------------------------------------------------
// 5. STATPROPSTG: struct de OLE2/COM para describir propiedades.
// En el SDK de NT4 PPC puede no estar en ole2.h (se añadio formalmente
// en el SDK de IE4/NT4 SP3 con propidl.h). La definimos manualmente
// con guard para evitar redefinicion si ya existe.
#if defined(_WIN32) && !defined(_STATPROPSTG_DEFINED)
#ifndef STATPROPSTG
typedef struct tagSTATPROPSTG {
    LPWSTR lpwstrName;
    PROPID propid;
    VARTYPE vt;
} STATPROPSTG;
#define _STATPROPSTG_DEFINED
#endif
#endif

// -----------------------------------------------------------------
// 6. Si ole2.h del SDK de NT4 PPC no define PROPVARIANT (poco probable
// pero posible), lo definimos manualmente como en MyWindows.h.
#if defined(_WIN32) && !defined(_PROPVARIANT_DEFINED) && !defined(tagPROPVARIANT)
typedef unsigned short VARTYPE;
typedef struct tagPROPVARIANT
{
  VARTYPE vt;
  WORD    wReserved1;
  WORD    wReserved2;
  WORD    wReserved3;
  union {
    char            cVal;
    unsigned char   bVal;
    short           iVal;
    unsigned short  uiVal;
    long            lVal;
    unsigned long   ulVal;
    LARGE_INTEGER   hVal;
    ULARGE_INTEGER  uhVal;
    short           boolVal;
    long            scode;
    FILETIME        filetime;
    BSTR            bstrVal;
  };
} PROPVARIANT;
#define _PROPVARIANT_DEFINED
#endif

// ----------------------------------------------------------------
// 7. CP_UTF8 no está definido en MSVC++ 4.0/NT4.0.
//    Definimos la constante a la cuál se refiere.
//    Se introduce en el SDK de Windows 2000, por lo que la misma
//    no funcionaría en principio en Windows 98, no sé cómo haría
//    Igor P. para el workaround , o si se retrocompilaba.

#ifndef CP_UTF8
#define CP_UTF8 65001
#endif

// -----------------------------------------------------------------
// 8. MyStringCompareNoCase(char) - declaracion que falta en MyString.h
//    MyString.h solo declara la version wchar_t (la de char esta
//    comentada). La implementacion si existe en MyString.cpp.
//    Al declarar aqui el overload, CStringBase<char>::CompareNoCase
//    puede resolverlo correctamente sin modificar MyString.h.
// -----------------------------------------------------------------
#ifdef __cplusplus
int MyStringCompareNoCase(const char *s1, const char *s2);
#endif

// -----------------------------------------------------------------
// 9. ObjVecFindLinear: reemplazo de CObjectVector::FindInSorted
//    para VC4, donde ese metodo esta desactivado por el guard.
//    Hace busqueda lineal (suficiente para los vectores pequenos
//    de rutas de archivos donde se usa en List.cpp y Extract.cpp).
// -----------------------------------------------------------------
#if defined(__cplusplus) && defined(_MSC_VER) && (_MSC_VER < 1100)
template <class V, class T>
inline int ObjVecFindLinear(const V& vec, const T& item)
{
  for (int i = 0; i < vec.Size(); i++)
    if (vec[i] == item) return i;
  return -1;
}
#endif

// -----------------------------------------------------------------
// 10. Silenciar warnings de VC4 que son ruido en este port
// -----------------------------------------------------------------
// C4237: 'bool' keyword is reserved for future use
#pragma warning(disable: 4237)
// C4290: C++ Exception Specification ignored
#pragma warning(disable: 4290)
// C4514: unreferenced inline function removed
#pragma warning(disable: 4514)

#endif  // _MSC_VER < 1100

#endif  // __VC4COMPAT_H

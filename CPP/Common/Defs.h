// Common/Defs.h

#ifndef __COMMON_DEFS_H
#define __COMMON_DEFS_H

#ifndef IS_GUID_EQUAL
#define IS_GUID_EQUAL(g1, g2) \
    ((g1).Data1 == (g2).Data1 && \
     (g1).Data2 == (g2).Data2 && \
     (g1).Data3 == (g2).Data3 && \
     (g1).Data4[0] == (g2).Data4[0] && \
     (g1).Data4[1] == (g2).Data4[1] && \
     (g1).Data4[2] == (g2).Data4[2] && \
     (g1).Data4[3] == (g2).Data4[3] && \
     (g1).Data4[4] == (g2).Data4[4] && \
     (g1).Data4[5] == (g2).Data4[5] && \
     (g1).Data4[6] == (g2).Data4[6] && \
     (g1).Data4[7] == (g2).Data4[7])
#endif

#ifndef IS_IID_EQUAL
#define IS_IID_EQUAL IS_GUID_EQUAL
#endif

template <class T> inline T MyMin(T a, T b)
  {  return a < b ? a : b; }
template <class T> inline T MyMax(T a, T b)
  {  return a > b ? a : b; }

template <class T> inline int MyCompare(T a, T b)
  {  return a < b ? -1 : (a == b ? 0 : 1); }

inline int BoolToInt(bool value)
  { return (value ? 1: 0); }

inline bool IntToBool(int value)
  { return (value != 0); }

#endif

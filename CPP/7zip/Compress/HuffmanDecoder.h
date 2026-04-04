// Compress/HuffmanDecoder.h
// Patched for VC++ 4.0: member function templates inside a class template
// are not supported. DecodeSymbol<TBitDecoder> replaced with:
//   - VC4: takes IBitDecoder* (abstract interface + per-type adapters)
//   - VC5+: original template unchanged
//
// Call sites: decoder.DecodeSymbol(&stream) must become
//             decoder.DecodeSymbol(MAKE_BIT_ADAPTER(&stream))
// A macro MAKE_BIT_ADAPTER is provided below.

#ifndef __COMPRESS_HUFFMAN_DECODER_H
#define __COMPRESS_HUFFMAN_DECODER_H

#include "../../Common/Types.h"

namespace NCompress {
namespace NHuffman {

const int kNumTableBits = 9;

#if defined(_MSC_VER) && (_MSC_VER < 1100)
struct IBitDecoder
{
  virtual UInt32 GetValue(int numBits) = 0;
  virtual void   MovePos(int numBits)  = 0;
};
template <class T>
struct CBitDecoderAdapter : public IBitDecoder
{
  T *_p;
  CBitDecoderAdapter(T *p) : _p(p) {}
  UInt32 GetValue(int n) { return _p->GetValue(n); }
  void   MovePos(int n)  { _p->MovePos(n); }
};
#define MAKE_BIT_ADAPTER(p) (&NCompress::NHuffman::CBitDecoderAdapter<__typeof__(*p)>(p))
#else
#define MAKE_BIT_ADAPTER(p) (p)
#endif

template <int kNumBitsMax, UInt32 m_NumSymbols>
class CDecoder
{
  UInt32 m_Limits[kNumBitsMax + 1];
  UInt32 m_Positions[kNumBitsMax + 1];
  UInt32 m_Symbols[m_NumSymbols];
  Byte   m_Lengths[1 << kNumTableBits];

public:
  bool SetCodeLengths(const Byte *codeLengths)
  {
    int lenCounts[kNumBitsMax + 1];
    UInt32 tmpPositions[kNumBitsMax + 1];
    int i;
    for(i = 1; i <= kNumBitsMax; i++)
      lenCounts[i] = 0;
    UInt32 symbol;
    for (symbol = 0; symbol < m_NumSymbols; symbol++)
    {
      int len = codeLengths[symbol];
      if (len > kNumBitsMax) return false;
      lenCounts[len]++;
      m_Symbols[symbol] = 0xFFFFFFFF;
    }
    lenCounts[0] = 0;
    m_Positions[0] = m_Limits[0] = 0;
    UInt32 startPos = 0;
    UInt32 index = 0;
    const UInt32 kMaxValue = (1 << kNumBitsMax);
    for (i = 1; i <= kNumBitsMax; i++)
    {
      startPos += lenCounts[i] << (kNumBitsMax - i);
      if (startPos > kMaxValue) return false;
      m_Limits[i] = (i == kNumBitsMax) ? kMaxValue : startPos;
      m_Positions[i] = m_Positions[i - 1] + lenCounts[i - 1];
      tmpPositions[i] = m_Positions[i];
      if(i <= kNumTableBits)
      {
        UInt32 limit = (m_Limits[i] >> (kNumBitsMax - kNumTableBits));
        for (; index < limit; index++)
          m_Lengths[index] = (Byte)i;
      }
    }
    for (symbol = 0; symbol < m_NumSymbols; symbol++)
    {
      int len = codeLengths[symbol];
      if (len != 0)
        m_Symbols[tmpPositions[len]++] = symbol;
    }
    return true;
  }

#if defined(_MSC_VER) && (_MSC_VER < 1100)
  UInt32 DecodeSymbol(IBitDecoder *bitStream)
#else
  template <class TBitDecoder>
  UInt32 DecodeSymbol(TBitDecoder *bitStream)
#endif
  {
    int numBits;
    UInt32 value = bitStream->GetValue(kNumBitsMax);
    if (value < m_Limits[kNumTableBits])
      numBits = m_Lengths[value >> (kNumBitsMax - kNumTableBits)];
    else
      for (numBits = kNumTableBits + 1; value >= m_Limits[numBits]; numBits++);
    bitStream->MovePos(numBits);
    UInt32 index = m_Positions[numBits] +
      ((value - m_Limits[numBits - 1]) >> (kNumBitsMax - numBits));
    if (index >= m_NumSymbols)
      return 0xFFFFFFFF;
    return m_Symbols[index];
  }
};

}}

#endif

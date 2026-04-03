// HuffmanDecoder.h - Versión simplificada para VC++ 4.0

#ifndef __COMPRESS_HUFFMAN_DECODER_H
#define __COMPRESS_HUFFMAN_DECODER_H

// Versión muy simplificada sin templates
class CHuffmanDecoder
{
private:
    // Arrays fijos para el decoder
    UInt32 m_Limits[16];
    UInt32 m_Positions[16];
    UInt32 m_NumSymbols;
    
public:
    CHuffmanDecoder() { m_NumSymbols = 0; }
    
    void SetLimits(const UInt32 limits[], int num) 
    {
        for (int i = 0; i < num && i < 16; i++)
            m_Limits[i] = limits[i];
        m_NumSymbols = num;
    }
    
    void SetPositions(const UInt32 positions[], int num)
    {
        for (int i = 0; i < num && i < 16; i++)
            m_Positions[i] = positions[i];
    }
    
    // Método simplificado de decodificación
    UInt32 DecodeSymbol(class CBitStream *bitStream);
};

#endif

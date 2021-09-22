typedef unsigned int Word; // => we can use the work

Word reverseBits(Word w);

Word reverseBits(Word w) {
    Word result = 0;
    for (Word bit = 0; bit < 32; ++bit) {
        Word wordMask = 1u << (31 - bit); // 'u' used to indicate that 1 is unsigned.
        Word resultMask = 1u << bit;
        
        if (w & wordMask) { // set the bit in result IF the bit is set in the original (w).
            result = result | wordMask;
        }
    }
    return result;
}
#include "randomTable.h"

#include <stddef.h>
#include <stdint.h>

//Doom psudorandom number table, with the duplicates replaced.
__UINT8_TYPE__ rndtable[256] = {
    0,   8,   109, 220, 222, 241, 149, 107,  75, 248, 254, 140,  16,  66 ,
    74,  21,  211, 47,  80,  242, 154,  27, 205, 117, 157,  89,  208,  36 ,
    95,  110, 85,  48,  212, 29, 32, 179,  22,  79, 200,  119,  28, 188 ,
    234, 23,  202, 55,  68,  145,  62,  131, 184, 190,  91, 127, 152, 217 ,
    12,  104, 25,  178, 252, 182, 83, 177, 141, 169,   4,  81, 181, 35 ,
    199, 42,  39,  227, 155, 124, 225, 193, 219,  93, 122, 88, 249,   1 ,
    210, 143, 70,  174, 46,  246, 65,  53, 163, 5, 168, 135,   2, 235 ,
    67,  92,  20,  207, 138, 233,  69, 166,  78, 176, 173, 160, 148, 113 ,
    94,  161, 41,  50,  239, 49, 111, 164,  134,  60,   189,  37, 171,  13 ,
    214, 156, 11,  56,  204, 215, 44, 229,  73, 146,  77,  61,  218, 64 ,
    209, 106, 63,  105, 195, 86,  96, 203, 121, 101, 170, 247, 137, 213 ,
    34,  250, 108, 7,   255, 237, 129, 40,  144, 18, 112, 142, 103, 10 ,
    24,  223, 51,  120, 198, 58,  172,  82, 128,   3, 132,  30, 150, 115 ,
    72,  224, 97,  206, 133, 45,  240,  90, 151, 114,  59,  33, 159,  228 ,
    191, 139, 153, 98,  125, 196,  15,  245, 194, 253,  54,  14, 6, 226 ,
    71,  17,  180, 147, 186, 87, 244, 130,  230,  102, 123, 251,  26,  162 ,
    192, 201, 52,  231, 232, 76,  31, 221,  84,  167, 216, 165, 158, 116 ,
    197, 38,  183, 43,  185, 175, 19, 238, 100,  243, 118, 9, 187, 136 ,
    57,  99,  236, 126
};

__UINT8_TYPE__ indices[256];

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void randomTable_indicesFromTable()
{
    for (size_t i = 0; i < sizeof(rndtable) && i < sizeof(indices); i++)
    {
        indices[i] = rndtable[i];
    }
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT8_TYPE__ getIndexRandomUInt8(__UINT8_TYPE__ index)
{
    return rndtable[indices[index]++];
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT8_TYPE__ getRandomUInt8()
{
    return getIndexRandomUInt8(0);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT16_TYPE__ getRandomUInt16()
{    
    __UINT8_TYPE__ index = getIndexRandomUInt8(getRandomUInt8());

    return getIndexRandomUInt8(index)
    + (rndtable[index] << 8);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT32_TYPE__ getRandomUInt32()
{
    __UINT8_TYPE__ firstIndex = getIndexRandomUInt8(getRandomUInt8());
    __UINT8_TYPE__ secondIndex = getIndexRandomUInt8(getRandomUInt8());

    return getIndexRandomUInt8(secondIndex)
    + (rndtable[secondIndex] << 8)
    + (getIndexRandomUInt8(firstIndex) << 16)
    + (rndtable[firstIndex] << 24);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT64_TYPE__ getRandomUInt64()
{
    __UINT8_TYPE__ firstIndex = getIndexRandomUInt8(getRandomUInt8());
    __UINT8_TYPE__ secondIndex = getIndexRandomUInt8(getRandomUInt8());
    __UINT8_TYPE__ thirdIndex = getIndexRandomUInt8(getRandomUInt8());
    __UINT8_TYPE__ forthIndex = getIndexRandomUInt8(getRandomUInt8());

    return (__UINT64_TYPE__)getIndexRandomUInt8(forthIndex)
    + ((__UINT64_TYPE__)rndtable[forthIndex] << 8)
    + ((__UINT64_TYPE__)getIndexRandomUInt8(thirdIndex) << 16)
    + ((__UINT64_TYPE__)rndtable[thirdIndex] << 24)
    + ((__UINT64_TYPE__)getIndexRandomUInt8(secondIndex) << 32)
    + ((__UINT64_TYPE__)rndtable[secondIndex] << 40)
    + ((__UINT64_TYPE__)getIndexRandomUInt8(firstIndex) << 48)
    + ((__UINT64_TYPE__)rndtable[firstIndex] << 56);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT8_TYPE__ getSeedyIndexRandomUInt8(__UINT8_TYPE__ index, __UINT8_TYPE__ seed)
{
    return rndtable[indices[index]++ + seed] ^ seed;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT8_TYPE__ getSeedyRandomUInt8(__UINT8_TYPE__ seed)
{
    return getSeedyIndexRandomUInt8(0, seed);
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT16_TYPE__ getSeedyRandomUInt16(__UINT16_TYPE__ seed)
{
    __UINT8_TYPE__ ucSeed = (__UINT8_TYPE__)seed;

    __UINT8_TYPE__ index = getSeedyIndexRandomUInt8(getRandomUInt8(), ucSeed);

    return (getSeedyIndexRandomUInt8(index, ucSeed)
    + (rndtable[index + ucSeed] << 8)) ^ seed;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT32_TYPE__ getSeedyRandomUInt32(__UINT32_TYPE__ seed)
{
    __UINT8_TYPE__ ucSeed = (__UINT8_TYPE__)seed;

    __UINT8_TYPE__ firstIndex = getSeedyIndexRandomUInt8(3, ucSeed);
    __UINT8_TYPE__ secondIndex = getSeedyIndexRandomUInt8(4, ucSeed);

    return (getSeedyIndexRandomUInt8(secondIndex, ucSeed)
    + (rndtable[secondIndex + ucSeed] << 8)
    + (getSeedyIndexRandomUInt8(firstIndex, ucSeed) << 16)
    + (rndtable[firstIndex + ucSeed] << 24)) ^ seed;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT64_TYPE__ getSeedyRandomUInt64(__UINT64_TYPE__ seed)
{
    __UINT8_TYPE__ ucSeed = (__UINT8_TYPE__)seed;

    __UINT8_TYPE__ firstIndex = getSeedyIndexRandomUInt8(5, ucSeed);
    __UINT8_TYPE__ secondIndex = getSeedyIndexRandomUInt8(6, ucSeed);
    __UINT8_TYPE__ thirdIndex = getSeedyIndexRandomUInt8(7, ucSeed);
    __UINT8_TYPE__ forthIndex = getSeedyIndexRandomUInt8(8, ucSeed);

    return ((__UINT64_TYPE__)getSeedyIndexRandomUInt8(forthIndex, ucSeed)
    + ((__UINT64_TYPE__)rndtable[forthIndex + ucSeed] << 8)
    + ((__UINT64_TYPE__)getSeedyIndexRandomUInt8(thirdIndex, ucSeed) << 16)
    + ((__UINT64_TYPE__)rndtable[thirdIndex + ucSeed] << 24)
    + ((__UINT64_TYPE__)getSeedyIndexRandomUInt8(secondIndex, ucSeed) << 32)
    + ((__UINT64_TYPE__)rndtable[secondIndex + ucSeed] << 40)
    + ((__UINT64_TYPE__)getSeedyIndexRandomUInt8(firstIndex, ucSeed) << 48)
    + ((__UINT64_TYPE__)rndtable[firstIndex + ucSeed] << 56)) ^ seed;
}

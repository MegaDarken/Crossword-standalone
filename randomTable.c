#include "randomTable.h"

//Doom psudorandom number table, with the second erronious 0 replaced with the missing 1
unsigned char rndtable[256] = {
    0,   8, 109, 220, 222, 241, 149, 107,  75, 248, 254, 140,  16,  66 ,
    74,  21, 211,  47,  80, 242, 154,  27, 205, 128, 161,  89,  77,  36 ,
    95, 110,  85,  48, 212, 140, 211, 249,  22,  79, 200,  50,  28, 188 ,
    52, 140, 202, 120,  68, 145,  62,  70, 184, 190,  91, 197, 152, 224 ,
    149, 104,  25, 178, 252, 182, 202, 182, 141, 197,   4,  81, 181, 242 ,
    145,  42,  39, 227, 156, 198, 225, 193, 219,  93, 122, 175, 249,   1 ,
    175, 143,  70, 239,  46, 246, 163,  53, 163, 109, 168, 135,   2, 235 ,
    25,  92,  20, 145, 138,  77,  69, 166,  78, 176, 173, 212, 166, 113 ,
    94, 161,  41,  50, 239,  49, 111, 164,  70,  60,   2,  37, 171,  75 ,
    136, 156,  11,  56,  42, 146, 138, 229,  73, 146,  77,  61,  98, 196 ,
    135, 106,  63, 197, 195,  86,  96, 203, 113, 101, 170, 247, 181, 113 ,
    80, 250, 108,   7, 255, 237, 129, 226,  79, 107, 112, 166, 103, 241 ,
    24, 223, 239, 120, 198,  58,  60,  82, 128,   3, 184,  66, 143, 224 ,
    145, 224,  81, 206, 163,  45,  63,  90, 168, 114,  59,  33, 159,  95 ,
    28, 139, 123,  98, 125, 196,  15,  70, 194, 253,  54,  14, 109, 226 ,
    71,  17, 161,  93, 186,  87, 244, 138,  20,  52, 123, 251,  26,  36 ,
    17,  46,  52, 231, 232,  76,  31, 221,  84,  37, 216, 165, 212, 106 ,
    197, 242,  98,  43,  39, 175, 254, 145, 190,  84, 118, 222, 187, 136 ,
    120, 163, 236, 249
};

unsigned char indices[256];

unsigned char getRandomUChar()
{
    indices[0]++;
    
    return rndtable[indices[0]];
}

unsigned int getRandomUInt()
{
    char index = getRandomUChar();
    indices[index]++;
    
    return rndtable[indices[index]] + (rndtable[index] << 8);
}

unsigned long getRandomULong()
{
    char firstIndex = getRandomUChar();
    indices[firstIndex]++;

    char secondIndex = rndtable[indices[firstIndex]];
    indices[secondIndex]++;

    return rndtable[indices[secondIndex]]
    + (rndtable[secondIndex] << 8)
    + (rndtable[indices[firstIndex]] << 16)
    + (rndtable[firstIndex] << 24);
}

unsigned long long getRandomULongLong()
{
    char firstIndex = getRandomUChar();
    indices[firstIndex]++;

    char secondIndex = rndtable[indices[firstIndex]];
    indices[secondIndex]++;

    char thirdIndex = rndtable[indices[secondIndex]];
    indices[thirdIndex]++;

    char forthIndex = rndtable[indices[thirdIndex]];
    indices[forthIndex]++;

    return (unsigned long long)rndtable[indices[forthIndex]]
    + ((unsigned long long)rndtable[forthIndex] << 8)
    + ((unsigned long long)rndtable[indices[thirdIndex]] << 16)
    + ((unsigned long long)rndtable[thirdIndex] << 24)
    + ((unsigned long long)rndtable[indices[secondIndex]] << 32)
    + ((unsigned long long)rndtable[secondIndex] << 40)
    + ((unsigned long long)rndtable[indices[firstIndex]] << 48)
    + ((unsigned long long)rndtable[firstIndex] << 56);
}


unsigned char getSeedyRandomUChar(unsigned char seed)
{
    indices[0]++;

    return rndtable[indices[0] + seed] ^ seed;
}

unsigned int getSeedyRandomUInt(unsigned int seed)
{
    unsigned char ucSeed = (unsigned char)seed;

    char index = getRandomUChar();
    indices[index]++;
    
    return (rndtable[indices[index] + ucSeed] + (rndtable[index + ucSeed] << 8)) ^ seed;
}

unsigned long getSeedyRandomULong(unsigned long seed)
{
    unsigned char ucSeed = (unsigned char)seed;

    char firstIndex = getRandomUChar();
    indices[firstIndex]++;

    char secondIndex = rndtable[indices[firstIndex]];
    indices[secondIndex]++;

    return (rndtable[indices[secondIndex] + ucSeed]
    + (rndtable[secondIndex + ucSeed] << 8)
    + (rndtable[indices[firstIndex] + ucSeed] << 16)
    + (rndtable[firstIndex + ucSeed] << 24)) ^ seed;
}

unsigned long long getSeedyRandomULongLong(unsigned long long seed)
{
    unsigned char ucSeed = (unsigned char)seed;

    char firstIndex = getRandomUChar();
    indices[firstIndex]++;

    char secondIndex = rndtable[indices[firstIndex]];
    indices[secondIndex]++;

    char thirdIndex = rndtable[indices[secondIndex]];
    indices[thirdIndex]++;

    char forthIndex = rndtable[indices[thirdIndex]];
    indices[forthIndex]++;

    return ((unsigned long long)rndtable[indices[forthIndex] + ucSeed]
    + ((unsigned long long)rndtable[forthIndex + ucSeed] << 8)
    + ((unsigned long long)rndtable[indices[thirdIndex] + ucSeed] << 16)
    + ((unsigned long long)rndtable[thirdIndex + ucSeed] << 24)
    + ((unsigned long long)rndtable[indices[secondIndex] + ucSeed] << 32)
    + ((unsigned long long)rndtable[secondIndex + ucSeed] << 40)
    + ((unsigned long long)rndtable[indices[firstIndex] + ucSeed] << 48)
    + ((unsigned long long)rndtable[firstIndex + ucSeed] << 56)) ^ seed;
}

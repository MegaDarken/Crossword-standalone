//Ensure loaded only once
#ifndef __RANDOM_TABLE__
#define __RANDOM_TABLE__

    unsigned char getRandomUChar();
    unsigned int getRandomUInt();
    unsigned long getRandomULong();
    unsigned long long getRandomULongLong();

    unsigned char getSeedyRandomUChar(unsigned char seed);
    unsigned int getSeedyRandomUInt(unsigned int seed);
    unsigned long getSeedyRandomULong(unsigned long seed);
    unsigned long long getSeedyRandomULongLong(unsigned long long seed);

#endif

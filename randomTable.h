//Ensure loaded only once
#ifndef __RANDOM_TABLE__
#define __RANDOM_TABLE__

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
unsigned char getRandomUChar();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
unsigned int getRandomUInt();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
unsigned long getRandomULong();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
unsigned long long getRandomULongLong();

//Seedy
#ifdef __cplusplus
extern "C"
#endif //__cplusplus
unsigned char getSeedyRandomUChar(unsigned char seed);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
unsigned int getSeedyRandomUInt(unsigned int seed);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
unsigned long getSeedyRandomULong(unsigned long seed);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
unsigned long long getSeedyRandomULongLong(unsigned long long seed);

#endif

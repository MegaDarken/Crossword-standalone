//Ensure loaded only once
#ifndef __RANDOM_TABLE__
#define __RANDOM_TABLE__

#define ONE_BYTE(type) (sizeof(type) == 1)
#define TWO_BYTE(type) (sizeof(type) == 2)
#define FOUR_BYTE(type) (sizeof(type) == 4)

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void randomTable_indicesFromTable();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT8_TYPE__ getRandomUInt8();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT16_TYPE__ getRandomUInt16();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT32_TYPE__ getRandomUInt32();

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT64_TYPE__ getRandomUInt64();

#define getRandomU(type) _Generic((type), \
        __uint8_t: getRandomUInt8(), \
        __uint16_t: getRandomUInt16(), \
        __uint32_t: getRandomUInt32(), \
        __uint64_t: getRandomUInt64() \
    )

//Seedy
#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT8_TYPE__ getSeedyRandomUInt8(__UINT8_TYPE__ seed);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT16_TYPE__ getSeedyRandomUInt16(__UINT16_TYPE__ seed);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT32_TYPE__ getSeedyRandomUInt32(__UINT32_TYPE__ seed);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
__UINT64_TYPE__ getSeedyRandomUInt64(__UINT64_TYPE__ seed);

#define getSeedyRandomU(seed) _Generic((seed), \
        __uint8_t: getSeedyRandomUInt8(seed), \
        __uint16_t: getSeedyRandomUInt16(seed), \
        __uint32_t: getSeedyRandomUInt32(seed), \
        __uint64_t: getSeedyRandomUInt64(seed) \
    )

#endif
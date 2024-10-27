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
        __UINT8_TYPE__: getRandomUInt8(), \
        __UINT16_TYPE__: getRandomUInt16(), \
        __UINT32_TYPE__: getRandomUInt32(), \
        __UINT64_TYPE__: getRandomUInt64() \
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
        __UINT8_TYPE__: getSeedyRandomUInt8(seed), \
        __UINT16_TYPE__: getSeedyRandomUInt16(seed), \
        __UINT32_TYPE__: getSeedyRandomUInt32(seed), \
        __UINT64_TYPE__: getSeedyRandomUInt64(seed) \
    )

#endif
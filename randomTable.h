//Ensure loaded only once
#ifndef __RANDOM_TABLE__
#define __RANDOM_TABLE__

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

#define getRandomU(type) \
    ({  type output = 0; \
        switch (sizeof(type)) { \
        case 1: \
            output = getRandomUInt8(); \
            break; \
        case 2: \
            output = getRandomUInt16(); \
            break; \
        case 4: \
            output = getRandomUInt32(); \
            break; \
        case 8: \
            output = getRandomUInt64(); \
            break; \
        default: \
            break; \
        } \
        output; })

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

#define getSeedyRandomU(seed) \
    ({  __typeof__ (seed) output = 0; \
        switch (sizeof(seed)) { \
        case 1: \
            output = getSeedyRandomUInt8(seed); \
            break; \
        case 2: \
            output = getSeedyRandomUInt16(seed); \
            break; \
        case 4: \
            output = getSeedyRandomUInt32(seed); \
            break; \
        case 8: \
            output = getSeedyRandomUInt64(seed); \
            break; \
        default: \
            break; \
        } \
        output; })

#endif
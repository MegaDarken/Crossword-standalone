#ifndef SWAPPING_
#define SWAPPING_

#include <string.h>

#define swap_helper(_1, _2, _3, NAME, ...) NAME

#define swap_known(x,y) \
    do { \
        unsigned char swap_temp[sizeof(*x) == sizeof(*y) ? (signed)sizeof(*x) : -1]; \
        memcpy(swap_temp,y,sizeof(*x)); \
        memcpy(y,x,       sizeof(*x)); \
        memcpy(x,swap_temp,sizeof(*x)); \
    } while(0)

#define swap_size(x,y,size) \
    do { \
        unsigned char swap_temp[size]; \
        memcpy(swap_temp,y,size); \
        memcpy(y,x,       size); \
        memcpy(x,swap_temp,size); \
    } while(0)

#define swap(...) swap_helper(__VA_ARGS__, swap_size, swap_known)(__VA_ARGS__)

#endif //SWAPPING_
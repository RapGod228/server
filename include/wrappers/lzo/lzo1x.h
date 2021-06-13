/**
  @file lzo/lzo1x.h
  This service provides dynamic access to LZO.
*/

#ifndef LZO_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#ifndef MYSQL_ABI_CHECK
#include <stdbool.h>
#endif

#ifndef LZO_E_OK
#define LZO_E_OK                0
#define LZO_E_INTERNAL_ERROR    (-99)

#define LZO1X_1_15_MEM_COMPRESS ((unsigned int) (32768L * ((unsigned) sizeof(unsigned char *))))

typedef unsigned long lzo_uint;

#define lzo1x_1_15_compress(...)   wrapper_service_lzo->lzo1x_1_15_compress_ptr   (__VA_ARGS__)
#define lzo1x_decompress_safe(...) wrapper_service_lzo->lzo1x_decompress_safe_ptr (__VA_ARGS__)
#endif

#define DEFINE_lzo1x_1_15_compress(NAME) NAME(  \
    const unsigned char *src,                   \
    unsigned long src_len,                      \
    unsigned char *dst,                         \
    unsigned long *dst_len,                     \
    void *wrkmem                                \
)

#define DEFINE_lzo1x_decompress_safe(NAME) NAME( \
    const unsigned char *src,                    \
    unsigned long src_len,                       \
    unsigned char *dst,                          \
    unsigned long *dst_len,                      \
    void *wrkmem                                 \
)

struct wrapper_service_lzo_st
{
  int DEFINE_lzo1x_1_15_compress((*lzo1x_1_15_compress_ptr));
  int DEFINE_lzo1x_decompress_safe((*lzo1x_decompress_safe_ptr));
};

extern struct wrapper_service_lzo_st *wrapper_service_lzo;

#ifdef __cplusplus
}
#endif

#define LZO_INCLUDED
#endif

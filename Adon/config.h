#ifndef CONFIG_HEADER
#define CONFIG_HEADER

#include <cstdint>
#include <string>

#ifndef _WIN32
//SINGED INTEGERS
#if defined __INT8_TYPE__
typedef int8_t              int8;
#elif defined __INT_FAST8_TYPE__
typedef int_fast8_t         int8;
#elif defined __INT_LEAST8_TYPE__
typedef int_least8_t        int8;
#endif

#if defined __INT16_TYPE__
typedef int16_t              int16;
#elif defined __INT_FAST16_TYPE__
typedef int_fast16_t         int16;
#elif defined __INT_LEAST16_TYPE__
typedef int_least16_t        int16;
#endif

#if defined __INT32_TYPE__
typedef int32_t              int32;
#elif defined __INT_FAST32_TYPE__
typedef int_fast32_t         int32;
#elif defined __INT_LEAST32_TYPE__
typedef int_least32_t        int32;
#endif

#if defined __INT64_TYPE__
typedef int64_t              int64;
#elif defined __INT_FAST64_TYPE__
typedef int_fast64_t         int64;
#elif defined __INT_LEAST64_TYPE__
typedef int_least64_t        int64;
#endif

//UNSIGNED INTEGERS
#if defined __UINT8_TYPE__
typedef uint8_t             uint8;
#elif defined __UINT_FAST8_TYPE__
typedef uint_fast8_t        uint8;
#elif defined __UINT_LEAST8_TYPE__
typedef uint_least8_t       uint8;
#endif

#if defined __UINT16_TYPE__
typedef uint16_t            uint16;
#elif defined __UINT_FAST16_TYPE__
typedef uint_fast16_t       uint16;
#elif defined __UINT_LEAST16_TYPE__
typedef uint_least16_t      uint16;
#endif

#if defined __UINT32_TYPE__
typedef uint32_t              uint32;
#elif defined __UINT_FAST32_TYPE__
typedef uint_fast32_t         uint32;
#elif defined __UINT_LEAST32_TYPE__
typedef uint_least32_t        uint32;
#endif

#if defined __UINT64_TYPE__
typedef uint64_t              uint64;
#elif defined __UINT_FAST64_TYPE__
typedef uint_fast64_t         uint64;
#elif defined __UINT_LEAST64_TYPE__
typedef uint_least64_t        uint64;
#endif
#else

typedef int8_t								int8;
typedef int16_t								int16;
typedef int32_t								int32;
typedef int64_t								int64;

#endif //NOT WIN32

#endif //CONFIG_HEADER

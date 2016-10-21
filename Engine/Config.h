#ifndef ENGINE_CONFIG_H_
#define ENGINE_CONFIG_H_

#define ENGINE_LINUX 1

#if defined(__GNUC__)
    #if defined(ENGINE_STATICLIB)
        #define ENGINE_API
    #else
        #if defined(ENGINE_SOURCE)
            #define ENGINE_API __attribute__((visibility ("default")))
        #else
            // If you use -fvisibility=hidden in GCC, exception handling and RTII
            // would break if visibility wasn't set during export _and_ import
            // because GCC would inmediately forget all type infos encountered.
            // See http://gcc.gnu.org/wiki/Visibility
            #define ENGINE_API __attribute__((visibility ("default")))
        #endif
    #endif
#else
    #error Unknow compiler, please implement shared libraries macros
#endif

#endif // ENGINE_CONFIG_H_


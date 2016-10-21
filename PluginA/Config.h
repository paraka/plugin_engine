#ifndef PLUGIN_A_CONFIG_H_
#define PLUGIN_A_CONFIG_H_

#if defined(__GNUC__)
    #if defined(PLUGIN_A_STATICLIB)
        #define PLUGIN_A_API
    #else
        #if defined(PLUGIN_A_SOURCE)
            #define PLUGIN_A_API __attribute__((visibility ("default")))
        #else
            // If you use -fvisibility=hidden in GCC, exception handling and RTII
            // would break if visibility wasn't set during export _and_ import
            // because GCC would inmediately forget all type infos encountered.
            // See http://gcc.gnu.org/wiki/Visibility
            #define PLUGIN_A_API __attribute__((visibility ("default")))
        #endif
    #endif
#else
    #error Unknow compiler, please implement shared libraries macros
#endif

#endif // PLUGIN_A_CONFIG_H_


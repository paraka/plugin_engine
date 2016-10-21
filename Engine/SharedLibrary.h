#ifndef _ENGINE_SHARED_LIBRARY_H_
#define _ENGINE_SHARED_LIBRARY_H_

#include <string>
#include <stdexcept>

#if defined(ENGINE_LINUX)
#include <dlfcn.h>
#endif

#include "Config.h"

namespace Engine
{

#if defined(ENGINE_LINUX)

class SharedLibrary
{
    public:
        using HandleType = void *;

        ENGINE_API static HandleType Load(const std::string &path)
        {
            std::string pathWithExtension = std::string("./lib") + path + ".so";
            
            HandleType sharedObject = ::dlopen(pathWithExtension.c_str(), RTLD_NOW);
            if (sharedObject == NULL)
                throw std::runtime_error(std::string("Could not load '") + pathWithExtension + "'"); 

            return sharedObject;
        }

        ENGINE_API static void UnLoad(HandleType sharedLibraryHandle)
        {
            int result = ::dlclose(sharedLibraryHandle);
            if (result != 0)
                throw std::runtime_error("Could not unload shared object");
        }

        template <typename TSignature>
        static TSignature *GetFunctionPointer(HandleType sharedLibraryHandle, const std::string &functionName)
        {
            ::dlerror(); // clear error value

            void *functionAddress = ::dlsym(sharedLibraryHandle, functionName.c_str());

            const char *error = ::dlerror();
            if (error != NULL)
                throw std::runtime_error("Cpuld not find exported function");

            return reinterpret_cast<TSignature *>(functionAddress);
        }
};

#else

    #warning Only linux is implemented yet!!

#endif

} // namespace Engine

#endif // _ENGINE_SHARED_LIBRARY_H_

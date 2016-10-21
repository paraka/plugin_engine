#ifndef _ENGINE_CORE_H_
#define _ENGINE_CORE_H_

#include <string>
#include <memory>
#include "Config.h"

namespace Engine
{

    class PluginAServer;

    class Core
    {
        public:                
            Core();
            ~Core();

            ENGINE_API PluginAServer &getPluginAServer();
            // ... Add plugin families here ...
            ENGINE_API void loadPlugin(const std::string &filename);

        private:
            class CoreImpl;
            using CoreImplPtr = std::unique_ptr<CoreImpl>;
            CoreImplPtr Impl;
    };

} // name space Engine

#endif // _ENGINE_CORE_H_

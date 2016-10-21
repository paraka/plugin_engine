#ifndef _PLUGINA_SERVER_H_
#define _PLUGINA_SERVER_H_


#include <memory>
#include "Config.h"

namespace Engine
{

    class PluginAServer 
    {
        public:
            class PluginA
            {
            public:
                PluginA() = default;
                virtual ~PluginA() = default;
                virtual bool canDoStuff1() = 0;
                virtual int doStuff1() = 0;
            };

            PluginAServer();
            ENGINE_API ~PluginAServer();
            using PluginAPtr = std::unique_ptr<PluginA>;
            ENGINE_API void addPluginA(PluginAPtr plugin);
            ENGINE_API int doStuff1();

        private:
            class PluginAServerImpl;
            using PluginAServerImplPtr = std::unique_ptr<PluginAServerImpl>;
            PluginAServerImplPtr Impl;
    };

} // namespace Engine

#endif // _PLUGINA_SERVER_H_

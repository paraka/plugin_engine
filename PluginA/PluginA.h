
#include <memory>
#include "../Engine/Core.h"
#include "../Engine/PluginAServer.h"
#include "Config.h"

#define PLUGIN_A_SOURCE 1

namespace Engine
{

    class PluginADriver: public PluginAServer::PluginA
    {
        public:
            PLUGIN_A_API PluginADriver() = default;
            PLUGIN_A_API virtual ~PluginADriver() = default;
            PLUGIN_A_API bool canDoStuff1();
            PLUGIN_A_API int doStuff1();
    };

    extern "C" PLUGIN_A_API int getEngineVersion()
    {
        return 1;
    }

    extern "C" PLUGIN_A_API void registerPlugin(Core &core)
    {
        PluginAServer::PluginAPtr plugin_to_register(new PluginADriver());
        if (plugin_to_register)
            core.getPluginAServer().addPluginA(std::move(plugin_to_register));
    }


} // namespace Engine

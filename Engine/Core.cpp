#include <map>
#include "Core.h"
#include "Plugin.h"
#include "PluginAServer.h"

namespace Engine
{

class Core::CoreImpl
{
public:
    using PluginMap = std::map<std::string, Plugin>;
    PluginMap loadedPlugins;
    PluginAServer pluginAServer;
};


Core::Core() : Impl(std::make_unique<CoreImpl>()) { }

Core::~Core() = default;

ENGINE_API PluginAServer &Core::getPluginAServer() const
{
    return Impl->pluginAServer;
}

ENGINE_API void Core::loadPlugin(const std::string &filename)
{
    if (Impl->loadedPlugins.find(filename) == Impl->loadedPlugins.end())
    {
        Plugin plugin(filename);
        Impl->loadedPlugins.insert(CoreImpl::PluginMap::value_type(filename, std::move(plugin))
        ).first->second.registerPlugin(*this);
    }
}

} // namespace Engine

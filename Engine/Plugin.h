#ifndef _ENGINE_PLUGIN_H_
#define _ENGINE_PLUGIN_H_

#include <memory>
#include <string>
#include "Config.h"

namespace Engine
{
    class Core;

    class Plugin
    {
        public:
            ENGINE_API Plugin(const std::string &filename);
            ENGINE_API Plugin(const Plugin &other) = default;
            ENGINE_API Plugin(Plugin && other) = default;
            Plugin &operator =(const Plugin &other) = default;
            ENGINE_API ~Plugin();
            ENGINE_API int getEngineVersion() const;
            ENGINE_API void registerPlugin(Core &core);

        private:
            class PluginImpl;
            using PluginImplPtr = std::shared_ptr<PluginImpl>;
            PluginImplPtr Impl;
    };

} // namespace Engine

#endif

#include <list>
#include <stdexcept>
#include "PluginAServer.h"

namespace Engine
{

class PluginAServer::PluginAServerImpl
{
public:
    using PluginAList = std::list<PluginAPtr>;
    PluginAList pluginAlist;
};

PluginAServer::PluginAServer() : Impl(new PluginAServerImpl()) { }
PluginAServer::~PluginAServer() = default;

void PluginAServer::addPluginA(PluginAPtr plugin)
{
    Impl->pluginAlist.push_back(std::move(plugin));
}

int PluginAServer::doStuff1()
{
    for (auto &x : Impl->pluginAlist)
    {
        const PluginAPtr &ptr = x;
        if (ptr->canDoStuff1())
            return (ptr->doStuff1());
    }

    throw std::runtime_error("Invalid or unsopported stuff1");
}

} //namespace Engine

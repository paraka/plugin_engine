#include <iostream>
#include "../Engine/Core.h"
#include "../Engine/PluginAServer.h"

using namespace Engine;

void tryExecStuff(PluginAServer &pluginAServer)
{
    try
    {
        std::cout << "Making stuff1: " << pluginAServer.doStuff1() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(int arg, char *argv[])
{
    Core core;

    try
    {
        std::cout << "Trying to make stufff before load plugins..." << std::endl;
        tryExecStuff(core.getPluginAServer());

        std::cout << "Loading plugins..." << std::endl;
        core.loadPlugin("PluginA");
        tryExecStuff(core.getPluginAServer());
    }
    catch (const std::exception &e)
    {
        std::cout << "Unhandled error: " << e.what() << std::endl;
    }
}

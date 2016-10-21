#include "Plugin.h"
#include "SharedLibrary.h"

namespace Engine
{

class Plugin::PluginImpl
{
    typedef int GetEngineVersionFunction();
    typedef void RegisterPluginFunction(Core &);

public:
    PluginImpl(const std::string &filename) : 
        shareLibraryHandle(0), 
        getEngineVersionAddress(0),
        registerPluginAddress(0) 
    {
        shareLibraryHandle = SharedLibrary::Load(filename);
        try
        {
            getEngineVersionAddress = SharedLibrary::GetFunctionPointer<GetEngineVersionFunction>(shareLibraryHandle, "getEngineVersion");
            registerPluginAddress = SharedLibrary::GetFunctionPointer<RegisterPluginFunction>(shareLibraryHandle, "registerPlugin");
        }
        catch (const std::exception &)
        {
            SharedLibrary::UnLoad(shareLibraryHandle);
            throw; // Should be throw this inside constructor???
        }
    }

    ~PluginImpl()
    {
        SharedLibrary::UnLoad(shareLibraryHandle);
    }

    SharedLibrary::HandleType shareLibraryHandle;
    GetEngineVersionFunction *getEngineVersionAddress;
    RegisterPluginFunction *registerPluginAddress;
};

Plugin::Plugin(const std::string &filename) : Impl(new PluginImpl(filename)) { }

Plugin::~Plugin() = default;

int Plugin::getEngineVersion() const 
{
    return Impl->getEngineVersionAddress(); 
}

void Plugin::registerPlugin(Core &core) 
{ 
    Impl->registerPluginAddress(core);
}

template<typename T>
struct is_regular : std::integral_constant <bool,
    //std::is_default_constructible<T>::value &&
    std::is_copy_constructible<T>::value &&
    std::is_move_constructible<T>::value &&
    std::is_copy_assignable<T>::value &&
    std::is_move_assignable<T>::value>
{};

static_assert(is_regular<Plugin>::value, "Plugin seems to be not regular type...");

} // namespace Engine

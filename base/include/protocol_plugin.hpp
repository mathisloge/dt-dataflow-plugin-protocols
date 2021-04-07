#include <Corrade/PluginManager/AbstractManager.h>
#include <Magnum/GL/OpenGL.h>
#include <dt/df/plugin/plugin.hpp>
#include <imnodes.h>

namespace dt::df::plugin
{

class ProtocolPlugin : public Plugin
{

  public:
    explicit ProtocolPlugin(Corrade::PluginManager::AbstractManager &manager, const std::string &plugin);
    void setup(Magnum::GL::Context &gl_ctx, ImGuiContext *imgui_ctx, imnodes::Context *imnodes_ctx);
    virtual void registerNodeFactories(IGraphManager &graph) = 0;
    virtual void registerSlotFactories(IGraphManager &graph) = 0;
};
} // namespace dt::df::plugin

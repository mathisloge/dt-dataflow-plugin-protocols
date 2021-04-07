#include "protocol_plugin.hpp"
#include <Magnum/Platform/GLContext.h>
namespace dt::df::plugin
{
ProtocolPlugin::ProtocolPlugin(Corrade::PluginManager::AbstractManager &manager, const std::string &plugin)
    : Plugin{manager, plugin}
{}

void ProtocolPlugin::setup(Magnum::GL::Context &gl_ctx, ImGuiContext *imgui_ctx, imnodes::Context *imnodes_ctx)
{
    Magnum::Platform::GLContext::makeCurrent(&gl_ctx);
    ImGui::SetCurrentContext(imgui_ctx);
    imnodes::SetCurrentContext(imnodes_ctx);
}
} // namespace dt::df::plugin

#include <Corrade/PluginManager/AbstractManager.h>
#include <protocol_plugin.hpp>
#include "protocol_ublox.hpp"
namespace dt::df::plugin
{
class UbloxProtocolPlugin final : public ProtocolPlugin
{
  public:
    explicit UbloxProtocolPlugin(Corrade::PluginManager::AbstractManager &manager, const std::string &plugin)
        : ProtocolPlugin{manager, plugin}
    {}

    void registerNodeFactories(IGraphManager &graph) override
    {}
    void registerSlotFactories(IGraphManager &graph) override
    {}
};
} // namespace dt::df::plugin

CORRADE_PLUGIN_REGISTER(UbloxProtocol, dt::df::plugin::UbloxProtocolPlugin, "de.mathisloge.dt.dataflow/1.0")

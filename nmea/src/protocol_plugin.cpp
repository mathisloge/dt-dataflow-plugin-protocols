#include <Corrade/PluginManager/AbstractManager.h>
#include <protocol_plugin.hpp>
#include "protocol_nmea.hpp"
namespace dt::df::plugin
{
class NmeaProtocolPlugin final : public ProtocolPlugin
{
  public:
    explicit NmeaProtocolPlugin(Corrade::PluginManager::AbstractManager &manager, const std::string &plugin)
        : ProtocolPlugin{manager, plugin}
    {}

    void registerNodeFactories(IGraphManager &graph) override
    {}
    void registerSlotFactories(IGraphManager &graph) override
    {}
};
} // namespace dt::df::plugin

CORRADE_PLUGIN_REGISTER(NmeaProtocol, dt::df::plugin::NmeaProtocolPlugin, "de.mathisloge.dt.dataflow/1.0")

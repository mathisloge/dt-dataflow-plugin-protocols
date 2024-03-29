#pragma once
#include <protocol_types.hpp>
#include <ublox/Message.h>
#include <ublox/frame/UbloxFrame.h>
#include <ublox/input/ClientInputMessages.h>
#include <ublox/options/ClientDefaultOptions.h>

// we compile this in a seperate compile unit since the build time of the protocol itself can be very long.
// as this header will not change this often, the build times will decrease a lot after the first build

namespace protocol::detail
{
class UbloxHandler;
// Common interface class for all the messages
using UbloxMessage = ublox::Message<comms::option::app::ReadIterator<ProtoReadIter>,
                                    comms::option::app::WriteIterator<std::back_insert_iterator<ProtoWriteData>>,
                                    comms::option::app::IdInfoInterface,
                                    comms::option::app::LengthInfoInterface,
                                    comms::option::app::NameInterface,
                                    comms::option::app::Handler<UbloxHandler>>;

// Protocol options for client
using UbloxClientProtocolOptions = ublox::options::ClientDefaultOptions;

// Client specific frame
using UbloxFrame = ublox::frame::UbloxFrame<UbloxMessage,
                                            ublox::input::ClientInputMessages<UbloxMessage, UbloxClientProtocolOptions>,
                                            UbloxClientProtocolOptions>;

struct UbloxInstance
{
    UbloxFrame frame;
    comms::ErrorStatus processSingle(ProtoReadIter begin,
                                     ProtoReadIter end,
                                     std::pair<ProtoReadIter, ProtoReadIter> &read_range,
                                     UbloxHandler &handler);
};

class UbloxHandler
{
  public:
    virtual void handle(UbloxMessage &msg);
};

} // namespace protocol::detail

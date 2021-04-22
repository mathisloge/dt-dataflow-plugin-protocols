#include "protocol_nmea.hpp"
#include <nmea/nmea_parser.hpp>
#include <spdlog/spdlog.h>

namespace protocol
{
    ProtocolNmea::ProtocolNmea()
        : state_{State::activated}
    {
    }

    std::string_view ProtocolNmea::name() const
    {
        return "NMEA0183";
    }

    std::pair<ProtoReadIter, ProtoReadIter> ProtocolNmea::consumeOneMessage(ProtoReadIter begin, ProtoReadIter end)
    {
        nmea::detail::AllNmeaMessages msg_var;
        ProtoReadIter read_end = begin;
        if (nmea::parseOneWithDispatch(read_end, end, handler_))
            return std::make_pair(begin, read_end);
        return std::make_pair(begin, begin);
    }

    void ProtocolNmea::setState(State state)
    {
        state_ = state;
    }
    bool ProtocolNmea::isActive() const
    {
        return state_ == State::activated;
    }
} // namespace protocol

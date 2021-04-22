#pragma once
#include <protocol.hpp>
#include "handler.hpp"

namespace protocol
{
    class ProtocolNmea : public Protocol
    {
    public:
        ProtocolNmea();
        std::string_view name() const override;
        std::pair<ProtoReadIter, ProtoReadIter> consumeOneMessage(ProtoReadIter begin, ProtoReadIter end) override;
        void setState(State state) override;
        bool isActive() const override;

    private:
        NmeaHandler handler_;
        State state_;
    };
} // namespace protocol

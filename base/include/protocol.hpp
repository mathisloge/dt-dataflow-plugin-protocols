#pragma once
#include <string_view>
#include <boost/noncopyable.hpp>
#include "protocol_types.hpp"
namespace protocol
{
    class Protocol : boost::noncopyable
    {
    public:
        enum class State
        {
            activated,
            deactivated
        };

    public:
        Protocol() = default;
        virtual std::string_view name() const = 0;
        virtual std::pair<ProtoReadIter, ProtoReadIter> consumeOneMessage(ProtoReadIter begin, ProtoReadIter end) = 0;
        virtual void setState(State state) = 0;
        virtual bool isActive() const = 0;
        virtual ~Protocol() = default;
    };
} // namespace protocol

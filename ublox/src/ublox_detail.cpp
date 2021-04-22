#include "ublox_detail.hpp"
#include <comms/comms.h>
#include <comms/process.h>

namespace protocol::detail
{
    comms::ErrorStatus UbloxInstance::processSingle(ProtoReadIter begin, ProtoReadIter end,
                                                    std::pair<ProtoReadIter, ProtoReadIter> &read_range,
                                                    UbloxHandler &handler)
    {
        using FrameType = typename std::decay<decltype(frame)>::type;
        using MsgPtr = typename FrameType::MsgPtr;
        MsgPtr msg;
        ProtoReadIter read_it = begin;
        const auto status = comms::processSingleWithDispatch(read_it, std::distance(begin, end), frame, msg, handler);

        read_range.first = begin;
        read_range.second = read_it;
        return status;
    }

    void UbloxHandler::handle(UbloxMessage &msg)
    {
        
    }

} // namespace protocol::detail

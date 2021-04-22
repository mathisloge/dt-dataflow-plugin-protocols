#pragma once
#include <cstdint>
#include <vector>
#include <span>

namespace protocol
{
    using ProtoReadData = std::span<uint8_t>;
    using ProtoReadIter = ProtoReadData::iterator;

    using ProtoWriteData = std::vector<uint8_t>;
} // namespace protocol

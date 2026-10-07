#pragma once

#include <atomic>
#include <cstdint>

namespace hooks {

// Monotonic world version: incremented on world mutations that invalidate
// Lua-side environment caches (stack moves, group changes, stack removal,
// engine flushes of added/changed/erased objects).
inline std::atomic<std::uint64_t>& worldVersion()
{
    static std::atomic<std::uint64_t> value{0};
    return value;
}

inline void bumpWorldVersion()
{
    worldVersion().fetch_add(1, std::memory_order_relaxed);
}

} // namespace hooks
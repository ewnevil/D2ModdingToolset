#include "worldversion.h"

namespace hooks {

// Single process-wide counter in a single translation unit (BUG-048):
// no function-local static — the previous inline-local std::atomic required
// a thread-safe-init guard on first call, which faulted on the worker Lua
// thread during battle initialization.
std::atomic<std::uint64_t> g_worldVersion{0};

std::atomic<std::uint64_t>& worldVersion()
{
    return g_worldVersion;
}

void bumpWorldVersion()
{
    g_worldVersion.fetch_add(1, std::memory_order_relaxed);
}

} // namespace hooks

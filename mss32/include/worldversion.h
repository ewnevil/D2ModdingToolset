#pragma once

#include <atomic>
#include <cstdint>

namespace hooks {

// Monotonic world version: incremented on world mutations that invalidate
// Lua-side environment caches (stack moves, group changes, stack removal,
// engine flushes of added/changed/erased objects).
// Defined in src/worldversion.cpp as a namespace-scope object: a function-local
// static here would require a thread-safe-init guard on first call (dynamic
// initialization, atomic ctor is constexpr only since C++20) which crashed the
// process on the worker Lua thread during battle init (BUG-048).
std::atomic<std::uint64_t>& worldVersion();

void bumpWorldVersion();

} // namespace hooks

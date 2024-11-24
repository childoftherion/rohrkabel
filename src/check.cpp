#include "utils/check.hpp"
#include <fmt/core.h>
#include <cstring>
#include <iostream>

namespace pipewire
{
#ifdef NDEBUG
    void check(bool, std::string_view, const std::source_location) {}
#else
    void check(bool condition, std::string_view message, const std::source_location loc)
    {
        if (condition)
        {
            return;
        }

        const auto *error = strerror(errno);
        std::cerr << fmt::format("{}:{} in function '{}': {} ({})\n",
            loc.file_name(), loc.line(), loc.function_name(),
            message, error);
        std::abort();
    }
#endif
} // namespace pipewire

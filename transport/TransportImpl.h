#pragma once

#include <mama/types.h>
#include <string>

struct Transport {
    mamaTransport parent;
    std::string name;

    void dispatch(uint64_t timeout) {
        mama_log(MAMA_LOG_LEVEL_FINEST, "Transport::dispatch(%" PRIu64 ")", timeout);
    }
};

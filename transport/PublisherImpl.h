#pragma once

#include <string>
#include <mama/types.h>
#include "TransportImpl.h"

struct Publisher {
    std::string root;
    std::string source;
    std::string topic;
    Transport* transport;
    mamaPublisher parent;
    mamaPublisherCallbacks callbacks;
    void* callbackClosure;

    Publisher()
        : callbackClosure(nullptr)
    {
        ::memset(&callbacks, 0, sizeof(mamaPublisherCallbacks));
    }
};

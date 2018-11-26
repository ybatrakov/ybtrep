#pragma once

#define OPENMAMA_INTEGRATION
#include <mama/integration/transport.h>
#include <mama/types.h>

#include <string>

#include "TransportImpl.h"

struct Subscription {
    bool active;
    std::string source;
    std::string symbol;
    Transport* transport;
    mamaMsgCallbacks callbacks;
    mamaSubscription parent;
    void* callbackClosure;

    Subscription() :
        active(false)
    {}

    static inline Subscription* get(subscriptionBridge sb) {
        return reinterpret_cast<Subscription*>(sb);
    }
};

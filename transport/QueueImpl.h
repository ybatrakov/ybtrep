#pragma once

#include "TransportImpl.h"
#include <mama/types.h>
#include <vector>

struct Queue {
    mamaQueue parent;
    std::vector<Transport*> transports;

    void addTransport(Transport* tport) {
        if(tport != nullptr) {
            transports.push_back(tport);
        }
    }

    void dispatch(uint64_t timeout) {
        for(auto i = transports.begin(); i != transports.end(); ++i) {
            (*i)->dispatch(timeout);
        }
    }
};

#pragma once

#include "TransportImpl.h"
#include <mama/types.h>
#include <vector>
#include <algorithm>

struct Queue {
    mamaQueue parent;
    std::vector<Transport*> transports;

    void addTransport(Transport* tport) {
        if(tport == nullptr) {
            return;
        }

        auto it = std::find(transports.begin(), transports.end(), tport);
        if(it == transports.end()) {
            transports.push_back(tport);
        }
    }

    void dispatch(uint64_t timeout) {
        for(auto i = transports.begin(); i != transports.end(); ++i) {
            (*i)->dispatch(timeout);
        }
    }
};

#pragma once

#include <mama/types.h>

struct Utils {
    static bool addTransportToQueue(mamaTransport tport, mamaQueue q);

    template<typename ToDeleteType>
    static void deleteWithCallback(ToDeleteType* d) {
        auto destroyCb = d->callbacks.onDestroy;
        auto parent    = d->parent;
        void* closure  = d->callbackClosure;

        delete d;

        if(destroyCb) {
            destroyCb(parent, closure);
        }
    }

    Utils() = delete;
    Utils& operator=(const Utils&) = delete;
};

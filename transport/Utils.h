#pragma once

#include <mama/types.h>
#include "DeleteUtils.h"

struct Utils {
    static bool addTransportToQueue(mamaTransport tport, mamaQueue q);

    template<typename ToDeleteType>
    static void deleteWithCallback(ToDeleteType* d) {
        DeleteWithCallback<HasCallbacks<ToDeleteType>::value>::del(d);
    }

    Utils() = delete;
    Utils& operator=(const Utils&) = delete;
};

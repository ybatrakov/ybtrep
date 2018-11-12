#pragma once

#define OPENMAMA_INTEGRATION
#include <mama/integration/transport.h>

#include "QueueImpl.h"
#include "TransportImpl.h"

struct Utils {
    static bool addTransportToQueue(mamaTransport tport, mamaQueue q) {
        Queue* queue = nullptr;
        mama_status rc = mamaQueue_getNativeHandle(q, reinterpret_cast<void**>(&queue));
        if(rc != MAMA_STATUS_OK || queue == nullptr) {
            mama_log(MAMA_LOG_LEVEL_ERROR, "Utils::addTransportToQueue: Couldn't get bridge queue: %s",
                     mamaStatus_stringForStatus(rc));
            return false;
        }

        Transport* transport = nullptr;
        rc = mamaTransport_getBridgeTransport(tport,  reinterpret_cast<transportBridge*>(&transport));
        if (rc != MAMA_STATUS_OK || transport == nullptr)
        {
            mama_log (MAMA_LOG_LEVEL_ERROR, "Utils::addTransportToQueue: Couldn't get bridge transport: %s",
                      mamaStatus_stringForStatus(rc));
            return false;
        }

        queue->addTransport(transport);
        return true;
    }

    Utils() = delete;
    Utils& operator=(const Utils&) = delete;
};
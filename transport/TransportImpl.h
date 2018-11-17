#pragma once

#define OPENMAMA_INTEGRATION
#include <mama/integration/transport.h>
#include <mama/types.h>
#include <string>

#include "DictionaryImpl.h"

struct Transport {
    mamaTransport parent;
    std::string name;
    Dictionary dict;

    void dispatch(uint64_t timeout) {
        (void) timeout;
        dict.dispatch();
    }

    void sendDictionaryRequest(mamaInbox inbox, mamaMsg msg) {
        mama_log(MAMA_LOG_LEVEL_FINEST, "Transport::sendDictionaryRequest");
        dict.sendRequest(inbox, msg);
    }

    inline static Transport* get(mamaTransport tport) {
        Transport* transport = nullptr;
        mama_status rc = mamaTransport_getBridgeTransport(tport, reinterpret_cast<transportBridge*>(&transport));
        if (rc != MAMA_STATUS_OK || transport == nullptr) {
            mama_log (MAMA_LOG_LEVEL_ERROR, "Utils::getTransport: Couldn't get bridge transport: %s",
                      mamaStatus_stringForStatus(rc));
            return nullptr;
        }
        return transport;
    }
};

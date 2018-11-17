#pragma once

#include <mama/mama.h>

struct MessageUtils {
    static mamaPayloadBridge payloadBridge;

    static mamaPayloadBridge getBridge() {
        if(payloadBridge == nullptr) {
            mama_status rc = mama_getPayloadBridge(&payloadBridge, "ybtrepmsg");
            if(rc != MAMA_STATUS_OK) {
                mama_log(MAMA_LOG_LEVEL_ERROR, "MessageUtils::init: Could not get payload bridge: %s",
                         mamaStatus_stringForStatus(rc));
                return nullptr;
            }
        }

        return payloadBridge;
    }

    static mamaMsg createMamaMsg() {
        mamaMsg ret;

        mamaPayloadBridge pb = getBridge();
        if(pb == nullptr) {
            return ret;
        }

        mama_status rc = mamaMsg_createForPayloadBridge(&ret, pb);
        if(rc != MAMA_STATUS_OK) {
            mama_log(MAMA_LOG_LEVEL_ERROR, "MessageUtils::createMamaMsg: Could not create message: %s",
                     mamaStatus_stringForStatus(rc));
            return nullptr;
        }

        return ret;
    }
};

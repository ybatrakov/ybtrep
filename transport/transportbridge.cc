#include "transportbridge.h"

#define OPENMAMA_INTEGRATION
#include <mama/integration/mama.h>

namespace {
    const char* BRIDGE_NAME = "ybtrep";
    const char* BRIDGE_VERSION = "0.1";
};

mama_status ybtrepBridge_init (mamaBridge bridgeImpl) {
    MAMA_SET_BRIDGE_COMPILE_TIME_VERSION(BRIDGE_NAME);
    (void) bridgeImpl;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridge_open (mamaBridge bridgeImpl) {
    (void) bridgeImpl;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridge_close (mamaBridge bridgeImpl) {
    (void) bridgeImpl;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridge_start (mamaQueue defaultEventQueue) {
  (void) defaultEventQueue;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridge_stop (mamaQueue defaultEventQueue) {
    (void) defaultEventQueue;
    return MAMA_STATUS_OK;
}

const char* ybtrepBridge_getVersion () {
    return BRIDGE_VERSION;
}

const char* ybtrepBridge_getName () {
    return BRIDGE_NAME;
}

mama_status ybtrepBridge_getDefaultPayloadId (const char ***name, const char **id) {
    if (name == nullptr || id == nullptr) {
        return MAMA_STATUS_NULL_ARG;
    }

    static const char* payloads[] = {"ybtrepmsg", nullptr};
    *name = payloads;

    static const char ids[] = {MAMA_PAYLOAD_TICK42RMDS, '\0'};
    *id = ids;

     return MAMA_STATUS_OK;
}

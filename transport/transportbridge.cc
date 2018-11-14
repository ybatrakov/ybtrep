#define OPENMAMA_INTEGRATION
#include <mama/integration/mama.h>
#include <bridge.h>

#include "transportbridge.h"
#include "queue.h"

namespace {
    const char* BRIDGE_NAME = "ybtrep";
    const char* BRIDGE_VERSION = "0.1";

    bool g_skipUsageNotice = false;
};

mama_status ybtrepBridge_init (mamaBridge bridgeImpl) {
    MAMA_SET_BRIDGE_COMPILE_TIME_VERSION(BRIDGE_NAME);

    g_skipUsageNotice = properties_GetPropertyValueAsBoolean(
        mamaBridgeImpl_getMetaProperty (bridgeImpl, "skip_usage_notice")) != 0;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridge_open (mamaBridge bridgeImpl) {
    mama_log(MAMA_LOG_LEVEL_NORMAL, "Bridge open requested");

    if (bridgeImpl == 0) {
        return MAMA_STATUS_NULL_ARG;
    }

    mamaBridgeImpl* bridge  = (mamaBridgeImpl*) bridgeImpl;
    mama_status status = mamaQueue_create (&bridge->mDefaultEventQueue, bridgeImpl);
    if (status != MAMA_STATUS_OK) {
        mama_log (MAMA_LOG_LEVEL_ERROR,
                  "ybtrepBridge_open: Failed to create default queue: %s",
                  mamaStatus_stringForStatus (status));
        return status;
    }

    if(! g_skipUsageNotice) {
        mama_log(MAMA_LOG_LEVEL_WARN, "*** ATTENTION! This bridge is designed to run in \"sequential mode\".\n"
            "This means that in order to use bridge functionality user process shall call mamaQueue_timedDispatch or mamaQueue_dispatchEvent in tight loop after the bridge is started.");
    }

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridge_close (mamaBridge bridgeImpl) {
    mama_log(MAMA_LOG_LEVEL_NORMAL, "Bridge close requested");
    (void) bridgeImpl;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridge_start (mamaQueue defaultEventQueue) {
    mama_log(MAMA_LOG_LEVEL_NORMAL, "Bridge start requested");

    return ybtrepBridgeMamaQueue_startDispatch(defaultEventQueue);
}

mama_status ybtrepBridge_stop (mamaQueue defaultEventQueue) {
    mama_log(MAMA_LOG_LEVEL_NORMAL, "Bridge stop requested");
    return mamaQueue_stopDispatch (defaultEventQueue);;
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

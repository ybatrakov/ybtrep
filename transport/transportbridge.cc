#include "transportbridge.h"

mama_status ybtrepBridge_init (mamaBridge bridgeImpl) {
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
    return nullptr;
}

const char* ybtrepBridge_getName () {
    return nullptr;
}

mama_status ybtrepBridge_getDefaultPayloadId (char ***name, char **id) {
    (void) name;
    (void) id;
    return MAMA_STATUS_OK;
}

#include "queue.h"

mama_status ybtrepBridgeMamaQueue_create (queueBridge* queue, mamaQueue parent) {
    (void) queue;
    (void) parent;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_create_usingNative (queueBridge*, mamaQueue, void*) {
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaQueue_destroy (queueBridge queue) {
    (void) queue;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_getEventCount (queueBridge queue, size_t* count) {
    (void) queue;
    (void) count;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_dispatch (queueBridge queue) {
    (void) queue;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_timedDispatch (queueBridge queue, uint64_t timeout) {
    (void) queue;
    (void) timeout;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_dispatchEvent (queueBridge queue) {
    (void) queue;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_enqueueEvent (queueBridge queue) {
    (void) queue;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_stopDispatch (queueBridge queue) {
    (void) queue;
    return MAMA_STATUS_OK;
}

mama_status  ybtrepBridgeMamaQueue_setEnqueueCallback (queueBridge queue, mamaQueueEnqueueCB callback, void* closure) {
    (void) queue;
    (void) callback;
    (void) closure;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_removeEnqueueCallback (queueBridge queue) {
    (void) queue;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_getNativeHandle (queueBridge, void**) {
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaQueue_setHighWatermark (queueBridge queue, size_t highWatermark) {
    (void) queue;
    (void) highWatermark;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_setLowWatermark (queueBridge queue, size_t lowWatermark) {
    (void) queue;
    (void) lowWatermark;
    return MAMA_STATUS_OK;
}

#include "queue.h"
#include "QueueImpl.h"

#define GET_NOT_NULL(queue, bridgeQueue)       \
    Queue* queue = Queue::get(bridgeQueue);    \
    if(queue == nullptr) {                     \
        return MAMA_STATUS_NULL_ARG;           \
    }

mama_status ybtrepBridgeMamaQueue_create (queueBridge* queue, mamaQueue parent) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaQueue_create(%p)", parent);

    Queue* res = new Queue();
    res->parent = parent;

    *queue = reinterpret_cast<queueBridge>(res);
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaQueue_create: created %p", res);
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_create_usingNative (queueBridge*, mamaQueue, void*) {
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaQueue_destroy (queueBridge q) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaQueue_destroy(%p)", q);

    GET_NOT_NULL(queue, q);
    delete queue;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_getEventCount (queueBridge q, size_t* count) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaQueue_getEventCount(%p)", q);
    (void) count;
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaQueue_dispatch (queueBridge q) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaQueue_dispatch(%p)", q);

    // We don't implement this function because of bridge design. Instead of calling mamaQueue_dispatch()
    // call mamaQueue_timedDispatch or mamaQueue_dispatchEvent in tight loop
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaQueue_timedDispatch (queueBridge q, uint64_t timeout) {
    GET_NOT_NULL(queue, q);

    if(!queue->dispatching) {
        return MAMA_STATUS_NOT_INITIALISED;
    }

    queue->dispatch(timeout);

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_dispatchEvent (queueBridge q) {
    GET_NOT_NULL(queue, q);

    if(!queue->dispatching) {
        return MAMA_STATUS_NOT_INITIALISED;
    }

    queue->dispatch(0);

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_enqueueEvent (queueBridge queue, mamaQueueEventCB callback, void* closure) {
    (void) queue;
    (void) callback;
    (void) closure;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_startDispatch (mamaQueue q) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaQueue_startDispatch(%p)", q);

    GET_NOT_NULL(queue, q);
    queue->dispatching = true;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_stopDispatch (queueBridge qb) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaQueue_stopDispatch(%p)", qb);

    GET_NOT_NULL(queue, qb);
    queue->dispatching = false;

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

mama_status ybtrepBridgeMamaQueue_getNativeHandle (queueBridge q, void** nativeRes) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaQueue_getNativeHandle(%p)", q);

    GET_NOT_NULL(queue, q);

    if(nativeRes == 0) {
        return MAMA_STATUS_NULL_ARG;
    }

    *nativeRes = queue;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaQueue_setHighWatermark (queueBridge queue, size_t highWatermark) {
    (void) queue;
    (void) highWatermark;
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaQueue_setLowWatermark (queueBridge queue, size_t lowWatermark) {
    (void) queue;
    (void) lowWatermark;
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

#pragma once

#include <mama/mama.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_create (queueBridge* queue, mamaQueue parent);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_create_usingNative (queueBridge*, mamaQueue, void*);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_destroy (queueBridge queue);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_getEventCount (queueBridge queue, size_t* count);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_dispatch (queueBridge queue);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_timedDispatch (queueBridge queue, uint64_t timeout);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_dispatchEvent (queueBridge queue);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_enqueueEvent (queueBridge queue);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_stopDispatch (queueBridge queue);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_setEnqueueCallback (queueBridge queue, mamaQueueEnqueueCB callback, void* closure);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_removeEnqueueCallback (queueBridge queue);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_getNativeHandle (queueBridge, void**);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_setHighWatermark (queueBridge queue, size_t highWatermark);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaQueue_setLowWatermark (queueBridge queue, size_t lowWatermark);

#ifdef __cplusplus
}
#endif

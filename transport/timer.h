#pragma once

#include <mama/mama.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTimer_create(timerBridge* result,
                             void*        nativeQueueHandle,
                             mamaTimerCb  action,
                             mamaTimerCb  onTimerDestroyed,
                             double       interval,
                             mamaTimer    parent,
                             void*        closure);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTimer_destroy(timerBridge timer);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTimer_reset(timerBridge timer);


MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTimer_setInterval(timerBridge timer,
                                  mama_f64_t interval);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTimer_getInterval(timerBridge timer,
                                  mama_f64_t* interval);

#ifdef __cplusplus
}
#endif

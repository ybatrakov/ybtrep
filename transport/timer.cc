#include "timer.h"

mama_status ybtrepBridgeMamaTimer_create(timerBridge* result,
                                         void*        nativeQueueHandle,
                                         mamaTimerCb  action,
                                         mamaTimerCb  onTimerDestroyed,
                                         double       interval,
                                         mamaTimer    parent,
                                         void*        closure)
{
    (void) result;
    (void) nativeQueueHandle;
    (void) action;
    (void) onTimerDestroyed;
    (void) interval;
    (void) parent;
    (void) closure;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaTimer_destroy(timerBridge timer) {
    (void) timer;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaTimer_reset(timerBridge timer) {
    (void) timer;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaTimer_setInterval(timerBridge timer, mama_f64_t interval) {
    (void) timer;
    (void) interval;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaTimer_getInterval(timerBridge timer, mama_f64_t* interval) {
    (void) timer;
    (void) interval;
    return MAMA_STATUS_OK;
}

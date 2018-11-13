#include "timer.h"
#include "TimerImpl.h"
#include "Utils.h"

mama_status ybtrepBridgeMamaTimer_create(timerBridge* result,
                                         void*        nativeQueueHandle,
                                         mamaTimerCb  action,
                                         mamaTimerCb  onTimerDestroyed,
                                         double       interval,
                                         mamaTimer    parent,
                                         void*        closure)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaTimer_create(%p, %p, %f)",
             parent, nativeQueueHandle, interval);

    if(result == nullptr || action == nullptr) {
        return MAMA_STATUS_NULL_ARG;
    }

    Queue* queue = Utils::getQueue(nativeQueueHandle);
    if(queue == nullptr) {
        mama_log(MAMA_LOG_LEVEL_ERROR, "ybtrepBridgeMamaTimer_create: Could not get queue");
        return MAMA_STATUS_PLATFORM;
    }

    Timer* ret = queue->createTimer(interval, action, onTimerDestroyed, parent, closure, queue);
    queue->scheduleTimer(ret);

    *result = reinterpret_cast<timerBridge>(ret);

    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaTimer_create created %p", ret);

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaTimer_destroy(timerBridge tb) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaTimer_destroy(%p)", tb);

    Timer* timer = reinterpret_cast<Timer*>(tb);
    timer->queue->destroyTimer(timer);

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

mama_status ybtrepBridgeMamaTimer_getInterval(timerBridge tb, mama_f64_t* interval) {
    const Timer* timer = reinterpret_cast<const Timer*>(tb);
    if(timer == nullptr || interval == nullptr) {
        return MAMA_STATUS_NULL_ARG;
    }

    *interval = timer->interval;
    return MAMA_STATUS_OK;
}

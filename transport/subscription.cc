#include "subscription.h"
#include "Utils.h"

mama_status ybtrepBridgeMamaSubscription_create(subscriptionBridge* result,
                                                const char*         source,
                                                const char*         symbol,
                                                mamaTransport       tport,
                                                mamaQueue           q,
                                                mamaMsgCallbacks    callback,
                                                mamaSubscription    parent,
                                                void*               closure)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaSubscription_create(%s.%s, %p, %p, %p)",
             source, symbol, parent, tport, q);

    bool rc = Utils::addTransportToQueue(tport, q);
    if(!rc) {
        mama_log(MAMA_LOG_LEVEL_ERROR, "ybtrepBridgeMamaSubscription_create: Unable to associate transport with queue");
        return MAMA_STATUS_PLATFORM;
    }

    (void) result;
    (void) callback;
    (void) closure;

    return MAMA_STATUS_OK;
}

mama_status
ybtrepBridgeMamaSubscription_createWildCard(subscriptionBridge*     result,
                                            const char*             source,
                                            const char*             symbol,
                                            mamaTransport           transport,
                                            mamaQueue               queue,
                                            mamaMsgCallbacks        callback,
                                            mamaSubscription        subscription,
                                            void*                   closure)
{
    (void) result;
    (void) source;
    (void) symbol;
    (void) transport;
    (void) queue;
    (void) callback;
    (void) subscription;
    (void) closure;

    return MAMA_STATUS_OK;
}

mama_status
ybtrepBridgeMamaSubscription_mute(subscriptionBridge subscription) {
    (void) subscription;
    return MAMA_STATUS_OK;
}

mama_status
ybtrepBridgeMamaSubscription_destroy(subscriptionBridge subscription) {
    (void) subscription;
    return MAMA_STATUS_OK;
}

int
ybtrepBridgeMamaSubscription_isValid(subscriptionBridge subscription) {
    (void) subscription;
    return 1;
}

int
ybtrepBridgeMamaSubscription_hasWildcards(subscriptionBridge subscription) {
    (void) subscription;
    return 0;
}

mama_status
ybtrepBridgeMamaSubscription_getPlatformError(subscriptionBridge subscription,
                                              void** error)
{
    (void) subscription;
    (void) error;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaSubscription_setTopicClosure(subscriptionBridge subscription,
                                                         void* closure)
{
    (void) subscription;
    (void) closure;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaSubscription_muteCurrentTopic(subscriptionBridge subscription) {
    (void) subscription;
    return MAMA_STATUS_OK;
}

int ybtrepBridgeMamaSubscription_isTportDisconnected(subscriptionBridge subscription) {
    (void) subscription;
    return 0;
}

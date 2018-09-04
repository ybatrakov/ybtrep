#include "subscription.h"

mama_status ybtrepBridgeMamaSubscription_create(subscriptionBridge* result,
                                                const char*         source,
                                                const char*         symbol,
                                                mamaTransport       transport,
                                                mamaQueue           queue,
                                                mamaMsgCallbacks    callback,
                                                mamaSubscription    subscription,
                                                void*               closure)
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

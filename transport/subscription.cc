#include "subscription.h"
#include "Utils.h"
#include "SubscriptionImpl.h"

#define GET_NOT_NULL(sub, bridgeSub)                    \
    Subscription* sub = Subscription::get(bridgeSub);   \
    if(sub == nullptr) {                                \
        return MAMA_STATUS_NULL_ARG;                    \
    }


mama_status ybtrepBridgeMamaSubscription_create(subscriptionBridge* result,
                                                const char*         source,
                                                const char*         symbol,
                                                mamaTransport       tport,
                                                mamaQueue           q,
                                                mamaMsgCallbacks    callbacks,
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

    Subscription* sub = new Subscription();
    sub->source = source;
    sub->symbol = symbol;
    sub->transport = Transport::get(tport);
    sub->callbacks = callbacks;
    sub->parent = parent;
    sub->callbackClosure = closure;

    *result = reinterpret_cast<subscriptionBridge>(sub);

    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaSubscription_create: created %p", sub);

    return MAMA_STATUS_OK;
}

mama_status
ybtrepBridgeMamaSubscription_createWildCard(subscriptionBridge*     result,
                                            const char*             source,
                                            const char*             symbol,
                                            mamaTransport           transport,
                                            mamaQueue               queue,
                                            mamaMsgCallbacks        callback,
                                            mamaSubscription        parent,
                                            void*                   closure)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaSubscription_createWildCard(%s.%s, %p, %p, %p)",
             source, symbol, parent, transport, queue);

    (void) result;
    (void) callback;
    (void) closure;

    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status
ybtrepBridgeMamaSubscription_mute(subscriptionBridge subscription) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaSubscription_mute(%p)", subscription);
    GET_NOT_NULL(sub, subscription);

    sub->active = false;

    return MAMA_STATUS_OK;
}

mama_status
ybtrepBridgeMamaSubscription_destroy(subscriptionBridge subscription) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaSubscription_destroy(%p)", subscription);
    GET_NOT_NULL(sub, subscription);

    Utils::deleteWithCallback(sub);

    return MAMA_STATUS_OK;
}

int
ybtrepBridgeMamaSubscription_isValid(subscriptionBridge subscription) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaSubscription_isValid(%p)", subscription);
    return 1;
}

int
ybtrepBridgeMamaSubscription_hasWildcards(subscriptionBridge subscription) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaSubscription_hasWildcards(%p)", subscription);
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

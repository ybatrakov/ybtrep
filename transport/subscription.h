#pragma once

#include <mama/mama.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaSubscription_create(subscriptionBridge* result,
                                    const char*         source,
                                    const char*         symbol,
                                    mamaTransport       transport,
                                    mamaQueue           queue,
                                    mamaMsgCallbacks    callback,
                                    mamaSubscription    subscription,
                                    void*               closure);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaSubscription_createWildCard(subscriptionBridge*     result,
                                            const char*             source,
                                            const char*             symbol,
                                            mamaTransport           transport,
                                            mamaQueue               queue,
                                            mamaMsgCallbacks        callback,
                                            mamaSubscription        subscription,
                                            void*                   closure);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaSubscription_mute(subscriptionBridge subscription);

MAMAExpBridgeDLL  mama_status
ybtrepBridgeMamaSubscription_destroy(subscriptionBridge subscription);

MAMAExpBridgeDLL int
ybtrepBridgeMamaSubscription_isValid(subscriptionBridge subscription);

MAMAExpBridgeDLL int
ybtrepBridgeMamaSubscription_hasWildcards(subscriptionBridge subscription);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaSubscription_getPlatformError(subscriptionBridge subscription,
                                              void** error);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaSubscription_setTopicClosure(subscriptionBridge subscription,
                                             void* closure);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaSubscription_muteCurrentTopic(subscriptionBridge subscription);

MAMAExpBridgeDLL int
ybtrepBridgeMamaSubscription_isTportDisconnected(subscriptionBridge subscription);

#ifdef __cplusplus
}
#endif

#pragma once

#include <mama/mama.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaPublisher_createByIndex(publisherBridge*  result,
                                        mamaTransport     tport,
                                        int               tportIndex,
                                        const char*       topic,
                                        const char*       source,
                                        const char*       root,
                                        mamaPublisher     parent);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaPublisher_destroy(publisherBridge publisher);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaPublisher_send(publisherBridge publisher,
                               mamaMsg msg);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaPublisher_sendReplyToInbox(publisherBridge publisher,
                                           mamaMsg         request,
                                           mamaMsg         reply);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaPublisher_sendReplyToInboxHandle(publisherBridge publisher,
                                                 void*           wmwReply,
                                                 mamaMsg         reply);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaPublisher_sendFromInboxByIndex(publisherBridge   publisher,
                                               int               tportIndex,
                                               mamaInbox         inbox,
                                               mamaMsg           msg);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaPublisher_sendFromInbox(publisherBridge publisher,
                                        mamaInbox       inbox,
                                        mamaMsg         msg);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaPublisher_setUserCallbacks(publisherBridge         publisher,
                                           mamaQueue               queue,
                                           mamaPublisherCallbacks* cb,
                                           void*                   closure);

#ifdef __cplusplus
}
#endif

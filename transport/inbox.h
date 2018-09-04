#pragma once

#include <mama/mama.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaInbox_create(inboxBridge*             result,
                             mamaTransport            tport,
                             mamaQueue                queue,
                             mamaInboxMsgCallback     msgCB,
                             mamaInboxErrorCallback   errorCB,
                             mamaInboxDestroyCallback onInboxDestroyed,
                             void*                    closure,
                             mamaInbox                parent);


MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaInbox_createByIndex(inboxBridge*             result,
                                    mamaTransport            tport,
                                    int                      tportIndex,
                                    mamaQueue                queue,
                                    mamaInboxMsgCallback     msgCB,
                                    mamaInboxErrorCallback   errorCB,
                                    mamaInboxDestroyCallback onInboxDestroyed,
                                    void*                    closure,
                                    mamaInbox                parent);


MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaInbox_destroy(inboxBridge inbox);

#ifdef __cplusplus
}
#endif

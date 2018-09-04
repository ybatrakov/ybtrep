#include "inbox.h"

mama_status ybtrepBridgeMamaInbox_create(inboxBridge*             result,
                                         mamaTransport            tport,
                                         mamaQueue                queue,
                                         mamaInboxMsgCallback     msgCB,
                                         mamaInboxErrorCallback   errorCB,
                                         mamaInboxDestroyCallback onInboxDestroyed,
                                         void*                    closure,
                                         mamaInbox                parent)
{
    (void) result;
    (void) tport;
    (void) queue;
    (void) msgCB;
    (void) errorCB;
    (void) onInboxDestroyed;
    (void) closure;
    (void) parent;

    return MAMA_STATUS_OK;
}


mama_status ybtrepBridgeMamaInbox_createByIndex(inboxBridge*             result,
                                                mamaTransport            tport,
                                                int                      tportIndex,
                                                mamaQueue                queue,
                                                mamaInboxMsgCallback     msgCB,
                                                mamaInboxErrorCallback   errorCB,
                                                mamaInboxDestroyCallback onInboxDestroyed,
                                                void*                    closure,
                                                mamaInbox                parent)
{
    (void) result;
    (void) tport;
    (void) tportIndex;
    (void) queue;
    (void) msgCB;
    (void) errorCB;
    (void) onInboxDestroyed;
    (void) closure;
    (void) parent;

    return MAMA_STATUS_OK;
}


mama_status
ybtrepBridgeMamaInbox_destroy(inboxBridge inbox) {
    (void) inbox;

    return MAMA_STATUS_OK;
}

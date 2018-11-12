#include "Utils.h"

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
    return ybtrepBridgeMamaInbox_createByIndex(result,
                                               tport,
                                               0,
                                               queue,
                                               msgCB,
                                               errorCB,
                                               onInboxDestroyed,
                                               closure,
                                               parent);
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
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaInbox_create(%p, %p, %p)", parent, tport, queue);

    bool rc = Utils::addTransportToQueue(tport, queue);
    if(!rc) {
        mama_log(MAMA_LOG_LEVEL_ERROR, "ybtrepBridgeMamaInbox_create: Unable to associate transport with queue");
        return MAMA_STATUS_PLATFORM;
    }

    (void) result;
    (void) tportIndex;
    (void) msgCB;
    (void) errorCB;
    (void) onInboxDestroyed;
    (void) closure;

    return MAMA_STATUS_OK;
}


mama_status
ybtrepBridgeMamaInbox_destroy(inboxBridge inbox) {
    (void) inbox;

    return MAMA_STATUS_OK;
}

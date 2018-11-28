#include "inbox.h"
#include "QueueImpl.h"
#include "Utils.h"

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

    Inbox* inbox = new Inbox();
    inbox->callbacks.onMsg = msgCB;
    inbox->callbacks.onError = errorCB;
    inbox->callbacks.onDestroy = onInboxDestroyed;
    inbox->parent = parent;
    inbox->callbackClosure = closure;

    *result = reinterpret_cast<inboxBridge>(inbox);

    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaInbox_create: created %p", inbox);

    (void) tportIndex;

    return MAMA_STATUS_OK;
}


mama_status
ybtrepBridgeMamaInbox_destroy(inboxBridge ib) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaInbox_destroy(%p, %p, %p)", ib);

    Inbox* inbox = Inbox::get(ib);
    if(inbox == nullptr) {
        return MAMA_STATUS_NULL_ARG;
    }

    Utils::deleteWithCallback(inbox);

    return MAMA_STATUS_OK;
}

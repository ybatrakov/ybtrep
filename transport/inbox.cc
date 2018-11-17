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
    inbox->onMsg = msgCB;
    inbox->onError = errorCB;
    inbox->onDestroyed = onInboxDestroyed;
    inbox->parent = parent;
    inbox->closure = closure;

    *result = reinterpret_cast<inboxBridge>(inbox);

    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaInbox_create: created %p", inbox);

    (void) tportIndex;

    return MAMA_STATUS_OK;
}


mama_status
ybtrepBridgeMamaInbox_destroy(inboxBridge ib) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaInbox_destroy(%p, %p, %p)", ib);

    Inbox* inbox = reinterpret_cast<Inbox*>(ib);

    mamaInboxDestroyCallback onDestroyed = inbox->onDestroyed;
    void* closure = inbox->closure;
    mamaInbox parent = inbox->parent;

    delete inbox;

    if(onDestroyed) {
        onDestroyed(parent, closure);
    }

    return MAMA_STATUS_OK;
}

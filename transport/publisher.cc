#include "publisher.h"

mama_status ybtrepBridgeMamaPublisher_createByIndex(publisherBridge*  result,
                                                    mamaTransport     tport,
                                                    int               tportIndex,
                                                    const char*       topic,
                                                    const char*       source,
                                                    const char*       root,
                                                    mamaPublisher     parent)
{
    (void) result;
    (void) tport;
    (void) tportIndex;
    (void) topic;
    (void) source;
    (void) root;
    (void) parent;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaPublisher_destroy(publisherBridge publisher) {
    (void) publisher;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaPublisher_send(publisherBridge publisher, mamaMsg msg) {
    (void) publisher;
    (void) msg;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaPublisher_sendReplyToInbox(publisherBridge publisher,
                                                       mamaMsg         request,
                                                       mamaMsg         reply)
{
    (void) publisher;
    (void) request;
    (void) reply;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaPublisher_sendReplyToInboxHandle(publisherBridge publisher,
                                                             void*           wmwReply,
                                                             mamaMsg         reply)
{
    (void) publisher;
    (void) wmwReply;
    (void) reply;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaPublisher_sendFromInboxByIndex(publisherBridge   publisher,
                                                           int               tportIndex,
                                                           mamaInbox         inbox,
                                                           mamaMsg           msg)
{
    (void) publisher;
    (void) tportIndex;
    (void) inbox;
    (void) msg;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaPublisher_sendFromInbox(publisherBridge publisher,
                                                    mamaInbox       inbox,
                                                    mamaMsg         msg)
{
    (void) publisher;
    (void) inbox;
    (void) msg;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaPublisher_setUserCallbacks(publisherBridge         publisher,
                                                       mamaQueue               queue,
                                                       mamaPublisherCallbacks* cb,
                                                       void*                   closure)
{
    (void) publisher;
    (void) queue;
    (void) cb;
    (void) closure;

    return MAMA_STATUS_OK;
}

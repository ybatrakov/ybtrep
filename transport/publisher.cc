#include "publisher.h"
#include "PublisherImpl.h"

#define GET_NOT_NULL(pub, bridgePub)                            \
    Publisher* pub = reinterpret_cast<Publisher*>(bridgePub);   \
    if(pub == nullptr) {                                        \
        return MAMA_STATUS_NULL_ARG;                            \
    }

mama_status ybtrepBridgeMamaPublisher_createByIndex(publisherBridge*  result,
                                                    mamaTransport     tport,
                                                    int               tportIndex,
                                                    const char*       topic,
                                                    const char*       source,
                                                    const char*       root,
                                                    mamaPublisher     parent)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaPublisher_createByIndex(%s/%s/%s, %p, %p)",
             root, source, topic, parent, tport);

    Publisher* pub = new Publisher();
    pub->topic  = topic;
    pub->source = source;
    pub->root   = root;
    pub->parent = parent;
    pub->transport = Transport::get(tport);

    *result = reinterpret_cast<publisherBridge>(pub);

    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaPublisher_createByIndex: created %p", pub);

    (void) tportIndex;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaPublisher_destroy(publisherBridge publisher) {
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaPublisher_destroy(%p)", publisher);
    GET_NOT_NULL(pub, publisher);

    mama_publisherOnDestroyCb cb = pub->callbacks.onDestroy;
    mamaPublisher parent = pub->parent;
    void* closure = pub->callbackClosure;

    delete pub;

    if(cb != nullptr) {
        cb(parent, closure);
    }

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
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaPublisher_sendFromInboxByIndex(%p, %p, %p)", publisher, inbox, msg);
    GET_NOT_NULL(pub, publisher);

    if(pub->topic == "DATA_DICT") {
        pub->transport->sendDictionaryRequest(inbox, msg);
        return MAMA_STATUS_OK;
    }

    mama_log(MAMA_LOG_LEVEL_ERROR, "Unsupported request type");

    (void) tportIndex;

    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaPublisher_sendFromInbox(publisherBridge publisher,
                                                    mamaInbox       inbox,
                                                    mamaMsg         msg)
{
    return ybtrepBridgeMamaPublisher_sendFromInboxByIndex(publisher, 0, inbox, msg);
}

mama_status ybtrepBridgeMamaPublisher_setUserCallbacks(publisherBridge         publisher,
                                                       mamaQueue               queue,
                                                       mamaPublisherCallbacks* cb,
                                                       void*                   closure)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaPublisher_setUserCallbacks(%p, %p)", publisher, closure);
    GET_NOT_NULL(pub, publisher);

    pub->callbacks = *cb;
    pub->callbackClosure = closure;

    (void) queue;

    return MAMA_STATUS_OK;
}

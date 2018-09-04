#include "msg.h"

mama_status ybtrepBridgeMamaMsg_create(msgBridge* result, mamaMsg parent) {
    (void) result;
    (void) parent;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaMsg_destroy(msgBridge msg, int destroyMsg) {
    (void) msg;
    (void) destroyMsg;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaMsg_destroyMiddlewareMsg(msgBridge msg) {
    (void) msg;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaMsg_detach(msgBridge msg) {
    (void) msg;

    return MAMA_STATUS_OK;
}

int ybtrepBridgeMamaMsg_isFromInbox(msgBridge msg) {
    (void) msg;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaMsg_getPlatformError(msgBridge msg, void** error) {
    (void) msg;
    (void) error;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaMsg_setSendSubject(msgBridge   msg,
                                               const char* symbol,
                                               const char* subject)
{
    (void) msg;
    (void) symbol;
    (void) subject;

    return MAMA_STATUS_OK;
}


mama_status ybtrepBridgeMamaMsg_getNativeHandle(msgBridge msg, void** result) {
    (void) msg;
    (void) result;

    return MAMA_STATUS_OK;
}


mama_status ybtrepBridgeMamaMsg_duplicateReplyHandle(msgBridge msg, void** result) {
    (void) msg;
    (void) result;

    return MAMA_STATUS_OK;
}


mama_status ybtrepBridgeMamaMsg_copyReplyHandle(void* src, void** dest) {
    (void) src;
    (void) dest;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaMsgImpl_setReplyHandle(msgBridge msg, void* handle) {
    (void) msg;
    (void) handle;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaMsgImpl_setReplyHandleAndIncrement(msgBridge msg, void* handle) {
    (void) msg;
    (void) handle;

    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaMsg_destroyReplyHandle(void* handle) {
    (void) handle;

    return MAMA_STATUS_OK;
}

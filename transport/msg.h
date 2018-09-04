#pragma once

#include <mama/mama.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsg_create(msgBridge* result,
                           mamaMsg parent);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsg_destroy(msgBridge msg,
                            int destroyMsg);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsg_destroyMiddlewareMsg(msgBridge msg);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsg_detach(msgBridge msg);

MAMAExpBridgeDLL int
ybtrepBridgeMamaMsg_isFromInbox(msgBridge msg);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsg_getPlatformError(msgBridge msg,
                                     void** error);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsg_setSendSubject(msgBridge   msg,
                                   const char* symbol,
                                   const char* subject);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsg_getNativeHandle(msgBridge msg,
                                    void** result);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsg_duplicateReplyHandle(msgBridge msg,
                                         void** result);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsg_copyReplyHandle(void* src,
                                    void** dest);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsgImpl_setReplyHandle(msgBridge msg,
                                       void* handle);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsgImpl_setReplyHandleAndIncrement(msgBridge msg,
                                                   void* handle);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaMsg_destroyReplyHandle(void* handle);

#ifdef __cplusplus
}
#endif

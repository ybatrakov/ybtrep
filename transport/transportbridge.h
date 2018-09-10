#pragma once

#include <mama/mama.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepBridge_init (mamaBridge bridgeImpl);

MAMAExpBridgeDLL mama_status
ybtrepBridge_open (mamaBridge bridgeImpl);

MAMAExpBridgeDLL mama_status
ybtrepBridge_close (mamaBridge bridgeImpl);

MAMAExpBridgeDLL mama_status
ybtrepBridge_start (mamaQueue defaultEventQueue);

MAMAExpBridgeDLL mama_status
ybtrepBridge_stop (mamaQueue defaultEventQueue);

MAMAExpBridgeDLL const char*
ybtrepBridge_getVersion (void);

MAMAExpBridgeDLL const char*
ybtrepBridge_getName (void);

MAMAExpBridgeDLL mama_status
ybtrepBridge_getDefaultPayloadId (const char ***name, const char **id);

#ifdef __cplusplus
}
#endif

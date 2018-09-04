#pragma once

#include <mama/mama.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_create (transportBridge* result,
                                  const char*      name,
                                  mamaTransport    parent);

MAMAExpBridgeDLL int
ybtrepBridgeMamaTransport_isValid (transportBridge transport);


MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_destroy (transportBridge transport);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_forceClientDisconnect (transportBridge*,
                                                 int,
                                                 const char*,
                                                 uint16_t);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_findConnection (transportBridge*,
                                          int,
                                          mamaConnection*,
                                          const char*,
                                          uint16_t);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_getAllConnections (transportBridge*,
                                             int,
                                             mamaConnection**,
                                             uint32_t*);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_getAllConnectionsForTopic (transportBridge*,
                                                     int,
                                                     const char*,
                                                     mamaConnection**,
                                                     uint32_t*);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_requestConflation (transportBridge*, int);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_requestEndConflation (transportBridge*, int);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_getAllServerConnections (transportBridge*,
                                                   int,
                                                   mamaServerConnection**,
                                                   uint32_t*);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_freeAllServerConnections (transportBridge*,
                                                    int,
                                                    mamaServerConnection*,
                                                    uint32_t);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_freeAllConnections (transportBridge*,
                                              int,
                                              mamaConnection*,
                                              uint32_t);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_getNumLoadBalanceAttributes (const char* name, int* num);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_getLoadBalanceScheme (const char* name, tportLbScheme* scheme);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_getNativeTransport (transportBridge, void**);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_getNativeTransportNamingCtx (transportBridge, void**);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_getLoadBalanceSharedObjectName (const char*,
                                                          const char**);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_sendMsgToConnection (transportBridge,
                                               mamaConnection,
                                               mamaMsg,
                                               const char*);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_isConnectionIntercepted (mamaConnection,
                                                   uint8_t*);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_installConnectConflateMgr (transportBridge,
                                                     mamaConflationManager,
                                                     mamaConnection,
                                                     conflateProcessCb,
                                                     conflateGetMsgCb);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_uninstallConnectConflateMgr (transportBridge,
                                                       mamaConflationManager,
                                                       mamaConnection);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaTransport_startConnectionConflation (transportBridge,
                                                     mamaConflationManager,
                                                     mamaConnection);

#ifdef __cplusplus
}
#endif

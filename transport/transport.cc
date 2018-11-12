#include "transport.h"
#include "TransportImpl.h"

mama_status ybtrepBridgeMamaTransport_create (transportBridge* result,
                                              const char*      name,
                                              mamaTransport    parent)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaTransport_create(%s, %p)", name, parent);

    Transport* res = new Transport();
    res->name.assign(name);
    res->parent = parent;
    *result = reinterpret_cast<transportBridge>(res);

    mama_log(MAMA_LOG_LEVEL_FINEST, "ybtrepBridgeMamaTransport_create returned %p", res);

    return MAMA_STATUS_OK;
}

int ybtrepBridgeMamaTransport_isValid (transportBridge transport) {
    (void) transport;
    return 1;
}

mama_status ybtrepBridgeMamaTransport_destroy (transportBridge transport) {
    (void) transport;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaTransport_forceClientDisconnect (transportBridge*,
                                                             int,
                                                             const char*,
                                                             uint16_t)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_findConnection (transportBridge*,
                                                      int,
                                                      mamaConnection*,
                                                      const char*,
                                                      uint16_t)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_getAllConnections (transportBridge*,
                                                       int,
                                                       mamaConnection**,
                                                       uint32_t*)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_getAllConnectionsForTopic (transportBridge*,
                                                               int,
                                                               const char*,
                                                               mamaConnection**,
                                                               uint32_t*)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_getAllServerConnections (transportBridge*,
                                                               int,
                                                               mamaServerConnection**,
                                                               uint32_t*)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_freeAllServerConnections (transportBridge*,
                                                                int,
                                                                mamaServerConnection*,
                                                                uint32_t)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_freeAllConnections (transportBridge*,
                                                          int,
                                                          mamaConnection*,
                                                          uint32_t)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_getNumLoadBalanceAttributes (const char* name, int* num)
{
    if (num == nullptr) {
        return MAMA_STATUS_NULL_ARG;
    }
    *num = 0;
    (void) name;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaTransport_getLoadBalanceScheme (const char* name, tportLbScheme* scheme) {
    if (scheme == nullptr) {
        return MAMA_STATUS_NULL_ARG;
    }

    *scheme = TPORT_LB_SCHEME_STATIC;
    (void) name;
    return MAMA_STATUS_OK;
}

mama_status ybtrepBridgeMamaTransport_getLoadBalanceSharedObjectName (const char*,
                                                                      const char**)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_sendMsgToConnection (transportBridge,
                                                           mamaConnection,
                                                           mamaMsg,
                                                           const char*)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_isConnectionIntercepted (mamaConnection,
                                                               uint8_t*)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_installConnectConflateMgr (transportBridge,
                                                                 mamaConflationManager,
                                                                 mamaConnection,
                                                                 conflateProcessCb,
                                                                 conflateGetMsgCb)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_uninstallConnectConflateMgr (transportBridge,
                                                                   mamaConflationManager,
                                                                   mamaConnection)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_startConnectionConflation (transportBridge,
                                                                 mamaConflationManager,
                                                                 mamaConnection)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_requestConflation (transportBridge*, int)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_requestEndConflation (transportBridge*, int)
{
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_getNativeTransport (transportBridge, void**) {
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status ybtrepBridgeMamaTransport_getNativeTransportNamingCtx (transportBridge, void**) {
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

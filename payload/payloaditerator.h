#pragma once

#include <mama/mama.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepmsgPayloadIter_create(msgPayloadIter*   iter,
                            msgPayload        msg);

MAMAExpBridgeDLL msgFieldPayload
ybtrepmsgPayloadIter_next(msgPayloadIter      iter,
                          msgFieldPayload     field,
                          msgPayload          msg);

MAMAExpBridgeDLL mama_bool_t
ybtrepmsgPayloadIter_hasNext(msgPayloadIter   iter,
                             msgPayload       msg);

MAMAExpBridgeDLL msgFieldPayload
ybtrepmsgPayloadIter_begin(msgPayloadIter     iter,
                           msgFieldPayload    field,
                           msgPayload         msg);

MAMAExpBridgeDLL msgFieldPayload
ybtrepmsgPayloadIter_end(msgPayloadIter       iter,
                         msgPayload           msg);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayloadIter_associate(msgPayloadIter iter,
                               msgPayload     msg);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayloadIter_destroy(msgPayloadIter   iter);


#ifdef __cplusplus
}
#endif

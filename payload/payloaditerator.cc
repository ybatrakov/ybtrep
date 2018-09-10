#include "payloaditerator.h"

mama_status
ybtrepmsgPayloadIter_create(msgPayloadIter*   iter,
                            msgPayload        msg)
{
    (void) iter;
    (void) msg;
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

msgFieldPayload
ybtrepmsgPayloadIter_next(msgPayloadIter      iter,
                          msgFieldPayload     field,
                          msgPayload          msg)
{
    (void) iter;
    (void) field;
    (void) msg;
    return nullptr;
}

mama_bool_t
ybtrepmsgPayloadIter_hasNext(msgPayloadIter   iter,
                             msgPayload       msg)
{
    (void) iter;
    (void) msg;
    return 0;
}

msgFieldPayload
ybtrepmsgPayloadIter_begin(msgPayloadIter     iter,
                           msgFieldPayload    field,
                           msgPayload         msg)
{
    (void) iter;
    (void) field;
    (void) msg;
    return nullptr;
}

msgFieldPayload
ybtrepmsgPayloadIter_end(msgPayloadIter       iter,
                         msgPayload           msg)
{
    (void) iter;
    (void) msg;
    return nullptr;
}

mama_status
ybtrepmsgPayloadIter_associate(msgPayloadIter iter,
                               msgPayload     msg)
{
    (void) iter;
    (void) msg;
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status
ybtrepmsgPayloadIter_destroy(msgPayloadIter   iter)
{
    (void) iter;
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

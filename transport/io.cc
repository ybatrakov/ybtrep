#include "io.h"

mama_status ybtrepBridgeMamaIo_create(ioBridge*  result,
                                      void*      nativeQueueHandle,
                                      uint32_t   descriptor,
                                      mamaIoCb   action,
                                      mamaIoType ioType,
                                      mamaIo     parent,
                                      void*      closure)
{
    (void) result;
    (void) nativeQueueHandle;
    (void) descriptor;
    (void) action;
    (void) ioType;
    (void) parent;
    (void) closure;

    return MAMA_STATUS_OK;
}

mama_status
ybtrepBridgeMamaIo_getDescriptor(ioBridge io, uint32_t* result) {
    (void) io;
    (void) result;

    return MAMA_STATUS_OK;
}

mama_status
ybtrepBridgeMamaIo_destroy(ioBridge io) {
    (void) io;

    return MAMA_STATUS_OK;
}

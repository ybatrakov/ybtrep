#pragma once

#include <mama/mama.h>
#include <mama/io.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaIo_create(ioBridge*  result,
                          void*      nativeQueueHandle,
                          uint32_t   descriptor,
                          mamaIoCb   action,
                          mamaIoType ioType,
                          mamaIo     parent,
                          void*      closure);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaIo_getDescriptor(ioBridge io,
                                 uint32_t* result);

MAMAExpBridgeDLL mama_status
ybtrepBridgeMamaIo_destroy(ioBridge io);

#ifdef __cplusplus
}
#endif

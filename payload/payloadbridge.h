#pragma once

#include <mama/mama.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_init(mamaPayloadBridge bridge, char* identifier);

MAMAIgnoreDeprecatedOpen
MAMAExpBridgeDLL mamaPayloadType
ybtrepmsgPayload_getType(void);
MAMAIgnoreDeprecatedClose

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_create(msgPayload*         msg);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_createForTemplate(msgPayload*         msg,
                                   mamaPayloadBridge       bridge,
                                   mama_u32_t          templateId);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_copy(const msgPayload    msg,
                      msgPayload*         copy);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_clear(msgPayload msg);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_destroy(msgPayload msg);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_setParent(msgPayload    msg,
                           const mamaMsg parent);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getByteSize(msgPayload   msg,
                             mama_size_t* size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getNumFields(const msgPayload msg,
                              mama_size_t*     numFields);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getSendSubject(const msgPayload msg,
                                const char**     subject);

MAMAExpBridgeDLL const char*
ybtrepmsgPayload_toString(const msgPayload msg);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_iterateFields(const msgPayload  msg,
                               const mamaMsg     parent,
                               mamaMsgField      field,
                               mamaMsgIteratorCb cb,
                               void*             closure);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_serialize(const msgPayload msg,
                           const void**     buffer,
                           mama_size_t*     bufferLength);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_deserialize(mamaPayloadBridge payloadBridge,
                             const msgPayload  msg,
                             const void*       buffer,
                             mama_size_t       bufferLength);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_unSerialize(const msgPayload    msg,
                             const void*         buffer,
                             mama_size_t         bufferLength);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getByteBuffer(const msgPayload    msg,
                               const void**        buffer,
                               mama_size_t*        bufferLength);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_setByteBuffer(const msgPayload    msg,
                               mamaPayloadBridge   bridge,
                               const void*         buffer,
                               mama_size_t         bufferLength);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_createFromByteBuffer(msgPayload*         msg,
                                      mamaPayloadBridge   bridge,
                                      const void*         buffer,
                                      mama_size_t         bufferLength);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_apply(msgPayload       dest,
                       const msgPayload src);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getNativeMsg(const msgPayload msg,
                              void**           nativeMsg);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getFieldAsString(const msgPayload    msg,
                                  const char*         name,
                                  mama_fid_t          fid,
                                  char*               buffer,
                                  mama_size_t         len);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addBool(msgPayload  msg,
                         const char* name,
                         mama_fid_t  fid,
                         mama_bool_t value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addChar(msgPayload  msg,
                         const char* name,
                         mama_fid_t  fid,
                         char        value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addI8(msgPayload          msg,
                       const char*         name,
                       mama_fid_t          fid,
                       mama_i8_t           value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addU8(msgPayload          msg,
                       const char*         name,
                       mama_fid_t          fid,
                       mama_u8_t           value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addI16(msgPayload          msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_i16_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addU16(msgPayload          msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_u16_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addI32(msgPayload          msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_i32_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addU32(msgPayload          msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_u32_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addI64(msgPayload          msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_i64_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addU64(msgPayload          msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_u64_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addF32(msgPayload          msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_f32_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addF64(msgPayload          msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_f64_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addString(msgPayload          msg,
                           const char*         name,
                           mama_fid_t          fid,
                           const char*         value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addOpaque(msgPayload          msg,
                           const char*         name,
                           mama_fid_t          fid,
                           const void*         value,
                           mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addDateTime(msgPayload          msg,
                             const char*         name,
                             mama_fid_t          fid,
                             const mamaDateTime  value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addPrice(msgPayload          msg,
                          const char*         name,
                          mama_fid_t          fid,
                          const mamaPrice     value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addMsg(msgPayload          msg,
                        const char*         name,
                        mama_fid_t          fid,
                        msgPayload          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorBool(msgPayload          msg,
                               const char*         name,
                               mama_fid_t          fid,
                               const mama_bool_t   value[],
                               mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorChar(msgPayload          msg,
                               const char*         name,
                               mama_fid_t          fid,
                               const char          value[],
                               mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorI8(msgPayload          msg,
                             const char*         name,
                             mama_fid_t          fid,
                             const mama_i8_t     value[],
                             mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorU8(msgPayload          msg,
                             const char*         name,
                             mama_fid_t          fid,
                             const mama_u8_t     value[],
                             mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorI16(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_i16_t    value[],
                              mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorU16(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_u16_t    value[],
                              mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorI32(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_i32_t    value[],
                              mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorU32(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_u32_t    value[],
                              mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorI64(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_i64_t    value[],
                              mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorU64(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_u64_t    value[],
                              mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorF32(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_f32_t    value[],
                              mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorF64(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_f64_t    value[],
                              mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorString(msgPayload          msg,
                                 const char*         name,
                                 mama_fid_t          fid,
                                 const char*         value[],
                                 mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorMsg(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mamaMsg       value[],
                              mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorDateTime(msgPayload          msg,
                                   const char*         name,
                                   mama_fid_t          fid,
                                   const mamaDateTime  value[],
                                   mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_addVectorPrice(msgPayload          msg,
                                const char*         name,
                                mama_fid_t          fid,
                                const mamaPrice     value[],
                                mama_size_t         size);
MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateBool(msgPayload          msg,
                            const char*         name,
                            mama_fid_t          fid,
                            mama_bool_t         value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateChar(msgPayload          msg,
                            const char*         name,
                            mama_fid_t          fid,
                            char                value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateU8(msgPayload          msg,
                          const char*         name,
                          mama_fid_t          fid,
                          mama_u8_t           value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateI8(msgPayload          msg,
                          const char*         name,
                          mama_fid_t          fid,
                          mama_i8_t           value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateI16(msgPayload          msg,
                           const char*         name,
                           mama_fid_t          fid,
                           mama_i16_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateU16(msgPayload          msg,
                           const char*         name,
                           mama_fid_t          fid,
                           mama_u16_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateI32(msgPayload          msg,
                           const char*         name,
                           mama_fid_t          fid,
                           mama_i32_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateU32(msgPayload          msg,
                           const char*         name,
                           mama_fid_t          fid,
                           mama_u32_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateI64(msgPayload          msg,
                           const char*         name,
                           mama_fid_t          fid,
                           mama_i64_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateU64(msgPayload          msg,
                           const char*         name,
                           mama_fid_t          fid,
                           mama_u64_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateF32(msgPayload          msg,
                           const char*         name,
                           mama_fid_t          fid,
                           mama_f32_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateF64(msgPayload          msg,
                           const char*         name,
                           mama_fid_t          fid,
                           mama_f64_t          value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateString(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const char*         value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateOpaque(msgPayload          msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const void*         value,
                              mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateDateTime(msgPayload          msg,
                                const char*         name,
                                mama_fid_t          fid,
                                const mamaDateTime  value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updatePrice(msgPayload          msg,
                             const char*         name,
                             mama_fid_t          fid,
                             const mamaPrice     value);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getBool(const msgPayload    msg,
                         const char*         name,
                         mama_fid_t          fid,
                         mama_bool_t*        result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateSubMsg(msgPayload          msg,
                              const char*         fname,
                              mama_fid_t          fid,
                              const msgPayload    subMsg);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorMsg(msgPayload          msg,
                                 const char*         fname,
                                 mama_fid_t          fid,
                                 const mamaMsg       value[],
                                 mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorString(msgPayload         msg,
                                    const char*         fname,
                                    mama_fid_t          fid,
                                    const char*         strList[],
                                    mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorBool(msgPayload          msg,
                                  const char*         fname,
                                  mama_fid_t          fid,
                                  const mama_bool_t   boolList[],
                                  mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorChar(msgPayload          msg,
                                  const char*         fname,
                                  mama_fid_t          fid,
                                  const char          charList[],
                                  mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorI8(msgPayload          msg,
                                const char*         fname,
                                mama_fid_t          fid,
                                const mama_i8_t     i8List[],
                                mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorU8(msgPayload          msg,
                                const char*         fname,
                                mama_fid_t          fid,
                                const mama_u8_t     u8List[],
                                mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorI16(msgPayload          msg,
                                 const char*         fname,
                                 mama_fid_t          fid,
                                 const mama_i16_t    i16List[],
                                 mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorU16(msgPayload          msg,
                                 const char*         fname,
                                 mama_fid_t          fid,
                                 const mama_u16_t    u16List[],
                                 mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorI32(msgPayload          msg,
                                 const char*         fname,
                                 mama_fid_t          fid,
                                 const mama_i32_t    i32List[],
                                 mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorU32(msgPayload          msg,
                                 const char*         fname,
                                 mama_fid_t          fid,
                                 const mama_u32_t    u32List[],
                                 mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorI64(msgPayload          msg,
                                 const char*         fname,
                                 mama_fid_t          fid,
                                 const mama_i64_t    i64List[],
                                 mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorU64(msgPayload          msg,
                                 const char*         fname,
                                 mama_fid_t          fid,
                                 const mama_u64_t    u64List[],
                                 mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorF32(msgPayload          msg,
                                 const char*         fname,
                                 mama_fid_t          fid,
                                 const mama_f32_t    f32List[],
                                 mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorF64(msgPayload          msg,
                                 const char*         fname,
                                 mama_fid_t          fid,
                                 const mama_f64_t    f64List[],
                                 mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorPrice(msgPayload          msg,
                                   const char*         fname,
                                   mama_fid_t          fid,
                                   const mamaPrice     priceList[],
                                   mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_updateVectorTime(msgPayload          msg,
                                  const char*         fname,
                                  mama_fid_t          fid,
                                  const mamaDateTime  timeList[],
                                  mama_size_t         size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getChar(const msgPayload    msg,
                         const char*         name,
                         mama_fid_t          fid,
                         char*               result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getI8(const msgPayload    msg,
                       const char*         name,
                       mama_fid_t          fid,
                       mama_i8_t*          result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getU8(const msgPayload    msg,
                       const char*         name,
                       mama_fid_t          fid,
                       mama_u8_t*          result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getI16(const msgPayload    msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_i16_t*         result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getU16(const msgPayload    msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_u16_t*         result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getI32(const msgPayload    msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_i32_t*         result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getU32(const msgPayload    msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_u32_t*         result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getI64(const msgPayload    msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_i64_t*         result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getU64(const msgPayload    msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_u64_t*         result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getF32(const msgPayload    msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_f32_t*         result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getF64(const msgPayload    msg,
                        const char*         name,
                        mama_fid_t          fid,
                        mama_f64_t*         result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getString(const msgPayload    msg,
                           const char*         name,
                           mama_fid_t          fid,
                           const char**        result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getOpaque(const msgPayload    msg,
                           const char*         name,
                           mama_fid_t          fid,
                           const void**        result,
                           mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getField(const msgPayload    msg,
                          const char*         name,
                          mama_fid_t          fid,
                          msgFieldPayload*    result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getDateTime(const msgPayload    msg,
                             const char*         name,
                             mama_fid_t          fid,
                             mamaDateTime        result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getPrice(const msgPayload    msg,
                          const char*         name,
                          mama_fid_t          fid,
                          mamaPrice           result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getMsg(const msgPayload    msg,
                        const char*         name,
                        mama_fid_t          fid,
                        msgPayload*         result);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorBool(const msgPayload    msg,
                               const char*         name,
                               mama_fid_t          fid,
                               const mama_bool_t** result,
                               mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorChar(const msgPayload    msg,
                               const char*         name,
                               mama_fid_t          fid,
                               const char**        result,
                               mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorI8(const msgPayload    msg,
                             const char*         name,
                             mama_fid_t          fid,
                             const mama_i8_t**   result,
                             mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorU8(const msgPayload    msg,
                             const char*         name,
                             mama_fid_t          fid,
                             const mama_u8_t**   result,
                             mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorI16(const msgPayload    msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_i16_t**  result,
                              mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorU16(const msgPayload    msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_u16_t**  result,
                              mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorI32(const msgPayload    msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_i32_t**  result,
                              mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorU32(const msgPayload    msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_u32_t**  result,
                              mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorI64(const msgPayload    msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_i64_t**  result,
                              mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorU64(const msgPayload    msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_u64_t**  result,
                              mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorF32(const msgPayload    msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_f32_t**  result,
                              mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorF64(const msgPayload    msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const mama_f64_t**  result,
                              mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorString(const msgPayload    msg,
                                 const char*         name,
                                 mama_fid_t          fid,
                                 const char***       result,
                                 mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorDateTime(const msgPayload    msg,
                                   const char*         name,
                                   mama_fid_t          fid,
                                   const mamaDateTime** result,
                                   mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorPrice(const msgPayload    msg,
                                const char*         name,
                                mama_fid_t          fid,
                                const mamaPrice**   result,
                                mama_size_t*        size);

MAMAExpBridgeDLL mama_status
ybtrepmsgPayload_getVectorMsg(const msgPayload    msg,
                              const char*         name,
                              mama_fid_t          fid,
                              const msgPayload**  result,
                              mama_size_t*        size);

#ifdef __cplusplus
}
#endif

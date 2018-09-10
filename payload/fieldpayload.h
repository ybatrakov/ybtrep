#pragma once

#include <mama/mama.h>

#define OPENMAMA_INTEGRATION
#include <mama/integration/types.h>

#ifdef __cplusplus
extern "C" {
#endif

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_create(msgFieldPayload*         field);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_destroy(msgFieldPayload         field);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getType(const msgFieldPayload   field,
                              mamaFieldType*          result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getName(msgFieldPayload         field,
                              mamaDictionary          dict,
                              mamaFieldDescriptor     desc,
                              const char**            result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getFid(const msgFieldPayload   field,
                             mamaDictionary          dict,
                             mamaFieldDescriptor     desc,
                             uint16_t*               result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getDescriptor(const msgFieldPayload   field,
                                    mamaDictionary          dict,
                                    mamaFieldDescriptor*    result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateBool(msgFieldPayload         field,
                                 msgPayload              msg,
                                 mama_bool_t             value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateChar(msgFieldPayload         field,
                                 msgPayload              msg,
                                 char                    value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateU8(msgFieldPayload         field,
                               msgPayload              msg,
                               mama_u8_t               value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateI8(msgFieldPayload         field,
                               msgPayload              msg,
                               mama_i8_t               value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateI16(msgFieldPayload         field,
                                msgPayload              msg,
                                mama_i16_t              value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateU16(msgFieldPayload         field,
                                msgPayload              msg,
                                mama_u16_t              value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateI32(msgFieldPayload         field,
                                msgPayload              msg,
                                mama_i32_t              value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateU32(msgFieldPayload         field,
                                msgPayload              msg,
                                mama_u32_t              value);
MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateI64(msgFieldPayload         field,
                                msgPayload              msg,
                                mama_i64_t              value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateU64(msgFieldPayload         field,
                                msgPayload              msg,
                                mama_u64_t              value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateF32(msgFieldPayload         field,
                                msgPayload              msg,
                                mama_f32_t              value);
MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateF64(msgFieldPayload         field,
                                msgPayload              msg,
                                mama_f64_t              value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateString(msgFieldPayload         field,
                                   msgPayload              msg,
                                   const char*             value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateDateTime(msgFieldPayload         field,
                                     msgPayload              msg,
                                     const mamaDateTime      value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updatePrice(msgFieldPayload         field,
                                  msgPayload              msg,
                                  const mamaPrice         value);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_updateSubMsg(msgFieldPayload         field,
                                   msgPayload              msg,
                                   const msgPayload        subMsg);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getBool(const msgFieldPayload   field,
                              mama_bool_t*            result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getChar(const msgFieldPayload   field,
                              char*                   result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getI8(const msgFieldPayload   field,
                            mama_i8_t*              result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getU8(const msgFieldPayload   field,
                            mama_u8_t*              result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getI16(const msgFieldPayload   field,
                             mama_i16_t*             result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getU16(const msgFieldPayload   field,
                             mama_u16_t*            result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getI32(const msgFieldPayload   field,
                             mama_i32_t*             result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getU32(const msgFieldPayload   field,
                             mama_u32_t*             result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getI64(const msgFieldPayload   field,
                             mama_i64_t*             result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getU64(const msgFieldPayload   field,
                             mama_u64_t*             result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getF32(const msgFieldPayload   field,
                             mama_f32_t*             result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getF64(const msgFieldPayload   field,
                             mama_f64_t*             result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getString(const msgFieldPayload   field,
                                const char**            result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getOpaque(const msgFieldPayload   field,
                                const void**            result,
                                mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getDateTime(const msgFieldPayload   field,
                                  mamaDateTime            result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getPrice(const msgFieldPayload   field,
                               mamaPrice               result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getMsg(const msgFieldPayload   field,
                             msgPayload*             result);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorBool(const msgFieldPayload   field,
                                    const mama_bool_t**     result,
                                    mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorChar(const msgFieldPayload   field,
                                    const char**            result,
                                    mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorI8(const msgFieldPayload   field,
                                  const mama_i8_t**       result,
                                  mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorU8(const msgFieldPayload   field,
                                  const mama_u8_t**       result,
                                  mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorI16(const msgFieldPayload   field,
                                   const mama_i16_t**      result,
                                   mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorU16(const msgFieldPayload   field,
                                   const mama_u16_t**      result,
                                   mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorI32(const msgFieldPayload   field,
                                   const mama_i32_t**      result,
                                   mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorU32(const msgFieldPayload   field,
                                   const mama_u32_t**      result,
                                   mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorI64(const msgFieldPayload   field,
                                   const mama_i64_t**      result,
                                   mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorU64(const msgFieldPayload   field,
                                   const mama_u64_t**      result,
                                   mama_size_t*            size);

 MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorF32(const msgFieldPayload   field,
                                   const mama_f32_t**      result,
                                   mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorF64(const msgFieldPayload   field,
                                   const mama_f64_t**      result,
                                   mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorString(const msgFieldPayload   field,
                                      const char***           result,
                                      mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorDateTime(const msgFieldPayload   field,
                                        const mamaDateTime*     result,
                                        mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorPrice(const msgFieldPayload   field,
                                     const mamaPrice*        result,
                                     mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getVectorMsg(const msgFieldPayload   field,
                                   const msgPayload**      result,
                                   mama_size_t*            size);

MAMAExpBridgeDLL mama_status
ybtrepmsgFieldPayload_getAsString(const msgFieldPayload   field,
                                  const msgPayload        msg,
                                  char*                   buffer,
                                  mama_size_t             len);

#ifdef __cplusplus
}
#endif

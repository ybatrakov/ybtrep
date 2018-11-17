#pragma once

#include "MsgImpl.h"

// Stub for future value convertion utility class
template<typename ToType>
struct ConvertImpl;

template<>
struct ConvertImpl<mama_i32_t> {
    static mama_status convert(const FieldValue& val, mama_i32_t* ret) {
        switch(val.type) {
        case MAMA_FIELD_TYPE_I16:
            *ret = val.scalar.i16;
            break;
        case MAMA_FIELD_TYPE_I32:
            *ret = val.scalar.i32;
            break;
        default:
            return MAMA_STATUS_INVALID_ARG;
        }
        return MAMA_STATUS_OK;
    }
};

struct FieldGetter {
    template<typename RetType>
    static mama_status getField(const Message* msg, const char* name, mama_fid_t fid, RetType* ret) {
        FieldValue value;
        mama_status rc = getValue(msg, name, fid, value);
        if(rc != MAMA_STATUS_OK) {
            mama_log(MAMA_LOG_LEVEL_ERROR, "FieldGetter::getField: Could not get value from message: %s",
                     mamaStatus_stringForStatus(rc));
            return rc;
        }
        rc = convert<RetType>(value, ret);
        if(rc != MAMA_STATUS_OK) {
            mama_log(MAMA_LOG_LEVEL_ERROR, "FieldGetter::getField: Could not convert value: %s",
                     mamaStatus_stringForStatus(rc));
            return rc;
        }
        return MAMA_STATUS_OK;
    }

    static mama_status getValue(const Message* msg, const char* name, mama_fid_t fid, FieldValue& value) {
        // TODO: Field mapping either of:
        // mama fid <-> system fid (msg type, msg status etc), static
        // mama fid <-> MAMDA fid (book's bid at level0 etc), static?
        // mama fid <-> arbitrary Reuters field
        if(fid == MamaFieldMsgType.mFid) {
            value.type = MAMA_FIELD_TYPE_I32;
            value.scalar.i32 = msg->type;
            return MAMA_STATUS_OK;
        }
        if(fid == MamaFieldMsgStatus.mFid) {
            value.type = MAMA_FIELD_TYPE_I32;
            value.scalar.i32 = msg->status;
            return MAMA_STATUS_OK;
        }

        (void) name;
        return MAMA_STATUS_NOT_FOUND;
    }

    template<typename RetType>
    static mama_status convert(FieldValue& val, RetType* ret) {
        return ConvertImpl<RetType>::convert(val, ret);
    }
};

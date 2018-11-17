#pragma once

#include "MsgImpl.h"

struct FieldSetter {
    template<typename ValueType>
    static mama_status setField(Message* msg, const char* name, mama_fid_t fid, ValueType val) {
        mama_status rc = setValue(msg, fid, val);
        if(rc != MAMA_STATUS_OK) {
            mama_log(MAMA_LOG_LEVEL_ERROR, "FieldSetter::setField: Could not set value: %s",
                     mamaStatus_stringForStatus(rc));
            return rc;
        }

        (void) name;
        return MAMA_STATUS_OK;
    }

    template<typename ValueType>
    static mama_status setValue(Message* msg, mama_fid_t fid, ValueType val) {
        if(fid == MamaFieldMsgType.mFid) {
            return convert(msg->type, val);
        }
        if(fid == MamaFieldMsgStatus.mFid) {
            return convert(msg->status, val);
        }
        return MAMA_STATUS_INVALID_ARG;
    }

    static inline mama_status convert(mama_i32_t& to, mama_i32_t from) {
        to = from;
        return MAMA_STATUS_OK;
    }
};

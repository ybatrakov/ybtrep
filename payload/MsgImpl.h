#pragma once

#include <mama/mama.h>
#include <unordered_map>

struct FieldValue {
    mamaFieldType type;
    union {
        mama_i16_t i16;
        mama_i32_t i32;
    } scalar;
};

struct Message {
    mama_i32_t type;
    mama_i32_t status;
    std::unordered_map<mama_fid_t, FieldValue> fields;

    mamaMsg parent;

    Message()
        : type(MAMA_MSG_TYPE_UNKNOWN),
          parent(nullptr)
    {}

    static inline Message* get(msgPayload msg) {
        return reinterpret_cast<Message*>(msg);
    }
};

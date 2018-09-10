cmake_minimum_required(VERSION 3.0)

project(ybtrep_payload)

include_directories(${MAMA_ROOT_DIR}/include)

add_library(mamaybtrepmsgimpl MODULE
    payloadbridge.cc
    payloaditerator.cc
    fieldpayload.cc
)

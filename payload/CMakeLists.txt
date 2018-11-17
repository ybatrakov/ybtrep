cmake_minimum_required(VERSION 3.0)

project(ybtrep_payload)

add_library(mamaybtrepmsgimpl MODULE
    payloadbridge.cc
    payloaditerator.cc
    fieldpayload.cc
)

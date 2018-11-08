cmake_minimum_required(VERSION 3.0)

project(ybtrep_transport)

include_directories(${MAMA_ROOT_DIR}/include)
include_directories(${MAMA_SRC_DIR}/mama/c_cpp/src/c)

add_library(mamaybtrepimpl MODULE
    transportbridge.cc
    queue.cc
    transport.cc
    subscription.cc
    timer.cc
    io.cc
    publisher.cc
    inbox.cc
    msg.cc
)

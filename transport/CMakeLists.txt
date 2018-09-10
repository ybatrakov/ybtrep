cmake_minimum_required(VERSION 3.0)

project(ybtrep_transport)

include_directories(${MAMA_ROOT_DIR}/include)

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

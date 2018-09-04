cmake_minimum_required(VERSION 3.0)

project(ybtrep_transport)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

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

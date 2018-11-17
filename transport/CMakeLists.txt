cmake_minimum_required(VERSION 3.0)

project(ybtrep_transport)

add_library(mamaybtrepimpl MODULE
    Utils.cc
    MessageUtils.cc
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

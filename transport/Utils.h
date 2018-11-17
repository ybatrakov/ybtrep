#pragma once

#include <mama/types.h>

struct Queue;
struct Transport;
struct Inbox;

struct Utils {
    static bool addTransportToQueue(mamaTransport tport, mamaQueue q);

    Utils() = delete;
    Utils& operator=(const Utils&) = delete;
};

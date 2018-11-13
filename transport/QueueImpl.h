#pragma once

#include "TimerHeap.h"
#include "TransportImpl.h"
#include <mama/types.h>
#include <vector>
#include <algorithm>

struct Queue {
    mamaQueue parent;
    TimerHeap timerHeap;
    std::vector<Transport*> transports;

    void addTransport(Transport* tport) {
        if(tport == nullptr) {
            return;
        }

        auto it = std::find(transports.begin(), transports.end(), tport);
        if(it == transports.end()) {
            transports.push_back(tport);
        }
    }

    Timer* createTimer(double interval, mamaTimerCb action, mamaTimerCb onTimerDestroyed,
                       mamaTimer parent, void* closure, Queue* queue)
    {
        return timerHeap.create(interval, action, onTimerDestroyed, parent, closure, queue);
    }

    void scheduleTimer(Timer* timer) {
        timerHeap.schedule(timer);
    }

    void destroyTimer(Timer* timer) {
        timerHeap.destroy(timer);
    }

    void dispatch(uint64_t timeout) {
        const Timer* timer = timerHeap.nextTimer();
        if(timer != nullptr) {
            timer->fire();
        }
        for(auto i = transports.begin(); i != transports.end(); ++i) {
            (*i)->dispatch(timeout);
        }
    }
};

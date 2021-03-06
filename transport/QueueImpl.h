#pragma once

#include "TimerHeap.h"
#include "TransportImpl.h"
#include <mama/types.h>
#include <vector>
#include <algorithm>

struct Queue {
    bool dispatching;
    mamaQueue parent;
    TimerHeap timerHeap;
    std::vector<Transport*> transports;

    Queue()
        : dispatching(false)
    {}

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
        if(!dispatching) {
            return;
        }

        const Timer* timer = timerHeap.nextTimer();
        if(timer != nullptr) {
            timer->fire();
        }
        for(auto i = transports.begin(); i != transports.end(); ++i) {
            (*i)->dispatch(timeout);
        }
    }

    inline static Queue* get(void* nativeHandle) {
        return reinterpret_cast<Queue*>(nativeHandle);
    }

    inline static Queue* get(mamaQueue q) {
        Queue* queue = nullptr;
        mama_status rc = mamaQueue_getNativeHandle(q, reinterpret_cast<void**>(&queue));
        if(rc != MAMA_STATUS_OK || queue == nullptr) {
            return nullptr;
        }

        return queue;
    }
};

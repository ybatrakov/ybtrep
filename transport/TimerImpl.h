#pragma once

#include <mama/timer.h>

struct Queue;

struct Timer {
    bool        destroying;
    mamaTimerCb action;
    mamaTimerCb onTimerDestroyed;
    double      interval;
    mamaTimer   parent;
    void*       closure;
    Queue*      queue;

    Timer(double interval_, mamaTimerCb action_, mamaTimerCb onTimerDestroyed_,
          mamaTimer parent_, void* closure_, Queue* queue_) :
        destroying(false),
        action(action_),
        onTimerDestroyed(onTimerDestroyed_),
        interval(interval_),
        parent(parent_),
        closure(closure_),
        queue(queue_)
    {
    }

    ~Timer() {
        if(onTimerDestroyed) {
            onTimerDestroyed(parent, closure);
        }
    }

    void fire() const {
        action(parent, closure);
    }
};

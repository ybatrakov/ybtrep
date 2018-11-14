#pragma once

#include <map>
#include "TimerImpl.h"

struct TimerHeap {
    void schedule(Timer* timer) {
        if(timer == nullptr) {
            return;
        }

        int64_t usec = getTime() + static_cast<int64_t>(timer->interval) * 1000000;
        timerMap.emplace(usec, timer);
    }

    const Timer* nextTimer() {
        if(timerMap.empty()) {
            return nullptr;
        }
        auto it = timerMap.begin();
        if(getTime() < it->first) {
            return nullptr;
        }

        Timer* timer = it->second;
        timerMap.erase(it);

        if(!timer->destroying) {
            schedule(timer);
            return timer;
        }
        else {
            delete timer;
            return nullptr;
        }
    }

    Timer* create(double interval, mamaTimerCb action, mamaTimerCb onTimerDestroyed,
                  mamaTimer parent, void* closure, Queue* queue)
    {
        return new Timer(interval, action, onTimerDestroyed, parent, closure, queue);
    }

    void destroy(Timer* timer) {
        // Delayed destroy upon nextTimer()
        timer->destroying = true;
    }

    inline static int64_t getTime() {
        timespec tp;
        clock_gettime(CLOCK_MONOTONIC, &tp);
        return tp.tv_sec * 1000000 + tp.tv_nsec / 1000;
    }

    std::map<int64_t, Timer*> timerMap;
};

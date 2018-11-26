#pragma once

#include <type_traits>

template <typename T, typename = int>
struct HasCallbacks : std::false_type { };

template <typename T>
struct HasCallbacks <T, decltype((void) T::callbacks, 0)> : std::true_type { };

template<bool> // Has member called callbacks?
struct DeleteWithCallback;

template<>
struct DeleteWithCallback<true> {
    template<typename ToDeleteType>
    static void del(ToDeleteType* d) {
        auto destroyCb = d->callbacks.onDestroy;
        auto parent    = d->parent;
        void* closure  = d->callbackClosure;

        delete d;

        if(destroyCb) {
            destroyCb(parent, closure);
        }
    }
};

template<>
struct DeleteWithCallback<false> {
    template<typename ToDeleteType>
    static void del(ToDeleteType* d) {
        auto destroyCb = d->onDestroy;
        auto parent    = d->parent;
        void* closure  = d->callbackClosure;

        delete d;

        if(destroyCb) {
            destroyCb(parent, closure);
        }
    }
};

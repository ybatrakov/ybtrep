#pragma once

#define OPENMAMA_INTEGRATION
#include <mama/integration/inbox.h>
#include <mama/types.h>

struct Inbox {
    mamaInboxMsgCallback     onMsg;
    mamaInboxErrorCallback   onError;
    mamaInboxDestroyCallback onDestroyed;
    mamaInbox                parent;
    void*                    closure;

    void reply(mamaMsg reply) {
        mama_log(MAMA_LOG_LEVEL_FINER, "Sending message %p to inbox %p", reply, parent);
        if(onMsg) {
            onMsg(reply, closure);
        }
    }

    inline static Inbox* get(mamaInbox mi) {
        return reinterpret_cast<Inbox*>(mamaInboxImpl_getInboxBridge(mi));
    }
};

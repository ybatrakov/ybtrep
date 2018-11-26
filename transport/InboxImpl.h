#pragma once

#define OPENMAMA_INTEGRATION
#include <mama/integration/inbox.h>
#include <mama/types.h>

struct Inbox {
    mamaInboxMsgCallback     onMsg;
    mamaInboxErrorCallback   onError;
    mamaInboxDestroyCallback onDestroy;
    mamaInbox                parent;
    void*                    callbackClosure;

    void reply(mamaMsg reply) {
        mama_log(MAMA_LOG_LEVEL_FINER, "Sending message %p to inbox %p", reply, parent);
        if(onMsg) {
            onMsg(reply, callbackClosure);
        }
    }

    inline static Inbox* get(mamaInbox mi) {
        return reinterpret_cast<Inbox*>(mamaInboxImpl_getInboxBridge(mi));
    }

    inline static Inbox* get(inboxBridge ib) {
        return reinterpret_cast<Inbox*>(ib);
    }
};

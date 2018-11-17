#pragma once

#include <mama/types.h>
#include <vector>

#include "InboxImpl.h"
#include "MessageUtils.h"

struct Dictionary {
    Dictionary() {
        replyMsg = MessageUtils::createMamaMsg();
        mamaMsg_addI32(replyMsg, MamaFieldMsgType.mName,
                       MamaFieldMsgType.mFid, MAMA_MSG_TYPE_DDICT_SNAPSHOT);
        mamaMsg_addI32(replyMsg, MamaFieldMsgStatus.mName,
                       MamaFieldMsgStatus.mFid, MAMA_MSG_STATUS_OK);
    }

    ~Dictionary() {
        mamaMsg_destroy(replyMsg);
    }

    void dispatch() {
        if(inboxes.empty()) {
            return;
        }

        if(!complete) {
            readDictionary();
        }

        if(complete) {
            for(mamaInbox inbox : inboxes) {
                reply(inbox);
            }
            inboxes.clear();
        }
    }

    void sendRequest(mamaInbox inbox, mamaMsg msg) {
        inboxes.push_back(inbox); // TODO: erase inbox if it is destroyed before dictionary is received
        if(!complete) {
            sendRequestImpl(msg);
        }
    }

private:
    void reply(mamaInbox replyTo) {
        Inbox* inbox = Inbox::get(replyTo);
        inbox->reply(replyMsg);
    }

    void readDictionary() {
        complete = true;
    }

    void sendRequestImpl(mamaMsg req) {
        (void) req;
    }

    bool complete;
    mamaMsg replyMsg;               // reusable reply message
    std::vector<mamaInbox> inboxes; // all dictionary requestors. normally there should be only one
};

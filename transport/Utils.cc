#include "Utils.h"

#include "QueueImpl.h"
#include "TransportImpl.h"

bool Utils::addTransportToQueue(mamaTransport tport, mamaQueue q) {
    Queue* queue = Queue::get(q);
    if(queue == nullptr) {
        mama_log (MAMA_LOG_LEVEL_ERROR, "Utils::addTransportToQueue: Couldn't get queue");
        return false;
    }

    Transport* transport = Transport::get(tport);
    if (transport == nullptr) {
        mama_log (MAMA_LOG_LEVEL_ERROR, "Utils::addTransportToQueue: Couldn't get transport");
        return false;
    }

    queue->addTransport(transport);
    return true;
}

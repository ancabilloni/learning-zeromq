#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "zmq.h"
// Server replies "word" to whenever it receives a "hello" from client.
// Server runs on port 404 and client sends messages to port 4040.

int main (int argc, char const *argv[]) {
    void* context = zmq_ctx_new();
    void* respond = zmq_socket(context, ZMQ_REP);
    zmq_bind(respond, "tcp://*:4040");

    printf("Starting...\n");

    for(;;) {
        zmq_msg_t request;
        zmq_msg_init(&request);
        zmq_msg_recv(&request, respond, 0);
        printf("Received: hello\n");
        zmq_msg_close(&request);
        sleep(1); // sleep 1 sec

        zmq_msg_t reply;
        zmq_msg_init_size(&reply, strlen("word"));
        memcpy(zmq_msg_data(&reply), "world", 5);
        zmq_msg_send(&reply, respond, 0);
        zmq_msg_close(&reply);
    }

    zmq_close(respond);
    zmq_ctx_destroy(context);

    return 0;
}
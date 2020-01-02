#include <iostream>
#include <zmq.hpp>
#include <string>
#include <unistd.h>

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:4040");

    while (true) {
        zmq::message_t request;
        socket.recv(&request);
        std::cout << "Received Hello" << std::endl;

        sleep(1);

        zmq::message_t reply(5);
        memcpy (reply.data(), "World", 5);
        socket.send(reply);
    }
    return 0;
}
//
//  Hello World server in C++
//  Binds REP socket to tcp://*:5555
//  Expects "Hello" from client, replies with "World"
//
#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>

int main () {
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, PAIR);
    socket.bind("tcp://ip:port");


    while (true) {
        // zmq::message_t request;

        // //  Wait for next request from client
        // socket.recv (&request);
        // std::cout << "Received Hello" << std::endl;

        //  Do some 'work'

        //  Send reply back to client
        zmq::message_t reply (5);
        memcpy ((void *) reply.data (), "World", 5);
        socket.send (reply);
        sleep (1);

    }
    return 0;
}
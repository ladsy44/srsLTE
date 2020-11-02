#include "my_zmq_socket.h"

  MyZMQsock::MyZMQsock(std::string port) {open(port);}
  MyZMQsock::~MyZMQsock() {close();}

  void MyZMQsock::open(std::string port) {
    context = zmq_init(1);
    socket = zmq_socket(context, ZMQ_PUB);
    address += port;
    char * addr = &address[0];
    zmq_connect(socket, addr);
  }
  void MyZMQsock::send(const void *buf, size_t len, int flags) {
    zmq_send(socket, buf, len, flags);
  }

  void MyZMQsock::close() {
    char * addr = &address[0];
    zmq_disconnect(socket, addr);
    zmq_close(socket);
  }

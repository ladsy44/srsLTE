#include "my_zmq_socket.h"

//MyZMQsock::MyZMQsock(char* port) {open(port);}
  //MyZMQsock::~MyZMQsock() {close();}
//MyZMQsock::MyZMQsock() {}


  void MyZMQsock::open(const char* port) {
    context = zmq_init(1);
    socket = zmq_socket(context, ZMQ_PUB);

    //address = new char[strlen(defAdd) + strlen(port) + 1 + 1];
    address = new char[strlen(port) + 1];
    //strcpy(address, defAdd);
    strcat(address, port);

    //address += port;
    //char * addr = &address[0];
    zmq_connect(socket, address);
  }
  void MyZMQsock::send(const void *buf, size_t len, int flags) {
    zmq_send(socket, buf, len, flags);
  }

  void MyZMQsock::close() {
    char * addr = &address[0];
    zmq_disconnect(socket, addr);
    zmq_close(socket);
  }


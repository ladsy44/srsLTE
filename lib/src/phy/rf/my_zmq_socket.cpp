#include "my_zmq_socket.h"

//MyZMQsock::MyZMQsock(char* port) {open(port);}
  //MyZMQsock::~MyZMQsock() {close();}
//MyZMQsock::MyZMQsock() {}


  void openMyZmq(struct MyZMQsock my, const char* address){
    my.context = zmq_init(1);
    my.socket = zmq_socket(my.context, ZMQ_PUB);

    //address = new char[strlen(defAdd) + strlen(port) + 1 + 1];
    my.address = new char[strlen(address) + 1];
    //strcpy(address, defAdd);
    strcat(my.address, address);

    //address += port;
    //char * addr = &address[0];
    zmq_connect(my.socket, my.address);
  }
  void sendMyZmq(struct MyZMQsock my, const void *buf, size_t len, int flags){
    zmq_send(my.socket, buf, len, flags);
  }

  void closeMyZmq(struct MyZMQsock my){
    char * addr = &my.address[0];
    zmq_disconnect(my.socket, addr);
    zmq_close(my.socket);
  }


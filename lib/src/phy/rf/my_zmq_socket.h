#include <zmq.h>
#include "string.h"

struct MyZMQsock{
  //MyZMQsock();
  // private:
  void *context;
  void *socket;

  //const char* defAdd = "tcp://127.0.0.1:";
  //const char* defAdd = "tcp://127.0.0.1:";
  char* address;


//public:
  //MyZMQsock(char* port);
  //~MyZMQsock();
  void open(const char* port);
  void close();
  void send(const void *buf, size_t len, int flags);
};
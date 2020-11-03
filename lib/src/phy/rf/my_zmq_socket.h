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

};

void openMyZmq(struct MyZMQsock my, const char* address);
void closeMyZmq(struct MyZMQsock my);
void sendMyZmq(struct MyZMQsock my, const void *buf, size_t len, int flags);
#include <string>
#include <zmq.h>

class MyZMQsock{
private:
  void *context;
  void *socket;

  std::string address = "tcp://127.0.0.1:";
public:
  MyZMQsock(std::string port);
  ~MyZMQsock();
  void open(std::string port);
  void send(const void *buf, size_t len, int flags);
  void close();
};
#include <sys/socket.h>
#include <netinet/in.h>

void main() {
  int s = socket(AF_INET, SOCK_STREAM, 0);

  // local ip-addr w/ port 9999
  struct sockaddr_in addr = {
    AF_INET,
    0x0f27,
    0
  };

  bind(s, &addr, sizeof(addr));

  listen(s, 10);
  int user_fd = accept(s, 0, 0);

  char buf[2048] = {0};
  int read = recv(user_fd, buf, sizeof(buf), 0);

  send(read, buf, sizeof(buf), 0);

  close(user_fd);
  close(s);
}

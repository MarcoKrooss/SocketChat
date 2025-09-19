#include <sys/socket.h>
#include <netinet/in.h>

void main() {
  int s = socket(AF_INET, SOCK_STREAM, 0);

  // local ip-addr w/ port 9999
  struct sockaddr_in addr = {
    AF_INET,
    // python3 hex(9999) returns 0x270f => "reversed" hex
    0x0f27,
    0
  };

  connect(s, &addr, sizeof(addr));

  char buf[2048] = {0};
  send(256, s, buf, sizeof(buf), 0);

  close(s);
}

#include <bits/stdc++.h>
#include <boost/system/system_error.hpp>
#include <nghttp2/asio_http2_server.h>
using namespace nghttp2::asio_http2;
using namespace nghttp2::asio_http2::server;

int main(int argc, char *argv[]) {
  boost::system::error_code ec;
  http2 server;

  server.handle("/hello", [](const request &req, const response &res) {
      std::cout << "Handling request\n";
    res.write_head(200);
    res.end("hello, world\n");
  });

  if (server.listen_and_serve(ec, "localhost", "3000")) {
    std::cerr << "error: " << ec.message() << std::endl;
  }
}

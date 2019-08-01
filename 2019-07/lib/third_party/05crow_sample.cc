#include <bits/stdc++.h>
#include "crow.h"
using namespace std;

constexpr int port = 18080;

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/") ([] {
    return "Hello, world!";
  });

  CROW_ROUTE(app, "/object/<string>/<int>")
    .methods("POST"_method)(
    [](crow::request req, crow::response& res, string name, int id) {
      res.write(name + ":" + to_string(id) + ":" + req.body);
      res.end();
  });

  app.port(port).multithreaded().run();
}

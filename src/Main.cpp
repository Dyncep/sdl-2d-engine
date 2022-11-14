#include "Application.hpp"
#include <iostream>

int main() {
  Dyncep::Application app{{400, 400}, "Hi!"};

  while (app.isRunning()) {
    app.handleEvents();
    app.update();
    app.render();
  }

  return 0;
}

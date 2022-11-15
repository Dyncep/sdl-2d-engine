#include "Application.hpp"
#include <SDL2/SDL_timer.h>

int main() {
  auto &app = Dyncep::Application::getInstance();
  app.initialize({400, 400}, "Hi!");

  const int frame_delay = 1000 / 60;
  int frame_time = 0;
  uint32_t frame_start = 0;

  while (app.isRunning()) {

    frame_start = SDL_GetTicks();

    app.handleEvents();
    app.update();
    app.render();

    frame_time = SDL_GetTicks() - frame_start;
    if (frame_delay > frame_time) {
      SDL_Delay(frame_delay - frame_time);
    }
  }

  return 0;
}

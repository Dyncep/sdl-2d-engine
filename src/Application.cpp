#include "Application.hpp"
#include "Debug/Assertion.hpp"
#include "Events/ApplicationEventHandler.hpp"
namespace Dyncep {

Application::Application() {}

Application &Application::getInstance() {
  static Application i;
  return i;
}

SDL_Renderer *Application::getRenderer() { return getInstance().renderer; }

Application::~Application() {
  if (renderer != nullptr) {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
  }

  if (window != nullptr) {
    SDL_DestroyWindow(window);
    window = nullptr;
  }

  SDL_Quit();
}

void Application::initialize(const Utility::Size &window_size,
                             const std::string &window_title) {
  const auto init = SDL_Init(SDL_INIT_EVERYTHING);
  Debug::dAssert(init == 0, "SDL Initialization");

  window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, window_size.width,
                            window_size.height, SDL_WINDOW_SHOWN);
  Debug::dAssert(window != nullptr, "SDL Window initialization");

  renderer = SDL_CreateRenderer(window, -1, 0);
  Debug::dAssert(renderer != nullptr, "SDL Renderer initialization");

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  is_running = true;
  this->event_handler = new Events::ApplicationEventHandler(this);
}

void Application::update() { ecs_manager.update(); }

void Application::render() {
  SDL_RenderClear(renderer);
  ecs_manager.render();
  SDL_RenderPresent(renderer);
}

void Application::handleEvents() {
  if (this->event_handler == nullptr || !is_running) {
    return;
  }

  SDL_PollEvent(&event);
  this->event_handler->handle(event);
}
} // namespace Dyncep

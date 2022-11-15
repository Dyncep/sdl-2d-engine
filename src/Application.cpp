#include "Application.hpp"
#include "Components/KeyboardInputComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "Debug/Assertion.hpp"
#include "Events/ApplicationEventHandler.hpp"

namespace Dyncep {

Application::Application() {}

Application &Application::getInstance() {
  static Application i;
  return i;
}

SDL_Renderer *Application::getRenderer() { return getInstance().renderer; }

SDL_Event &Application::getEvent() { return getInstance().event; }

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

  auto &enemy = ecs_manager.addEntity();
  enemy.addComponent<Components::TransformComponent>(glm::vec2{200, 200});
  enemy.addComponent<Components::SpriteComponent>("figure-enemy.png");

  auto &player = ecs_manager.addEntity();
  player.addComponent<Components::TransformComponent>(glm::vec2{50, 200});
  player.addComponent<Components::SpriteComponent>("figure-player.png");
  player.addComponent<Components::KeyboardInputComponent>();
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

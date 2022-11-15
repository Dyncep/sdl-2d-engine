#ifndef DYNCEP_SDL_ENGINE_COMPONENTS_KEYBOARD_INPUT_COMPONENT_HPP
#define DYNCEP_SDL_ENGINE_COMPONENTS_KEYBOARD_INPUT_COMPONENT_HPP

#include "Application.hpp"
#include "TransformComponent.hpp"

namespace Dyncep::Components {
class KeyboardInputComponent : public ECS::Component {
public:
  /**
   * @brief overriden initialize method of component base class
   */
  void initialize() override {
    transform = &entity->getComponent<TransformComponent>();
  }

  void update() override {
    SDL_Event &e = Application::getEvent();

    if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
      case SDLK_w:
        transform->velocity.y = -1;
        break;
      case SDLK_a:
        transform->velocity.x = -1;
        break;
      case SDLK_s:
        transform->velocity.y = 1;
        break;
      case SDLK_d:
        transform->velocity.x = 1;
        break;
      default:
        break;
      }
    }

    if (e.type == SDL_KEYUP) {
      switch (e.key.keysym.sym) {
      case SDLK_w:
        transform->velocity.y = 0;
        break;
      case SDLK_a:
        transform->velocity.x = 0;
        break;
      case SDLK_s:
        transform->velocity.y = 0;
        break;
      case SDLK_d:
        transform->velocity.x = 0;
        break;
      default:
        break;
      }
    }
  }

private:
  /**
   * @transform the transform component of the parent entity
   */
  TransformComponent *transform = nullptr;
};
} // namespace Dyncep::Components

#endif

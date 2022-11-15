#ifndef DYNCEP_SDL_ENGINE_COMPONENTS_COLLIDER_COMPONENT_HPP
#define DYNCEP_SDL_ENGINE_COMPONENTS_COLLIDER_COMPONENT_HPP

#include "Application.hpp"
#include "SDL2/SDL_rect.h"
#include "TransformComponent.hpp"
#include <ECS/Entity.hpp>
#include <string>

namespace Dyncep::Components {
class ColliderComponent : public ECS::Component {
public:
  /**
   * @brief constructor
   *
   * @param t - the tag
   */
  ColliderComponent(const std::string &t) { this->tag = t; }

  void initialize() override {
    if (!entity->hasComponent<TransformComponent>()) {
      entity->addComponent<TransformComponent>();
    }
    transform = &entity->getComponent<TransformComponent>();
    Application::getInstance().getECSManager().addCollider(this);
  }

  void update() override {
    collider.x = transform->pos.x;
    collider.y = transform->pos.y;
    collider.w = transform->size.width * transform->scale;
    collider.h = transform->size.height * transform->scale;
  }

  /**
   * @collider the collision rect
   */
  SDL_Rect collider{};

private:
  /**
   * @tag the tag
   */
  std::string tag{};

  /**
   * @transform the transform component
   */
  TransformComponent *transform;
};
} // namespace Dyncep::Components

#endif

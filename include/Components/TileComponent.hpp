#ifndef DYNCEP_SDL_ENGINE_COMPONENTS_TILE_COMPONENT_HPP
#define DYNCEP_SDL_ENGINE_COMPONENTS_TILE_COMPONENT_HPP

#include "SpriteComponent.hpp"
#include "TransformComponent.hpp"
#include "Utility/Size.hpp"
#include <glm/vec2.hpp>

namespace Dyncep::Components {
class TileComponent : public ECS::Component {
public:
  TileComponent() = default;

  TileComponent(const SDL_Rect &rect, int tile_id) {
    tile_rect = rect;
    tile_id = tile_id;
    switch (tile_id) {
    case 0:
      path = "water.png";
      break;
    case 1:
      path = "dirt.png";
      break;
    case 2:
      path = "grass.png";
      break;
    default:
      break;
    }
  }

  void initialize() override {
    if (!entity->hasComponent<TransformComponent>()) {
      entity->addComponent<TransformComponent>(
          glm::vec2{tile_rect.x, tile_rect.y},
          Utility::Size{tile_rect.w, tile_rect.h});
    }
    if (!entity->hasComponent<SpriteComponent>()) {
      entity->addComponent<SpriteComponent>(path);
    }

    transform = &entity->getComponent<TransformComponent>();
    sprite = &entity->getComponent<SpriteComponent>();
  }

private:
  TransformComponent *transform = nullptr;
  SpriteComponent *sprite = nullptr;
  SDL_Rect tile_rect;
  int tile_id = 0;
  const char *path;
};
} // namespace Dyncep::Components

#endif

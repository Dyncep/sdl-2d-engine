#ifndef DYNCEP_SDL_ENGINE_COMPONENTS_SPRITE_COMPONENT_HPP
#define DYNCEP_SDL_ENGINE_COMPONENTS_SPRITE_COMPONENT_HPP

#include "ECS/Entity.hpp"
#include "TransformComponent.hpp"
#include "SDL2/SDL.h"
#include "TextureHelper.hpp"
#include <string>

namespace Dyncep::Components {

class SpriteComponent : public ECS::Component {
public:
  /**
   * @brief constructor
   *
   * @param resource_path - the path to the image resource used for the sprite
   */
  SpriteComponent(const std::string &resource_path) {
    texture = TextureHelper::loadTexture(resource_path.c_str());
  }

  /**
   * @brief overriden initialize function
   */
  void initialize() override {

    this->position = &this->entity->getComponent<TransformComponent>();

    src_rect.x = 0;
    src_rect.y = 0;

    src_rect.w = 50;
    src_rect.h = 100;

    dest_rect.w = 50;
    dest_rect.h = 100;
  }

  /**
   * @brief overriden update function
   */
  void update() override {
    dest_rect.x = this->position->getX();
    dest_rect.y = this->position->getY();
  }

  /**
   * @brief overriden render function
   */
  void render() override {
    TextureHelper::render(texture, src_rect, dest_rect);
  }

private:
  /**
   * @position the position component which is fetched from the entity in the
   * initialization
   */
  TransformComponent *position = nullptr;

  /**
   * @texture the sdl texture of the sprite
   */
  SDL_Texture *texture = nullptr;

  /**
   * @src_rect the source rectangle of this sprite
   */
  SDL_Rect src_rect{};

  /**
   * @dest_rect the destination rectangle of this sprite
   */
  SDL_Rect dest_rect{};
};

} // namespace Dyncep::Components

#endif

#ifndef DYNCEP_SDL_ENGINE_COMPONENTS_SPRITE_COMPONENT_HPP
#define DYNCEP_SDL_ENGINE_COMPONENTS_SPRITE_COMPONENT_HPP

#include "ECS/Entity.hpp"
#include "SDL2/SDL.h"
#include "TextureHelper.hpp"
#include "TransformComponent.hpp"
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
   * @brief destructor
   */
  ~SpriteComponent() { SDL_DestroyTexture(texture); }

  /**
   * @brief overriden initialize function
   */
  void initialize() override {

    this->transform = &this->entity->getComponent<TransformComponent>();

    src_rect.x = 0;
    src_rect.y = 0;

    src_rect.w = transform->size.width * transform->scale;
    src_rect.h = transform->size.height * transform->scale;
  }

  /**
   * @brief overriden update function
   */
  void update() override {
    dest_rect.x = transform->pos.x;
    dest_rect.y = transform->pos.y;
    dest_rect.w = transform->size.width * transform->scale;
    dest_rect.h = transform->size.height * transform->scale;
  }

  /**
   * @brief overriden render function
   */
  void render() override {
    TextureHelper::render(texture, src_rect, dest_rect);
  }

private:
  /**
   * @transform the transform component which is fetched from the entity in the
   * initialization
   */
  TransformComponent *transform = nullptr;

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

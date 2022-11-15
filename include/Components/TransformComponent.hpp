#ifndef DYNCEP_SDL_ENGINE_COMPONENTS_TRANSFORM_COMPONENT_HPP
#define DYNCEP_SDL_ENGINE_COMPONENTS_TRANSFORM_COMPONENT_HPP

#include "ECS/Component.hpp"
#include "glm/vec2.hpp"

namespace Dyncep::Components {

class TransformComponent : public ECS::Component {
public:
  /**
   * @brief constructor
   *
   * @param x - the x position
   * @param y - the y position
   */
  TransformComponent(const glm::vec2 &v) { this->pos = v; }

  /**
   * @brief default constructor
   */
  TransformComponent() = default;

  /**
   * @pos the 2d position vector
   */
  glm::vec2 pos{};

  /**
   * @velocity the 2d velocity vector
   */
  glm::vec2 velocity{};

  /**
   * @speed value of the speed to be used with the velocity
   */
  int speed = 3;

  /**
   * @brief override of update method
   */
  void update() override {
    pos.x += velocity.x * speed;
    pos.y += velocity.y * speed;
  }
};
} // namespace Dyncep::Components

#endif

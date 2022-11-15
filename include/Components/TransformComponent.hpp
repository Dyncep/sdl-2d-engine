#ifndef DYNCEP_SDL_ENGINE_COMPONENTS_POSITION_COMPONENT_HPP
#define DYNCEP_SDL_ENGINE_COMPONENTS_POSITION_COMPONENT_HPP

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
   * @brief override of update method
   */
  void update() override {
    this->pos.x++;
    this->pos.y++;
    if (this->pos.x >= 400) {
      this->pos.x = 0;
      this->pos.y = 0;
    }
  }
};
} // namespace Dyncep::Components

#endif

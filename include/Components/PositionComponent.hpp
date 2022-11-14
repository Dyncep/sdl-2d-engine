#ifndef DYNCEP_SDL_ENGINE_COMPONENTS_POSITION_COMPONENT_HPP
#define DYNCEP_SDL_ENGINE_COMPONENTS_POSITION_COMPONENT_HPP

#include "ECS/Component.hpp"

namespace Dyncep::Components {

class PositionComponent : public ECS::Component {
public:
  /**
   * @brief constructor
   *
   * @param x - the x position
   * @param y - the y position
   */
  PositionComponent(int x, int y);

  /**
   * @brief getter method for the x coordinate
   *
   * @return int
   */
  [[nodiscard]] int getX() const noexcept { return this->x; };

  /**
   * @brief getter method for the y coordinate
   *
   * @return int
   */
  [[nodiscard]] int getY() const noexcept { return this->y; }

  /**
   * @brief setter method for the x coordinate
   *
   * @param value - the new desired value for the x coordinate
   */
  void setX(int value) noexcept { this->x = value; }

  /**
   * @brief setter method for the y coordinate
   *
   * @param value - the new desired value for the y coordinate
   */
  void setY(int value) noexcept { this->y = value; }

  /**
   * @brief setter method for both x and y coordinates
   *
   * @param x - the new desired value for the x coordinate
   * @param y - the new desired value for the y coordinate
   */
  void set(int x, int y) noexcept {
    this->x = x;
    this->y = y;
  }

  /**
   * @brief override of update method
   */
  void update() override {
    this->x++;
    this->y++;
  }

private:
  /**
   * @x the x coordinate
   */
  int x = 0;

  /**
   * @y the y coordinate
   */
  int y = 0;
};
} // namespace Dyncep::Components

#endif

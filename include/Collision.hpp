#ifndef DYNCEP_SDL_ENGINE_COLLISION_HPP
#define DYNCEP_SDL_ENGINE_COLLISION_HPP

/**
 * @brief forward statement for sdl rect
 */
class SDL_Rect;

namespace Dyncep::Components {
/**
 * @brief forward declaration for collider component
 */
class ColliderComponent;
} // namespace Dyncep::Components

namespace Dyncep {

/**
 * @brief class which contains static methods in order to calculate collisions
 */
class Collision {
public:
  /**
   * @brief calculation of aa bb collision
   *
   * @param a - A rect
   * @param b - B Rect
   * @return bool - indicating whether the two rectangles collide
   */
  static bool collidesAabb(const SDL_Rect &a, const SDL_Rect &b);

  /**
   * @brief calculation of aa bb collision with collider components
   *
   * @param a - a ColliderComponent
   * @param b - b ColliderComponent
   * @return bool
   */
  static bool collidesAabb(Components::ColliderComponent *a,
                           Components::ColliderComponent *b);
};
} // namespace Dyncep

#endif

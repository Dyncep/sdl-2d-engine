#ifndef DYNCEP_SDL_ENGINE_APP_ECS_MANAGER_HPP
#define DYNCEP_SDL_ENGINE_APP_ECS_MANAGER_HPP

#include <ECS/Entity.hpp>
#include <ECS/Manager.hpp>
#include <vector>

namespace Dyncep::Components {
/**
 * @brief forward declaration for collider component
 */
class ColliderComponent;
} // namespace Dyncep::Components

namespace Dyncep {
class ECSManager : public ECS::Manager {
public:
  /**
   * @brief constructor
   */
  ECSManager() = default;

  /**
   * @brief add a collider component to the list
   *
   * @param collider - the collider to add
   */
  void addCollider(Components::ColliderComponent *collider) {
    colliders.push_back(collider);
  }

  /**
   * @brief add a collidable entity
   *
   * @param e - the entity
   */
  void addCollidableEntity(ECS::Entity *e) {
    this->collidable_entities.push_back(e);
  }

  void update()  {
    ECS::Manager::update();
  }

private:
  /**
   * @colliders the collider components
   */
  std::vector<Components::ColliderComponent *> colliders{};

  /**
   * @collidable_entities list of collidable entities
   */
  std::vector<ECS::Entity *> collidable_entities{};
};
} // namespace Dyncep

#endif

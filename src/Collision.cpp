#include "Collision.hpp"
#include "Components/ColliderComponent.hpp"
#include "SDL2/SDL_rect.h"

namespace Dyncep {
bool Collision::collidesAabb(const SDL_Rect &a, const SDL_Rect &b) {
  return a.x + a.w >= b.x && b.x + b.w >= a.x && a.y + a.h >= b.y &&
         b.y + b.h >= a.y;
}

bool Collision::collidesAabb(Components::ColliderComponent *a,
                             Components::ColliderComponent *b) {
  return collidesAabb(a->collider, b->collider);
}
} // namespace Dyncep

#include "Events/SDLEventHandler.hpp"

namespace Dyncep::Events {
SDLEventHandler::SDLEventHandler() = default;

void SDLEventHandler::handle(const SDL_Event &e) {
  switch (e.type) {
  case SDL_QUIT:
    this->handleQuit(e);
    break;
  case SDL_KEYDOWN:
    this->handleKeyDown(e);
    break;
  case SDL_KEYUP:
    this->handleKeyUp(e);
    break;
  default:
    break;
  }
}
} // namespace Dyncep::Events

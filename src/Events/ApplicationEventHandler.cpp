#include "Events/ApplicationEventHandler.hpp"
#include <iostream>

namespace Dyncep::Events {
ApplicationEventHandler::ApplicationEventHandler(Application *app)
    : SDLEventHandler() {
  this->app = app;
}

void ApplicationEventHandler::handleQuit(const SDL_Event &e) {
  this->app->stop();
}

void ApplicationEventHandler::handleKeyDown(const SDL_Event &e) {}

void ApplicationEventHandler::handleKeyUp(const SDL_Event &e) {}
} // namespace Dyncep::Events

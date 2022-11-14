#ifndef DYNCEP_SDL_ENGINE_EVENTS_APPLICATION_EVENT_HANDLER_HPP
#define DYNCEP_SDL_ENGINE_EVENTS_APPLICATION_EVENT_HANDLER_HPP

#include "Application.hpp"
#include "SDLEventHandler.hpp"

namespace Dyncep::Events {
class ApplicationEventHandler : public SDLEventHandler {
public:
  /**
   * @brief constructor
   */
  ApplicationEventHandler(Application *app);

protected:
  /**
   * @brief handle the SDL_QUIT event
   */
  void handleQuit(const SDL_Event &e) override;

  /**
   * @brief handle the SDL_KEYDOWN event
   *
   * @param e - the key down event
   */
  void handleKeyDown(const SDL_Event &e) override;

  /**
   * @brief handle the SDL_KEYUP event
   *
   * @param e - the key up event
   */
  void handleKeyUp(const SDL_Event &e) override;

  /**
   * @app the application this event handler works for
   */
  Application *app = nullptr;
};
} // namespace Dyncep::Events

#endif

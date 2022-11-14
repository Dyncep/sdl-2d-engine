#ifndef DYNCEP_SDL_ENGINE_EVENTS_SDL_EVENT_HANDLER_HPP
#define DYNCEP_SDL_ENGINE_EVENTS_SDL_EVENT_HANDLER_HPP

#include <SDL2/SDL_events.h>

namespace Dyncep::Events {
class SDLEventHandler {
public:
  /**
   * @brief constructor
   */
  SDLEventHandler();

  /**
   * @brief handle an event
   *
   * @param e - the event to handle
   */
  void handle(const SDL_Event &e);

protected:
  /**
   * @brief handle the SDL_QUIT event
   */
  virtual void handleQuit(const SDL_Event &e) = 0;

  /**
   * @brief handle the SDL_KEYDOWN event
   *
   * @param e - the key down event
   */
  virtual void handleKeyDown(const SDL_Event &e) = 0;

  /**
   * @brief handle the SDL_KEYUP event
   *
   * @param e - the key up event
   */
  virtual void handleKeyUp(const SDL_Event &e) = 0;
};
} // namespace Dyncep::Events

#endif

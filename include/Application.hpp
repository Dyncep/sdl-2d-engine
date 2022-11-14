#ifndef DYNCEP_SDL_ENGINE_APPLICATION_HPP
#define DYNCEP_SDL_ENGINE_APPLICATION_HPP

#include "Events/SDLEventHandler.hpp"
#include "Utility/Size.hpp"
#include <SDL2/SDL.h>
#include <string>

namespace Dyncep {
/**
 * @brief main instance of the application, may be a game, a desktop app,
 * whatever
 */
class Application {
public:
  /** @brief constructor
   * initializes SDL and creates a window and renderer
   *
   * @param window_size - the desired window size
   * @param window_title - the desired window title
   */
  Application(const Utility::Size &window_size,
              const std::string &window_title);

  /**
   * @brief destructor
   * cleans up resources (sdl, window, renderer)
   *
   */
  ~Application();

  /**
   * @brief update the application
   */
  void update();

  /**
   * @brief rerender the application
   */
  void render();

  /**
   * @brief check whether the application is still running
   *
   * @return bool
   */
  bool isRunning() { return is_running; }

  /**
   * @brief stop the application
   */
  void stop() { this->is_running = false; }

  /**
   * @brief polls and handles events
   */
  void handleEvents();

private:
  /**
   * @window the sdl window
   */
  SDL_Window *window = nullptr;

  /**
   * @renderer the sdl renderer
   */
  SDL_Renderer *renderer = nullptr;

  /**
   * @is_running whether the application is running or not
   */
  bool is_running = false;

  /**
   * @event_handler the event handler for the polled events
   */
  Events::SDLEventHandler *event_handler = nullptr;
};
} // namespace Dyncep

#endif

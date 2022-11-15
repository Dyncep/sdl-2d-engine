#ifndef DYNCEP_SDL_ENGINE_APPLICATION_HPP
#define DYNCEP_SDL_ENGINE_APPLICATION_HPP

#include "AppECSManager.hpp"
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
private:
  /**
   * @brief private constructor
   */
  Application();

public:
  /**
   * @brief retrieve the singleton instance of the application
   */
  static Application &getInstance();

  /**
   * @brief retrieve the sdl renderer of the application
   */
  static SDL_Renderer *getRenderer();

  /**
   * @brief retrieve the currently running event of the application
   */
  static SDL_Event &getEvent();

  /**
   * @brief retrieve the ecs manager of the application
   */
  static ECSManager &getECSManager();

  /** @brief constructor
   * initializes SDL and creates a window and renderer
   *
   * @param window_size - the desired window size
   * @param window_title - the desired window title
   */
  void initialize(const Utility::Size &window_size,
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
  virtual void update();

  /**
   * @brief rerender the application
   */
  virtual void render();

  /**
   * @brief check whether the application is still running
   *
   * @return bool
   */
  virtual bool isRunning() { return is_running; }

  /**
   * @brief stop the application
   */
  virtual void stop() { this->is_running = false; }

  /**
   * @brief polls and handles events
   */
  virtual void handleEvents();

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
   * @event the current sdl event
   */
  SDL_Event event{};

  /**
   * @ecs_manager the ecs manager
   */
  ECSManager ecs_manager{};

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

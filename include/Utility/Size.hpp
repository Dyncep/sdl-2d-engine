#ifndef DYNCEP_SDL_ENGINE_UTILITY_SIZE_HPP
#define DYNCEP_SDL_ENGINE_UTILITY_SIZE_HPP

namespace Dyncep::Utility {

/**
 * struct Size - struct used for sharing any sizes that use width and height as
 * their only dimensions
 */
struct Size {
  /**
   * @width the width
   */
  int width = {};

  /**
   * @height the height
   */
  int height = {};
};

}; // namespace Dyncep

#endif

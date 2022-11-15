#ifndef DYNCEP_SDL_ENGINE_TEXTURE_HELPER_HPP
#define DYNCEP_SDL_ENGINE_TEXTURE_HELPER_HPP

#include "SDL2/SDL.h"

namespace Dyncep {
class TextureHelper {
public:
  /**
   * @brief load a texture
   *
   * @param resource_path - the path to the resource
   * @return SDL_Texture*
   */
  static SDL_Texture *loadTexture(const char *resource_path);

  /**
   * @brief draw a texture
   *
   * @param texture - the desired texture to draw
   * @param src - the source rectangle
   * @param dest - the destination rectangle
   */
  static void render(SDL_Texture *texture, const SDL_Rect &src,
                     const SDL_Rect &dest);
};
}; // namespace Dyncep

#endif

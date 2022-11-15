#include "TextureHelper.hpp"
#include "Application.hpp"

#include "SDL2/SDL_image.h"

namespace Dyncep {

SDL_Texture *TextureHelper::loadTexture(const char *resource_path) {
  SDL_Surface *surface = IMG_Load(resource_path);
  SDL_Texture *texture =
      SDL_CreateTextureFromSurface(Application::getRenderer(), surface);
  SDL_FreeSurface(surface);
  return texture;
}

void TextureHelper::render(SDL_Texture *texture, const SDL_Rect &src,
                           const SDL_Rect &dest) {
  SDL_RenderCopy(Application::getRenderer(), texture, &src, &dest);
}
} // namespace Dyncep

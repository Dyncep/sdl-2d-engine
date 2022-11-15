#include "TextureHelper.hpp"

#include "SDL2/SDL_image.h"

namespace Dyncep {

TextureHelper::TextureHelper() = default;

TextureHelper &TextureHelper::getInstance() {
  static TextureHelper i;
  return i;
}

void TextureHelper::setRenderer(SDL_Renderer *renderer) {
  auto &i = getInstance();
  i.renderer = renderer;
}

SDL_Texture *TextureHelper::loadTexture(const char *resource_path) {
  SDL_Surface *surface = IMG_Load(resource_path);
  SDL_Texture *texture =
      SDL_CreateTextureFromSurface(getInstance().renderer, surface);
  SDL_FreeSurface(surface);
  return texture;
}

void TextureHelper::render(SDL_Texture *texture, const SDL_Rect &src,
                         const SDL_Rect &dest) {
  SDL_RenderCopy(getInstance().renderer, texture, &src, &dest);
}
} // namespace Dyncep

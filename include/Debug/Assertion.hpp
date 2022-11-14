#ifndef DYNCEP_SDL_ENGINE_DEBUG_ASSERTION_HPP
#define DYNCEP_SDL_ENGINE_DEBUG_ASSERTION_HPP

#include <string>

namespace Dyncep::Debug {

/**
 * @brief do an assertion and crash if necessary
 *
 * @param state - the state to assert
 * @param file - the file where the assertion is invoked
 * @param line - the line of the code where the assertion is invoked
 * @param message - the message to display if the assertion fails
 */
void doAssert(bool state, const std::string &file, int line,
              const std::string &message);

/** macro that invokes the doAssert function with the file and line macros **/
#define dAssert(state, message) doAssert(state, __FILE__, __LINE__, message);

} // namespace

#endif

#include "Debug/Assertion.hpp"
#include <sstream>
#include <iostream>


namespace Dyncep::Debug {

class AssertionFailedException : public std::runtime_error {
public:
  /**
   * @brief constructor
   *
   * @param what - the explanatory string for the virtual what() function
   */
  AssertionFailedException(const std::string &what) : std::runtime_error(what) {}
};

void doAssert(bool state, const std::string &file, int line,
              const std::string &message) {
  if (state) {
    return;
  }

  std::stringstream msg;
  msg << "Assertion failed\n"
      << "[" << file << ":" << line << "]: " << message;
  std::cout << msg.str() << std::endl;

  throw AssertionFailedException(message);
}
} // namespace Dyncep::Debug

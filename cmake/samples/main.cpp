#include <iostream>

#include <foo/foo.h>

int main(int /*argc*/, char** /*argv*/) {
  foo::C c = foo::protoFunction(42);
  std::cout << absl::StrCat(c) << std::endl;

  return 0;
}

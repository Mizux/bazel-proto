#include "foo/foo.h"

#include <iostream>
#include <string>
#include <utility>

namespace foo {
foo::C protoFunction(int level) {
  foo::C c;

  foo::A* a = c.mutable_a();
  a->set_name(std::to_string(level));

  foo::B* b = c.mutable_b();
  b->set_value(level);

  return c;
}
} // namespace foo

#include <iostream>

#include <foo/foo.h>
#include <bar/bar.h>
#include <foobar/foobar.h>

int main(int /*argc*/, char** /*argv*/) {
  foo::freeFunction(0);
  bar::freeFunction(1);
  foobar::freeFunction(2);
  std::cout << std::endl;

  foo::Foo::staticFunction(int{0});
  bar::Bar::staticFunction(int{1});
  foobar::FooBar::staticFunction(int{2});
  std::cout << std::endl;

  return 0;
}

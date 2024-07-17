#include "foo.h"
#include "foo/C.pb.h"

#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
#include <string>

namespace foo {

TEST(FooTest, ProtoFunction) {
 foo::C c = protoFunction(42);
EXPECT_TRUE(c.has_a());
EXPECT_EQ(c.a().name(), std::to_string(42));
EXPECT_TRUE(c.has_b());
EXPECT_EQ(c.b().value(), 42);
std::cerr << absl::StrCat(c);
}

} // namespace foo

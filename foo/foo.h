#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "foo/C.pb.h"

//! @namespace foo The Foo namespace
namespace foo {
//! @defgroup ProtoFunction Proto function usage.
/*! @brief Proto function in foo namespace.
 * @param level Scope level.*/
foo::C protoFunction(int level);
//! @}
} // namespace foo

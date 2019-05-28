#ifndef HYPER_CORE_COUNT_TRAILING_ZEROS_H
#define HYPER_CORE_COUNT_TRAILING_ZEROS_H

#include <stddef.h>

///
/// namespace Hyper
///
namespace Hyper {

  ///
  /// namespace Util
  ///
  namespace Util {

    ///
    /// function ctz(size_t v)
    /// comment Counts the number of trailing zeros of a binary number.
    ///
    /// param v The binary number to analyze.
    ///
    /// return size_t
    /// comment Returns the number of trailing zeros.
    ///
    size_t ctz (size_t v);
  } // namespace Core
} // namespace Hyper

#endif

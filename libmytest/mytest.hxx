#pragma once

#include <libmytest/export.hxx>

namespace mytest
{
  // The users of this testing framework are expected to register their test
  // functions like this:
  //
  // bool test1 ()
  // {
  //   ...
  // }
  //
  // static mytest::test test1_ (&test1);
  //
  struct test
  {
    const test* next;
    bool (*func) ();

    explicit test (bool (*) ());
  };

  LIBMYTEST_SYMEXPORT extern test* tests; // Head of the list.

  inline test::
  test (bool (*f) ())
      : next (tests), func (f)
  {
    tests = this;
  }
}

#include <libmytest/mytest.hxx>

#undef NDEBUG
#include <cassert>

using namespace mytest;

bool test1 ()
{
  return true;
}

static test test1_ (&test1);

bool test2 ()
{
  return false;
}

static test test2_ (&test2);

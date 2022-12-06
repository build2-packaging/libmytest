#include <libmytest/mytest.hxx>

#include <cstddef>
#include <iostream>

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

int main ()
{
  using namespace std;

  size_t succ (0);
  size_t fail (0);
  for (const test* t (tests); t != nullptr; t = t->next)
  {
    (t->func () ? succ : fail)++;
  }

  cerr << "success: " << succ << '\n'
       << "failure: " << fail << '\n';

  return fail == 0 ? 0 : 1;
}

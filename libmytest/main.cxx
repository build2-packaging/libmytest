#include <libmytest/mytest.hxx>

#include <cstddef>
#include <iostream>

int main ()
{
  using namespace std;
  using namespace mytest;

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

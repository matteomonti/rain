#include <iostream>

#include "bytewise/sort.hpp"

using namespace bytewise;

template <size_t ...> struct printer;

template <> struct printer <>
{
  static void print()
  {
    std :: cout << std :: endl;
  }
};

template <size_t first, size_t ... others> struct printer <first, others...>
{
  static void print()
  {
    std :: cout << first << "\t";
    printer <others...> :: print();
  }
};

template <size_t ... values> void print(bytewise :: ranges <values...>)
{
  printer <values...> :: print();
}

int main()
{
  print(sort <ranges <7, 1007, 2, 1002, 6, 1006, 1, 1001, 5, 1005, 0, 1000, 8, 1008, 3, 1003, 4, 1004>> :: type {});
}

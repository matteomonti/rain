#include <iostream>

#include "bytewise/sort.hpp"

using namespace bytewise;

template <typename> struct printer;

template <> struct printer <mask <>>
{
  static void print()
  {
    std :: cout << std :: endl;
  };
};

template <size_t first_offset, size_t first_size, bool first_swap, typename... tail> struct printer <mask <range <first_offset, first_size, first_swap>, tail...>>
{
  static void print()
  {
    std :: cout << "(" << first_offset << ", " << first_size << ", " << (first_swap ? "true" : "false") << ")\t";
    
    printer <mask <tail...>> :: print();
  };
};

template <typename type> void print(type)
{
  printer <type> :: print();
}

int main()
{
  print(sort <mask <range <6, 1006, true>, range <1, 1001, false>, range <3, 1003, false>, range <0, 1000, true>, range <4, 1004, true>, range <2, 1002, true>, range <5, 1005, false>>> :: type {});
}

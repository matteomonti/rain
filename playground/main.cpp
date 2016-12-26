#include "bytewise/compress.hpp"

#include <iostream>

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
  print(bytewise :: compress <mask <range <0, 4, false>, range <5, 4, false>, range <9, 3, true>, range <12, 4, false>, range <16, 4, false>>> :: type {});
}

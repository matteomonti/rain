#include <iostream>

#include "bytewise/range.hpp"

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
  print(mask <range <0, 12, false>, range <12, 3, true>> :: shift <1000> {});
}

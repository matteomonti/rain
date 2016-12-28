#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/valid.hpp"
#include "data/buffer.hpp"
#include "bytewise/arithmetic_visitor.hpp"

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

class myotherclass
{
  // Self
  
  typedef myotherclass self;
  
  // Members
  
  int a;
  int b[3];
  
public:
  
  // Bytewise
  
  bytewise(b);
};

class myclass
{
  // Self
  
  typedef myclass self;
  
  // Members
  
  myotherclass a[2];
  char b[44];
  
public:
  
  // Bytewise
  
  bytewise(a);
  bytewise(b);
};

int main()
{
  print(bytewise :: arithmetic_visitor <myclass> :: type {});
}

#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/valid.hpp"
#include "data/buffer.hpp"
#include "bytewise/arithmetic_visitor.hpp"

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
  
public:
  
  // Bytewise
  
  bytewise(a);
};

int main()
{
  print(bytewise :: arithmetic_visitor <myclass> :: type {});
}

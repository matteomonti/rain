#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/valid.hpp"
#include "data/buffer.hpp"
#include "bytewise/arithmetic_visitor.hpp"

class asd
{
  // Self
  
  typedef asd self;
  
  // Members
  
  int a;
  int b;
  
public:
  
  // Bytewise
  
  bytewise(a);
  bytewise(b);
};

class test
{
  // Self
  
  typedef test self;
  
  // Members
  
  int a;
  int b;
  double c;
  
  asd d;
  
public:
  
  // Bytewise
  
  bytewise(a);
  bytewise(b);
  bytewise(c);
  
  bytewise(d);
};

int main()
{
  std :: cout << std :: is_same <bytewise :: ranges <0, 4, 4, 4, 8, 8, 16, 4, 20, 4>, bytewise :: arithmetic_visitor <test> :: type> :: value << std :: endl;
}

#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/valid.hpp"
#include "data/buffer.hpp"
#include "bytewise/arithmetic_visitor.hpp"

/*class otherclass
{
  // Self
  
  typedef otherclass self;
  
  // Members
  
  buffer * a;
  
public:
  
  bytewise(a);
};

class myclass
{
  // Self
  
  typedef myclass self;
  
  // Members
  
  buffer a[12];
  int b;
  double c[44];
  otherclass d;
  
public:
  
  bytewise(a);
  bytewise(b);
  bytewise(c);
  bytewise(d);
};*/

class test
{
  // Self
  
  typedef test self;
  
  // Members
  
  int a;
  int b;
  double c;
  
public:
  
  // Bytewise
  
  bytewise(a);
  bytewise(b);
  bytewise(c);
};

int main()
{
  std :: cout << std :: is_same <bytewise :: arithmetic_visitor <test> :: ranges <0, 4, 4, 4, 8, 8>, bytewise :: arithmetic_visitor <test> :: type> :: value << std :: endl;
}

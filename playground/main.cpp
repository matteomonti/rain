#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/valid.hpp"
#include "data/buffer.hpp"

class otherclass
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
};

int main()
{
  std :: cout << bytewise :: valid <myclass> :: value << std :: endl;
}

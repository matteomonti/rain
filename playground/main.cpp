#include <iostream>

#include "data/buffer.hpp"
#include "bytewise/macro.hpp"

class myclass
{
  // Self
  
  typedef myclass self;
  
  // Members
  
  int a;
  int b;
  
public:
  
  bytewise(a);
  bytewise(b);
};

int main()
{
}

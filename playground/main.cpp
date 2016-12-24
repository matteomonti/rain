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
  double c[44];
  char d;
  
public:
  
  bytewise(a);
  bytewise(b);
  bytewise(c);
  bytewise(d);
};

int main()
{
  std :: cout << std :: is_same <int, myclass :: __bytewise__ <0, false> :: type> :: value << std :: endl;
}

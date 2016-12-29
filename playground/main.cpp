#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/arithmetic_visitor.hpp"

using namespace bytewise;

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

class myvisitor
{
public:
  
  template <size_t size> void arithmetic(const char (&block) [size])
  {
  }
};

void f(char (&x) [3])
{
}

int main()
{
  myclass x;
  
  f(((bytewise :: arithmetic_visitor <myvisitor, myclass> :: selector <4, 3> &) x).mask.body);
  
  // std :: cout << bytewise :: arithmetic_visitor <myvisitor, myclass> :: valid <3, false> :: value << std :: endl;
}

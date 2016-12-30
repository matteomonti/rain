#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/arithmetic_visitor.hpp"

using namespace bytewise;

/*class myotherclass
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
};*/

class myclass
{
  // Self
  
  typedef myclass self;
  
  // Members
  
  int a;
  
public:
  
  // Bytewise
  
  bytewise(a);
  
  // Constructors
  
  myclass(int _a) : a(_a)
  {
  }
};

class myvisitor
{
public:
  
  template <size_t size> void arithmetic(const arithmetic <size, true, false> & item)
  {
    for(size_t i = 0; i < size; i++)
      std :: cout << (unsigned int) (unsigned char) item[i] << "\t";
    
    std :: cout << std :: endl;
  }
};

int main()
{
  myvisitor visitor;
  myclass target(55);
  
  arithmetic_visitor <myvisitor, myclass> :: visit(visitor, target);
}

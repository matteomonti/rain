#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/arithmetic_visitor.hpp"

using namespace bytewise;

class myotherclass
{
  // Self
  
  typedef myotherclass self;
  
public:
  
  // Members
  
  char s[12];
  
  // Bytewise
  
  bytewise(s);
  
  // Constructors
  
  myotherclass(const char (&_s)[12])
  {
    memcpy(s, _s, 12);
  }
};

class myclass
{
  // Self
  
  typedef myclass self;
  
public:
  
  // Members
  
  int a;
  int b;
  
  // char separator;
  
  int c[3];
  myotherclass s;
  
  // Bytewise
  
  bytewise(a);
  bytewise(b);
  bytewise(c);
  bytewise(s);
  
  // Constructors
  
  myclass(int _a, int _b, int _c1, int _c2, int _c3, const char (&_s)[12]) : a(_a), b(_b), c{_c1, _c2, _c3}, s(_s)
  {
  }
};

class myvisitor
{
public:
  
  template <size_t size> void arithmetic(arithmetic <size, true, true> & item)
  {
    for(size_t i = 0; i < size; i++)
      std :: cout << (unsigned int) (unsigned char) item[i] << "\t";
    
    std :: cout << std :: endl;
    
    memset(item, '\0', size);
  }
};

int main()
{
  myvisitor visitor;
  myclass target(55, 46, 12, 13, 14, "emma watson");
  
  arithmetic_visitor <myvisitor, myclass> :: visit(visitor, target);
  
  std :: cout << "Output:" << std :: endl;
  
  std :: cout << target.a << std :: endl;
  std :: cout << target.b << std :: endl;
  std :: cout << target.c[0] << std :: endl;
  std :: cout << target.c[1] << std :: endl;
  std :: cout << target.c[2] << std :: endl;
  std :: cout << strlen(target.s.s) << std :: endl;
}

#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/arithmetic_visitor.hpp"
#include "bytewise/buffer_scanner.hpp"
#include "bytewise/buffer_visitor.hpp"
#include "data/buffer.hpp"

using namespace bytewise;

template <size_t ...> struct path_iterator;

template <size_t n, size_t ... ns> struct path_iterator <n, ns...>
{
  static void run()
  {
    std :: cout << n << "\t";
    path_iterator <ns...> :: run();
  }
};

template <> struct path_iterator <>
{
  static void run()
  {
    std :: cout << std :: endl;
  }
};

template <size_t ... ns> void print_path(path <ns...>)
{
  path_iterator <ns...> :: run();
}

template <typename...> struct map_iterator;

template <typename p, typename... ps> struct map_iterator <p, ps...>
{
  static void run()
  {
    print_path(p{});
    map_iterator <ps...> :: run();
  }
};

template <> struct map_iterator <>
{
  static void run()
  {
  }
};

template <typename... ps> void print_map(map <ps...>)
{
  map_iterator <ps...> :: run();
}

class myotherclass
{
  // Self
  
  typedef myotherclass self;
  
public:
  
  // Members
  
  int a;
  buffer b;
  buffer c[2];
  
  // Bytewise
  
  bytewise(a);
  bytewise(b);
  bytewise(c);
};

class myclass
{
  // Self
  
  typedef myclass self;
  
public:
  
  // Members
  
  int a;
  buffer b[3];
  myotherclass c;
  
  // Bytewise
  
  bytewise(a);
  bytewise(b);
  bytewise(c);
};

class myvisitor
{
public:
  
  template <bool multiple> void buffer(const :: buffer & target)
  {
    std :: cout << "(multiple: " << multiple << ") " << target << std :: endl;
  }
};

int main()
{
  myvisitor visitor;
  myclass object;
  
  object.b[0] = "Il primo funziona!";
  object.b[1] = "Il secondo funziona!";
  object.b[2] = "Il terzo funziona!";
  object.c.b = "Il quarto funziona!";
  object.c.c[0] = "Il quinto funziona!";
  object.c.c[1] = "Il sesto funziona!";
  
  buffer_visitor <myvisitor, myclass> :: visit(visitor, (const myclass &) object);
}

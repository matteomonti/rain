#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/arithmetic_visitor.hpp"
#include "bytewise/buffer_scanner.hpp"
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
  
  // Members
  
  int a;
  buffer b[12];
  buffer c;
  
public:
  
  // Bytewise
  
  bytewise(a);
  bytewise(b);
  bytewise(c);
};

class myclass
{
  // Self
  
  typedef myclass self;
  
  // Members
  
  int a;
  buffer b;
  myotherclass c;
  
public:
  
  // Bytewise
  
  bytewise(a);
  bytewise(b);
  bytewise(c);
};

int main()
{
  print_map(buffer_scanner <myclass> :: type {});
}

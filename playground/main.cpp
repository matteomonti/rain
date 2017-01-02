#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/arithmetic_visitor.hpp"
#include "bytewise/path.hpp"

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

int main()
{
  print_map(map <path <1, 2, 3>, path <4, 5, 6>, path <7, 8, 9>> :: append <map <path <10, 11, 12>>> :: type :: prepend <13> :: type{});
}

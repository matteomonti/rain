#include <iostream>

#include "bytewise/macro.hpp"
#include "bytewise/valid.hpp"
#include "data/buffer.hpp"
#include "bytewise/arithmetic_visitor.hpp"


int main()
{
  std :: cout << std :: is_same <bytewise :: arithmetic_visitor :: ranges <44, 2, 50, 4, 54, 2>, bytewise :: arithmetic_visitor :: append <bytewise :: arithmetic_visitor :: ranges <44, 2, 50, 4, 54, 2>, bytewise :: arithmetic_visitor :: ranges <>> :: type> :: value << std :: endl;
}

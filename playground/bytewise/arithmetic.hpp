#ifndef __playground__bytewise__arithmetic__hpp
#define __playground__bytewise__arithmetic__hpp

#include "arithmetic.h"

namespace bytewise
{
  // Casting
  
  template <size_t size, bool read, bool write> arithmetic <size, read, write> :: operator mutable_reference()
  {
    return this->_bytes;
  }
  
  template <size_t size, bool read, bool write> arithmetic <size, read, write> :: operator const_reference() const
  {
    return this->_bytes;
  }
};

#endif

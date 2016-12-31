#ifndef __playground__bytewise__endianess__hpp
#define __playground__bytewise__endianess__hpp

#include "endianess.h"

namespace bytewise
{
  // Static methods
  
  #if defined(__clang__) || defined(__GNUC__)
  
  template <> inline void endianess :: swap(const char (&source)[1], char (&destination)[1])
  {
    *destination = *source;
  }
  
  template <> inline void endianess :: swap(const char (&source)[2], char (&destination)[2])
  {
    ((int16_t &) destination) = __builtin_bswap16((const int16_t &) source);
  }
  
  template <> inline void endianess :: swap(const char (&source)[4], char (&destination)[4])
  {
    ((int32_t &) destination) = __builtin_bswap32((const int32_t &) source);
  }
  
  template <> inline void endianess :: swap(const char (&source)[8], char (&destination)[8])
  {
    ((int64_t &) destination) = __builtin_bswap64((const int64_t &) source);
  }
  
  #else
  
  // TODO: Implement performing solutions with bitshifts when no compiler shortcut is available.
  
  #endif
  
  template <size_t size> inline void endianess :: swap(const char (&source)[size], char (&destination)[size])
  {
    // TODO: Improve with template recursion.
    
    for(size_t i = 0; i < size; i++)
      destination[i] = source[size - 1 - i];
  }
};

#endif

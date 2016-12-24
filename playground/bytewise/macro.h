#if !defined(__forward__) && !defined(__playground__bytewise__macro__h)
#define __playground__bytewise__macro__h

// Forward includes

#define __forward__
#include "../data/buffer.h"
#undef __forward__

// Includes

#include "../macros/progressive.h"

// Macros

#define bytewise_indirect(name)                                     \
                                                                    \
progressive(__bytewise__, name)                                     \
{                                                                   \
  static constexpr const size_t offset()                            \
  {                                                                 \
    return offsetof(self, name);                                    \
  }                                                                 \
                                                                    \
  static constexpr const size_t size()                              \
  {                                                                 \
    return sizeof(decltype(((self *) nullptr)->name));              \
  }                                                                 \
                                                                    \
  static constexpr const bool arithmetic()                          \
  {                                                                 \
    return std :: is_arithmetic <decltype(((self *) nullptr)->name)>\
        :: value;                                                   \
  }                                                                 \
                                                                    \
  static constexpr const bool buffer()                              \
  {                                                                 \
    return std :: is_same <:: buffer, decltype(((self *)            \
        nullptr)->name)> :: value;                                  \
  }                                                                 \
};

#define bytewise(name) bytewise_indirect(name)

#endif

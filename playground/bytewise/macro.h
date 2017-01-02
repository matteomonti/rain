#if !defined(__forward__) && !defined(__playground__bytewise__macro__h)
#define __playground__bytewise__macro__h

// Forward includes

#define __forward__
#include "../data/buffer.h"
#include "buffer_visitor.h"
#undef __forward__

// Includes

#include "../macros/progressive.h"

// Macros

#define bytewise_indirect(name)                                     \
                                                                    \
progressive(__bytewise__, name)                                     \
{                                                                   \
  template <typename, typename> friend class :: bytewise            \
      :: buffer_visitor;                                            \
                                                                    \
  typedef decltype(self :: name) type;                              \
                                                                    \
  static constexpr const size_t offset()                            \
  {                                                                 \
    return offsetof(self, name);                                    \
  }                                                                 \
                                                                    \
private:                                                            \
                                                                    \
  static inline auto & get(self & that)                             \
  {                                                                 \
    return that.name;                                               \
  }                                                                 \
                                                                    \
  static inline const auto & get(const self & that)                 \
  {                                                                 \
    return that.name;                                               \
  }                                                                 \
};

#define bytewise(name) bytewise_indirect(name)

#endif

// Forward declaration

namespace bytewise
{
	template <typename, typename> class arithmetic_visitor;
};

#if !defined(__forward__) && !defined(__playground__bytewise__arithmetic_visitor__h)
#define __playground__bytewise__arithmetic_visitor__h

// Libraries

#include <stddef.h>

// Includes

#include "arithmetic_scanner.h"
#include "compress.h"

namespace bytewise
{
	template <typename visitor, typename target> class arithmetic_visitor
	{
  public:
    
    // Service nested classes
    
    template <size_t size, bool mutable_reference> struct valid
    {
      template <size_t csize, bool cmutable_reference> struct const_conditional
      {
        template <typename type, void (type :: *) (typename std :: conditional <cmutable_reference, char (&)[csize], const char (&)[csize]> :: type)> class helper;
        
        template <typename type> static uint8_t sfinae(...);
        template <typename type> static uint32_t sfinae(helper <type, &type :: arithmetic> *);
        
        static constexpr bool value = std :: is_same <uint32_t, decltype(sfinae <visitor> (0))> :: value;
      };
      
      static constexpr bool value = const_conditional <size, true> :: value || (!mutable_reference && const_conditional <size, false> :: value);
    };
  };
};

#endif

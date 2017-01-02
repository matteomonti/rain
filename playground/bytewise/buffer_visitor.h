// Forward declaration

namespace bytewise
{
	template <typename, typename> class buffer_visitor;
};

#if !defined(__forward__) && !defined(__playground__bytewise__buffer_visitor__h)
#define __playground__bytewise__buffer_visitor__h

// Libraries

#include <type_traits>
#include <stdint.h>

// Forward includes

#define __forward__
#include "../data/buffer.h"
#undef __forward__

namespace bytewise
{
	template <typename visitor_type, typename target_type> class buffer_visitor
	{
  public:
    
    // Service nested classes
    
    template <bool const_reference, bool multiple> struct valid
    {
      template <bool cconst_reference, bool cmultiple> struct const_conditional
      {
        template <typename type, void (type :: *) (typename std :: conditional <cconst_reference, const :: buffer &, :: buffer &> :: type)> class helper;
        
        template <typename type> static uint8_t sfinae(...);
        template <typename type> static uint32_t sfinae(helper <type, &type :: template buffer <cmultiple>> *);
        
        static constexpr bool value = std :: is_same <uint32_t, decltype(sfinae <visitor_type> (0))> :: value;
      };
      
      static constexpr bool value = const_conditional <const_reference, multiple> :: value || const_conditional <true, multiple> :: value;
    };
	};
};

#endif

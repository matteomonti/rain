// Forward declaration

namespace bytewise
{
	template <typename> class valid;
};

#if !defined(__forward__) && !defined(__playground__bytewise__valid__h)
#define __playground__bytewise__valid__h

// Forward includes

#define __forward__
#include "../data/buffer.h"
#undef __forward__

// Includes

#include "count.h"

namespace bytewise
{
  // Service nested classes
  
	template <typename type> class valid
	{
  public:
    
    template <ssize_t, bool> class valid_member;
    
    template <bool dummy> class valid_member <-1, dummy>
    {
    public:
      
      // Static members
      
      static constexpr bool value = true;
    };
    
    template <ssize_t index, bool dummy> class valid_member
    {
      // Typedefs
      
      typedef typename std :: remove_all_extents <typename type :: template __bytewise__ <index, false> :: type> :: type member;
     
    public:
      
      // Static members
      
      static constexpr bool value = valid_member <index - 1, false> :: value && (std :: is_arithmetic <member> :: value || std :: is_same <buffer,member> :: value || (std :: is_class <member> :: value && valid <member> :: value));
    };
    
  public:
    
    // Static members
    
    static constexpr bool value = valid_member <((ssize_t) (count <type> :: value)) - 1, false> :: value;
	};
};

#endif

// Forward declaration

namespace bytewise
{
	template <typename> class buffer_scanner;
};

#if !defined(__forward__) && !defined(__playground__bytewise__buffer_scanner__h)
#define __playground__bytewise__buffer_scanner__h

// Forward includes

#define __forward__
#include "../data/buffer.h"
#undef __forward__

// Libraries

#include <stdio.h>

// Includes

#include "path.h"
#include "count.h"

namespace bytewise
{
	template <typename btype> class buffer_scanner
	{
  public:
    
    // Service nested classes
    
    template <ssize_t, bool> struct member_iterator;
    
    template <bool dummy> struct member_iterator <-1, dummy>
    {
      typedef map <> type;
    };
    
    template <ssize_t index, bool dummy> struct member_iterator
    {
      typedef typename btype :: template __bytewise__ <index, false> :: type member_type;
      
      typedef typename std :: remove_all_extents <member_type> :: type root_type;
      
      template <bool, bool, bool> struct conditional;
      
      template <bool cdummy> struct conditional <true, true, cdummy>
      {
        typedef map <path <index>> type;
      };
      
      template <bool cdummy> struct conditional <true, false, cdummy>
      {
        typedef typename buffer_scanner <root_type> :: type :: template prepend <index> :: type type;
      };
      
      template <bool cdummy> struct conditional <false, false, cdummy>
      {
        typedef map <> type;
      };
      
      typedef typename conditional <std :: is_class <root_type> :: value, std :: is_same <root_type, :: buffer> :: value, false> :: type member_map;
      
      typedef typename member_iterator <index - 1, false> :: type :: template append <member_map> :: type type;
    };
    
    typedef typename member_iterator <(ssize_t) (count <btype> :: value) - 1, false> :: type type;
	};
};

#endif

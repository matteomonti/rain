// Forward declaration

namespace bytewise
{
	template <typename> class compress;
};

#if !defined(__forward__) && !defined(__playground__bytewise__compress__h)
#define __playground__bytewise__compress__h

// Libraries

#include <type_traits>

// Includes

#include "range.h"

namespace bytewise
{
	template <typename first, typename ... tail> class compress <mask <first, tail...>>
	{
  public:
    
    // Service nested classes
    
    template <bool, typename> struct reverse;
    
    template <bool rdummy> struct reverse <rdummy, mask <>>
    {
      typedef mask <> type;
    };
    
    template <bool rdummy, typename rfirst, typename ... rtail> struct reverse <rdummy, mask <rfirst, rtail...>>
    {
      typedef typename append <typename reverse <false, mask <rtail...>> :: type, rfirst> :: type type;
    };
    
    template <typename, typename> struct merge;
    
    template <size_t toffset, size_t tsize, bool tswap, typename ... ttail> struct merge <mask <range <toffset, tsize, tswap>, ttail...>, mask <>>
    {
      typedef mask <range <toffset, tsize, tswap>, ttail...> type;
    };
    
    template <size_t toffset, size_t tsize, bool tswap, typename... ttail, size_t soffset, size_t ssize, bool sswap, typename... stail> struct merge <mask <range <toffset, tsize, tswap>, ttail...>, mask <range <soffset, ssize, sswap>, stail...>>
    {
      static constexpr bool mergeable = !tswap && !sswap && (soffset == toffset + tsize);
      
      typedef typename std :: conditional <mergeable, mask <>, mask <range <soffset, ssize, sswap>>> :: type thead;
      
      typedef typename merge <typename append <thead, mask <range <toffset, (mergeable ? tsize + ssize : tsize), tswap>, ttail...>> :: type, mask <stail...>> :: type type;
    };
    
    // Static members
    
    typedef typename reverse <false, typename merge <mask <first>, mask <tail...>> :: type> :: type type;
	};
};

#endif

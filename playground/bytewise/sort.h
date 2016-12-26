// Forward declaration

namespace bytewise
{
	template <typename> class sort;
};

#if !defined(__forward__) && !defined(__playground__bytewise__sort__h)
#define __playground__bytewise__sort__h

// Libraries

#include <limits>

// Includes

#include "range.h"

namespace bytewise
{
  template <typename ... ranges> class sort <mask <ranges...>>
	{
    // Private static members
    
    static constexpr size_t cap = std :: numeric_limits <size_t> :: max();
    
    // Service nested classes
    
    template <typename, size_t, size_t, bool, typename ...> struct minsup;
    
    template <size_t min, size_t size_dummy, size_t swap_dummy, size_t offset, size_t size, bool swap> struct minsup <range <min, size_dummy, swap_dummy>, offset, size, swap>
    {
      typedef range <offset, size, swap> type;
    };
    
    template <size_t min, size_t size_dummy, bool swap_dummy, size_t offset, size_t size, bool swap, size_t foffset, size_t fsize, bool fswap, typename ... tail> struct minsup <range <min, size_dummy, swap_dummy>, offset, size, swap, range <foffset, fsize, fswap>, tail...>
    {
      static constexpr bool replace = foffset > min && foffset < offset;
      
      typedef typename minsup <range <min, size_dummy, swap_dummy>, replace ? foffset : offset, replace ? fsize : size, replace ? fswap : swap, tail...> :: type type;
    };
    
    template <size_t offset, size_t size, bool swap> struct minsup <range <cap, cap, false>, offset, size, swap>
    {
      typedef range <offset, size, swap> type;
    };
    
    template <size_t offset, size_t size, bool swap, size_t foffset, size_t fsize, bool fswap, typename ... tail> struct minsup <range <cap, cap, false>, offset, size, swap, range <foffset, fsize, fswap>, tail...>
    {
      static constexpr bool replace = foffset < offset;
      
      typedef typename minsup <range <cap, cap, false>, replace ? foffset : offset, replace ? fsize : size, replace ? fswap : swap, tail...> :: type type;
    };
    
    template <size_t, typename> struct iterator;
    
    template <typename previous> struct iterator <0, previous>
    {
      typedef mask <> type;
    };
    
    template <size_t index, typename previous> struct iterator
    {
      typedef typename minsup <previous, cap, cap, false, ranges...> :: type needle;
      typedef typename append <needle, typename iterator <index - 1, needle> :: type> :: type type;
    };
    
  public:
    
    // Static members
    
    typedef typename iterator <sizeof...(ranges), range <cap, cap, false>> :: type type;
	};
};

#endif

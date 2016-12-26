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

#include "ranges.h"

namespace bytewise
{
  template <size_t ... values> class sort <ranges <values...>>
	{
  public:
    
    // Private static members
    
    static constexpr size_t cap = std :: numeric_limits <size_t> :: max();
    
    // Service nested classes
    
    template <typename, size_t, size_t, size_t ...> struct minsup;
    
    template <size_t min, size_t dummy, size_t offset, size_t size> struct minsup <ranges <min, dummy>, offset, size>
    {
      typedef ranges <offset, size> type;
    };
    
    template <size_t min, size_t dummy, size_t offset, size_t size, size_t foffset, size_t fsize, size_t ... tail> struct minsup <ranges <min, dummy>, offset, size, foffset, fsize, tail...>
    {
      typedef typename minsup <ranges <min, dummy>, (foffset > min && foffset < offset) ? foffset : offset, (foffset > min && foffset < offset) ? fsize : size, tail...> :: type type;
    };
    
    template <size_t offset, size_t size> struct minsup <ranges <>, offset, size>
    {
      typedef ranges <offset, size> type;
    };
    
    template <size_t offset, size_t size, size_t foffset, size_t fsize, size_t ... tail> struct minsup <ranges <>, offset, size, foffset, fsize, tail...>
    {
      typedef typename minsup <ranges <>, (foffset < offset) ? foffset : offset, (foffset < offset) ? fsize : size, tail...> :: type type;
    };
    
    template <ssize_t, typename> struct iterator;
    
    template <typename previous> struct iterator <-1, previous>
    {
      typedef ranges <> type;
    };
    
    template <ssize_t index, typename previous> struct iterator
    {
      typedef typename minsup <previous, cap, cap, values...> :: type needle;
      typedef typename append <needle, typename iterator <index - 1, needle> :: type> :: type type;
    };
    
    typedef typename iterator <((ssize_t)(sizeof...(values) / 2)) - 1, ranges <>> :: type type;
	};
};

#endif

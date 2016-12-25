// Forward declaration

namespace bytewise
{
	template <typename> class arithmetic_visitor;
};

#if !defined(__forward__) && !defined(__playground__bytewise__arithmetic_visitor__h)
#define __playground__bytewise__arithmetic_visitor__h

// Includes

#include "ranges.h"

namespace bytewise
{
	template <typename atype> class arithmetic_visitor
	{
  public:
    
    // Service nested classes
    
    template <ssize_t, bool> struct member_iterator;
    
    template <bool mdummy> struct member_iterator <-1, mdummy>
    {
      typedef ranges <> type;
    };
    
    template <ssize_t index, bool mdummy> struct member_iterator
    {
      typedef typename atype :: template __bytewise__ <index, false> :: type member_type;
      
      typedef typename std :: remove_all_extents <member_type> :: type root_type;
      
      template <ssize_t, typename> struct repeat;
      
      template <size_t ... values> struct repeat <-1, ranges <values...>>
      {
        typedef ranges <> type;
      };
      
      template <ssize_t reps, size_t ... values> struct repeat <reps, ranges <values...>>
      {
        typedef typename append <typename repeat <reps - 1, ranges <values...>> :: type, typename ranges <values...> :: template shift <sizeof(root_type) * reps>> :: type type;
      };
      
      template <bool, bool, bool, bool> struct conditional;
      
      template <bool, bool, bool, bool> struct conditional
      {
        typedef ranges <> type;
      };
      
      template <bool cdummy> struct conditional <false, true, false, cdummy>
      {
        typedef ranges <atype :: template __bytewise__ <index, false> :: offset(), sizeof(root_type)> type;
      };
      
      template <bool cdummy> struct conditional <false, false, true, cdummy>
      {
        typedef typename arithmetic_visitor <root_type> :: type :: template shift <atype :: template __bytewise__ <index, false> :: offset()> type;
      };
      
      template <bool is_arithmetic, bool is_class, bool cdummy> struct conditional <true, is_arithmetic, is_class, cdummy>
      {
        typedef typename repeat <sizeof(member_type) / sizeof(root_type) - 1, typename conditional <false, is_arithmetic, is_class, false> :: type> :: type type;
      };
      
      typedef typename conditional <std :: is_array <member_type> :: value, std :: is_arithmetic <root_type> :: value, std :: is_class <root_type> :: value, false> :: type member_ranges;
      
      typedef typename append <typename member_iterator <index - 1, false> :: type, member_ranges> :: type type;
    };
    
    typedef typename member_iterator <((ssize_t)(count <atype> :: value)) - 1, false> :: type type;
	};
};

#endif

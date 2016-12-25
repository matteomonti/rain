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
      template <bool, bool, bool> struct conditional;
      
      template <bool, bool, bool> struct conditional
      {
        typedef ranges <> type;
      };
      
      template <bool cdummy> struct conditional <true, false, cdummy>
      {
        typedef ranges <atype :: template __bytewise__ <index, false> :: offset(), sizeof(typename atype :: template __bytewise__ <index, false> :: type)> type;
      };
      
      template <bool cdummy> struct conditional <false, true, cdummy>
      {
        typedef typename arithmetic_visitor <typename atype :: template __bytewise__ <index, false> :: type> :: type :: template shift <atype :: template __bytewise__ <index, false> :: offset()> type;
      };
      
      typedef typename conditional <std :: is_arithmetic <typename atype :: template __bytewise__ <index, false> :: type> :: value, std :: is_class <typename atype :: template __bytewise__ <index, false> :: type> :: value, false> :: type member_type;
      
      typedef typename append <typename member_iterator <index - 1, false> :: type, member_type> :: type type;
    };
    
    typedef typename member_iterator <count <atype> :: value - 1, false> :: type type;
	};
};

#endif

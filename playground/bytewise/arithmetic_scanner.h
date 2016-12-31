// Forward declaration

namespace bytewise
{
	template <typename> class arithmetic_scanner;
};

#if !defined(__forward__) && !defined(__playground__bytewise__arithmetic_scanner__h)
#define __playground__bytewise__arithmetic_scanner__h

// Includes

#include "range.h"
#include "count.h"
#include "endianess.h"

namespace bytewise
{
	template <typename atype> class arithmetic_scanner
	{
    // Service nested classes
    
    template <ssize_t, bool> struct member_iterator;
    
    template <bool mdummy> struct member_iterator <-1, mdummy>
    {
      typedef mask <> type;
    };
    
    template <ssize_t index, bool mdummy> struct member_iterator
    {
      typedef typename atype :: template __bytewise__ <index, false> :: type member_type;
      
      typedef typename std :: remove_all_extents <member_type> :: type root_type;
      
      static constexpr size_t offset = atype :: template __bytewise__ <index, false> :: offset();
      
      template <ssize_t, typename> struct repeat;
      
      template <typename ... ranges> struct repeat <-1, mask <ranges...>>
      {
        typedef mask <> type;
      };
      
      template <ssize_t reps, typename ... ranges> struct repeat <reps, mask <ranges...>>
      {
        typedef typename append <typename repeat <reps - 1, mask <ranges...>> :: type, typename mask <ranges...> :: template shift <sizeof(root_type) * reps>> :: type type;
      };
      
      template <bool, bool, bool, bool> struct conditional;
      
      template <bool, bool, bool, bool> struct conditional
      {
        typedef mask <> type;
      };
      
      template <bool cdummy> struct conditional <false, true, false, cdummy>
      {
        typedef mask <range <offset, sizeof(root_type), (endianess :: foreign && sizeof(root_type) > 1)>> type;
      };
      
      template <bool cdummy> struct conditional <false, false, true, cdummy>
      {
        typedef typename arithmetic_scanner <root_type> :: type :: template shift <offset> type;
      };
      
      template <bool is_arithmetic, bool is_class, bool cdummy> struct conditional <true, is_arithmetic, is_class, cdummy>
      {
        template <bool, bool> struct conditional_shortcut;
        
        template <bool sdummy> struct conditional_shortcut <true, sdummy>
        {
          typedef mask <range <offset, sizeof(member_type), false>> type;
        };
        
        template <bool sdummy> struct conditional_shortcut <false, sdummy>
        {
          typedef typename repeat <sizeof(member_type) / sizeof(root_type) - 1, typename conditional <false, is_arithmetic, is_class, false> :: type> :: type type;
        };
        
        typedef typename conditional_shortcut <is_arithmetic && sizeof(root_type) == 1, false> :: type type;
      };
      
      typedef typename conditional <std :: is_array <member_type> :: value, std :: is_arithmetic <root_type> :: value, std :: is_class <root_type> :: value, false> :: type member_ranges;
      
      typedef typename append <typename member_iterator <index - 1, false> :: type, member_ranges> :: type type;
    };
    
  public:
    
    // Static members
    
    typedef typename member_iterator <((ssize_t)(count <atype> :: value)) - 1, false> :: type type;
	};
};

#endif

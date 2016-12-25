// Forward declaration

namespace bytewise
{
	template <typename> class arithmetic_visitor;
};

#if !defined(__forward__) && !defined(__playground__bytewise__arithmetic_visitor__h)
#define __playground__bytewise__arithmetic_visitor__h

namespace bytewise
{
	template <typename atype> class arithmetic_visitor
	{
  public:
    
    // Service nested classes
    
    template <size_t ...> struct ranges;
    
    template <size_t, size_t, typename> struct shift_ranges;
    
    template <size_t shift, size_t first_offset, size_t first_size, size_t ... tail> struct shift_ranges <0, shift, ranges <first_offset, first_size, tail...>>
    {
      typedef ranges <first_offset, first_size, tail...> type;
    };
    
    template <size_t steps, size_t shift, size_t first_offset, size_t first_size, size_t ... tail> struct shift_ranges <steps, shift, ranges <first_offset, first_size, tail...>>
    {
      typedef typename shift_ranges <steps - 1, shift, ranges <tail..., first_offset + shift, first_size>> :: type type;
    };
    
    template <size_t ... values> struct ranges
    {
      template <size_t shift_value> using shift = typename shift_ranges <sizeof...(values) / 2, shift_value, ranges <values...>> :: type;
    };
    
    template <typename, typename> struct append;
    
    template <size_t ... left_values, size_t ... right_values> struct append <ranges <left_values...>, ranges <right_values...>>
    {
      typedef ranges <left_values..., right_values...> type;
    };
    
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
        typedef typename arithmetic_visitor <typename atype :: template __bytewise__ <index> :: type> :: type :: template shift <atype :: template __bytewise__ <index> :: offset()> type;
      };
      
      typedef typename conditional <std :: is_arithmetic <typename atype :: template __bytewise__ <index, false> :: type> :: value, std :: is_class <typename atype :: template __bytewise__ <index, false> :: type> :: value, false> :: type member_type;
      
      typedef typename append <typename member_iterator <index - 1, false> :: type, member_type> :: type type;
    };
    
    typedef typename member_iterator <count <atype> :: value - 1, false> :: type type;
	};
};

#endif

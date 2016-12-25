// Forward declaration

namespace bytewise
{
	template <size_t ...> struct ranges;
  template <typename, typename> struct append;
};

#if !defined(__forward__) && !defined(__playground__bytewise__ranges__h)
#define __playground__bytewise__ranges__h

namespace bytewise
{
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
};

#endif

// Forward declaration

namespace bytewise
{
  template <size_t, size_t, bool> struct range;
	template <typename ...> struct mask;
  template <typename, typename> struct append;
};

#if !defined(__forward__) && !defined(__playground__bytewise__range__h)
#define __playground__bytewise__range__h

namespace bytewise
{
  template <size_t, size_t, typename> struct shift_mask;
  
  template <size_t steps, size_t shift> struct shift_mask <steps, shift, mask <>>
  {
    typedef mask <> type;
  };
  
  template <size_t shift, size_t first_offset, size_t first_size, bool first_swap, typename ... tail> struct shift_mask <0, shift, mask <range <first_offset, first_size, first_swap>, tail...>>
  {
    typedef mask <range <first_offset, first_size, first_swap>, tail...> type;
  };
  
  template <size_t steps, size_t shift, size_t first_offset, size_t first_size, bool first_swap, typename ... tail> struct shift_mask <steps, shift, mask <range <first_offset, first_size, first_swap>, tail...>>
  {
    typedef typename shift_mask <steps - 1, shift, mask <tail..., range <first_offset + shift, first_size, first_swap>>> :: type type;
  };
  
  template <typename ... ranges> struct mask
  {
    template <size_t shift_value> using shift = typename shift_mask <sizeof...(ranges), shift_value, mask <ranges...>> :: type;
  };
  
  template <typename, typename> struct append;
  
  template <typename ... left_values, typename ... right_values> struct append <mask <left_values...>, mask <right_values...>>
  {
    typedef mask <left_values..., right_values...> type;
  };
  
  template <typename ... left_values, typename right_range> struct append <mask <left_values...>, right_range>
  {
    typedef mask <left_values..., right_range> type;
  };
  
  template <typename left_range, typename ... right_values> struct append <left_range, mask <right_values...>>
  {
    typedef mask <left_range, right_values...> type;
  };
};

#endif

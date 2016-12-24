// Forward declaration

namespace bytewise
{
	template <typename> class count;
};

#if !defined(__forward__) && !defined(__playground__bytewise__count__h)
#define __playground__bytewise__count__h

namespace bytewise
{
	template <typename type> class count
	{
    // Service nested classes
    
    template <size_t index> class exists
    {
      // Sfinae
      
      template <bool dummy> struct helper {};
      template <typename stype> static uint8_t sfinae(...);
      template <typename stype> static uint32_t sfinae(helper <stype :: template __bytewise__ <index, false> :: __exists__> *);
      
    public:
      
      // Static members
      
      static constexpr bool value = std :: is_same <uint32_t, decltype(sfinae <type> (0))> :: value;
    };
    
    template <bool, size_t> class conditional_iterator;
    
    template <size_t index> class conditional_iterator <false, index>
    {
    public:
      
      // Static members
      
      static constexpr size_t value = 0;
    };
    
    template <size_t index> class conditional_iterator <true, index>
    {
    public:
      
      // Static members
      
      static constexpr size_t value = conditional_iterator <exists <index + 1> :: value, index + 1> :: value + 1;
    };
    
  public:
    
    // Static members
    
    static constexpr size_t value = conditional_iterator <exists <0> :: value, 0> :: value;
	};
};

#endif

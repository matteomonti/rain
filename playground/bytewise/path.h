// Forward declaration

namespace bytewise
{
	template <size_t ...> class path;
  template <typename...> class map;
};

#if !defined(__forward__) && !defined(__playground__bytewise__path__h)
#define __playground__bytewise__path__h

namespace bytewise
{
	template <size_t ...> class path
	{
	};
  
  template <typename... paths> class map
  {
  public:
    
    static constexpr size_t size = sizeof...(paths);
    
    template <typename> struct append;
    
    template <typename... apaths> struct append <map <apaths...>>
    {
      typedef map <paths..., apaths...> type;
    };
    
  private:
    
    template <size_t, typename...> struct prepend_iterator;
    
    template <size_t head, size_t ... ns, typename... tail> struct prepend_iterator <head, path <ns...>, tail...>
    {
      typedef typename map <path <head, ns...>> :: template append <typename prepend_iterator <head, tail...> :: type> :: type type;
    };
    
    template <size_t head> struct prepend_iterator <head>
    {
      typedef map <> type;
    };
    
  public:
    
    template <size_t head> struct prepend
    {
      typedef typename prepend_iterator <head, paths...> :: type type;
    };
  };
};

#endif

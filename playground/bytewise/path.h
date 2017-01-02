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
    
    template <typename> struct append;
    
    template <typename... apaths> struct append <map <apaths...>>
    {
      typedef map <paths..., apaths...> type;
    };
  };
};

#endif

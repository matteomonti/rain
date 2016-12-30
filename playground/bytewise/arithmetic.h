// Forward declaration

namespace bytewise
{
	template <size_t, bool, bool> class arithmetic;
};

#if !defined(__forward__) && !defined(__playground__bytewise__arithmetic__h)
#define __playground__bytewise__arithmetic__h

namespace bytewise
{
	template <size_t size, bool read = false, bool write = false> class arithmetic
	{
    // Typedefs
    
    typedef char (&mutable_reference)[size];
    typedef const char (&const_reference)[size];
    
    // Members
    
    char _bytes[size];
    
  public:
    
    // Casting
    
    operator mutable_reference();
    operator const_reference() const;
	};
};

#endif

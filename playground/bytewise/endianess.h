// Forward declaration

namespace bytewise
{
	class endianess;
};

#if !defined(__forward__) && !defined(__playground__bytewise__endianess__h)
#define __playground__bytewise__endianess__h

namespace bytewise
{
	class endianess
	{
  public:
    
    // Nested classes
    
    enum type {little, big};
    
    // Macros
    
    #ifdef __BYTE_ORDER
    #if __BYTE_ORDER == __BIG_ENDIAN
        #define __playground__bytewise__endianess__endianess big
    #endif
        
    #if __BYTE_ORDER == __LITTLE_ENDIAN
        #define __playground__bytewise__endianess__endianess little
    #endif
    #endif
        
    #ifdef __BIG_ENDIAN__
        #define __playground__bytewise__endianess__endianess big
    #endif
        
    #ifdef __LITTLE_ENDIAN__
        #define __playground__bytewise__endianess__endianess little
    #endif
        
    #ifdef __ARMEB__
        #define __playground__bytewise__endianess__endianess big
    #endif
        
    #ifdef __ARMEL__
        #define __playground__bytewise__endianess__endianess little
    #endif
        
    #ifdef __THUMBEB__
        #define __playground__bytewise__endianess__endianess big
    #endif
        
    #ifdef __THUMBEL__
        #define __playground__bytewise__endianess__endianess little
    #endif
        
    #ifdef __AARCH64EB__
        #define __playground__bytewise__endianess__endianess big
    #endif
        
    #ifdef __AARCH64EL__
        #define __playground__bytewise__endianess__endianess little
    #endif
        
    #ifdef _MIPSEB
        #define __playground__bytewise__endianess__endianess big
    #endif
        
    #ifdef _MIPSEL
        #define __playground__bytewise__endianess__endianess little
    #endif
        
    #ifdef __MIPSEB
        #define __playground__bytewise__endianess__endianess big
    #endif
        
    #ifdef __MIPSEL
        #define __playground__bytewise__endianess__endianess little
    #endif
        
    #ifdef __MIPSEB__
        #define __playground__bytewise__endianess__endianess big
    #endif
        
    #ifdef __MIPSEL__
        #define __playground__bytewise__endianess__endianess little
    #endif
        
    #ifdef __BYTE_ORDER__
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        #define __playground__bytewise__endianess__endianess big
    #endif
        
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        #define __playground__bytewise__endianess__endianess little
    #endif
    #endif
        
    #ifdef __FLOAT_WORD_ORDER__
    #if __FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__
        #define __playground__bytewise__endianess__endianess big
    #endif
        
    #if __FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__
        #define __playground__bytewise__endianess__endianess little
    #endif
    #endif
    
    // Static members
    
    static constexpr type local = __playground__bytewise__endianess__endianess;
    static constexpr type network = big;
    
    static constexpr bool swap = (local != network);
	};
};

#endif

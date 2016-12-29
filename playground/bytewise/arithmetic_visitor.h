// Forward declaration

namespace bytewise
{
	template <typename, typename> class arithmetic_visitor;
};

#if !defined(__forward__) && !defined(__playground__bytewise__arithmetic_visitor__h)
#define __playground__bytewise__arithmetic_visitor__h

// Libraries

#include <stddef.h>

// Includes

#include "arithmetic_scanner.h"
#include "compress.h"

namespace bytewise
{
	template <typename visitor_type, typename target_type> class arithmetic_visitor
	{
  public:
    
    // Service nested classes
    
    template <size_t size, bool mutable_reference> struct valid
    {
      template <size_t csize, bool cmutable_reference> struct const_conditional
      {
        template <typename type, void (type :: *) (typename std :: conditional <cmutable_reference, char (&)[csize], const char (&)[csize]> :: type)> class helper;
        
        template <typename type> static uint8_t sfinae(...);
        template <typename type> static uint32_t sfinae(helper <type, &type :: arithmetic> *);
        
        static constexpr bool value = std :: is_same <uint32_t, decltype(sfinae <visitor_type> (0))> :: value;
      };
      
      static constexpr bool value = const_conditional <size, true> :: value || (!mutable_reference && const_conditional <size, false> :: value);
    };
    
    template <size_t offset, size_t size> union selector
    {
      target_type item;
      
      #pragma pack(push, 1)
      struct mask_type
      {
        char head[offset];
        char body[size];
        char tail[sizeof(target_type) - offset - size];
      };
      #pragma pack(pop)
      
      mask_type mask;
    };
    
    template <typename, bool> struct iterator;
    
    template <bool dummy> struct iterator <mask <>, dummy>
    {
      static inline void run(visitor_type &, target_type &);
      static inline void run(visitor_type &, const target_type &);
    };
    
    template <size_t offset, size_t size, typename... tail, bool dummy> struct iterator <mask <range <offset, size, true>, tail...>, dummy>
    {
      static inline void run(visitor_type &, target_type &);
      static inline void run(visitor_type &, const target_type &);
    };
    
    template <size_t offset, size_t size, typename... tail, bool dummy> struct iterator <mask <range <offset, size, false>, tail...>, dummy>
    {
      static inline void run(visitor_type &, target_type &);
      static inline void run(visitor_type &, const target_type &);
    };
  };
};

#endif

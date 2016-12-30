#ifndef __playground__bytewise__arithmetic_visitor__hpp
#define __playground__bytewise__arithmetic_visitor__hpp

#include "arithmetic_visitor.h"

// Includes

#include "arithmetic_scanner.hpp"
#include "compress.hpp"
#include "arithmetic.hpp"

namespace bytewise
{
  // conditional <true>
  
  template <typename visitor_type, typename target_type> template <bool dummy> template <size_t size> void arithmetic_visitor <visitor_type, target_type> :: conditional <true, dummy> :: swap(const char (&source) [size], char (&destination)[size])
  {
    swab(source, destination, size);
  }
  
  // conditional <false>
  
  template <typename visitor_type, typename target_type> template <bool dummy> template <size_t size> void arithmetic_visitor <visitor_type, target_type> :: conditional <false, dummy> :: swap(const char (&source) [size], char (&destination)[size])
  {
  }
  
  // Empty iterator
  
  template <typename visitor_type, typename target_type> template <bool dummy> inline void arithmetic_visitor <visitor_type, target_type> :: iterator <mask <>, dummy> :: run(visitor_type &, target_type &)
  {
  }
  
  template <typename visitor_type, typename target_type> template <bool dummy> inline void arithmetic_visitor <visitor_type, target_type> :: iterator <mask <>, dummy> :: run(visitor_type &, const target_type &)
  {
  }
  
  // Swapper iterator
  
  template <typename visitor_type, typename target_type> template <size_t offset, size_t size, typename... tail, bool dummy> inline void arithmetic_visitor <visitor_type, target_type> :: iterator <mask <range <offset, size, true>, tail...>, dummy> :: run(visitor_type & visitor, target_type & target)
  {
    static_assert(valid <size, true> :: value, "Visitor does not offer proper arithmetic method.");
    
    char buffer[size];
    
    static constexpr bool read = valid <size, true> :: read;
    static constexpr bool write = valid <size, true> :: write;
    
    conditional <read, false> :: swap(((selector <offset, size> &) target).mask.body, buffer);
    
    visitor.arithmetic(buffer);
    
    conditional <write, false> :: swap(buffer, ((selector <offset, size> &) target).mask.body);
    
    iterator <mask <tail...>, false> :: run(visitor, target);
  }
  
  template <typename visitor_type, typename target_type> template <size_t offset, size_t size, typename... tail, bool dummy> inline void arithmetic_visitor <visitor_type, target_type> :: iterator <mask <range <offset, size, true>, tail...>, dummy> :: run(visitor_type & visitor, const target_type & target)
  {
    static_assert(valid <size, true> :: value, "Visitor does not offer proper arithmetic method.");
    
    char buffer[size];
    
    static constexpr bool read = valid <size, true> :: read;
    static constexpr bool write = valid <size, true> :: write;
    
    static_assert(!write, "Visitor needs to write on const target.");
    
    conditional <read, false> :: swap(((const selector <offset, size> &) target).mask.body, buffer);
    
    visitor.arithmetic(buffer);
    
    iterator <mask <tail...>, false> :: run(visitor, target);
  }
  
  // Direct iterator
  
  template <typename visitor_type, typename target_type> template <size_t offset, size_t size, typename... tail, bool dummy> inline void arithmetic_visitor <visitor_type, target_type> :: iterator <mask <range <offset, size, false>, tail...>, dummy> :: run(visitor_type & visitor, target_type & target)
  {
    static_assert(valid <size, true> :: value, "Visitor does not offer proper arithmetic method.");
    
    visitor.arithmetic(((selector <offset, size> &) target).mask.body);
    iterator <mask <tail...>, false> :: run(visitor, target);
  }
  
  template <typename visitor_type, typename target_type> template <size_t offset, size_t size, typename... tail, bool dummy> inline void arithmetic_visitor <visitor_type, target_type> :: iterator <mask <range <offset, size, false>, tail...>, dummy> :: run(visitor_type & visitor, const target_type & target)
  {
    static_assert(valid <size, true> :: value, "Visitor does not offer proper arithmetic method.");

    static_assert(!(valid <size, true> :: write), "Visitor needs to write on const target.");
    
    visitor.arithmetic(((const selector <offset, size> &) target).mask.body);
    
    iterator <mask <tail...>, false> :: run(visitor, target);
  }
};

#endif

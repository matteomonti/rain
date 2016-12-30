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
    static_assert(valid <size, false> :: value, "Visitor does not offer proper arithmetic method.");
    
    char buffer[size];
    
    conditional <valid <size, false> :: read, false> :: swap(((selector <offset, size> &) target).mask.body, buffer);
    
    visitor.arithmetic((arithmetic <size, valid <size, false> :: read, valid <size, false> :: write> &) buffer);
    
    conditional <valid <size, false> :: write, false> :: swap(buffer, ((selector <offset, size> &) target).mask.body);
    
    iterator <mask <tail...>, false> :: run(visitor, target);
  }
  
  template <typename visitor_type, typename target_type> template <size_t offset, size_t size, typename... tail, bool dummy> inline void arithmetic_visitor <visitor_type, target_type> :: iterator <mask <range <offset, size, true>, tail...>, dummy> :: run(visitor_type & visitor, const target_type & target)
  {
    static_assert(valid <size, true> :: value, "Visitor does not offer proper arithmetic method.");
    
    char buffer[size];
    
    conditional <valid <size, true> :: read, false> :: swap(((const selector <offset, size> &) target).mask.body, buffer);
    
    visitor.arithmetic((const arithmetic <size, valid <size, true> :: read, valid <size, true> :: write> &) buffer);
    
    iterator <mask <tail...>, false> :: run(visitor, target);
  }
  
  // Direct iterator
  
  template <typename visitor_type, typename target_type> template <size_t offset, size_t size, typename... tail, bool dummy> inline void arithmetic_visitor <visitor_type, target_type> :: iterator <mask <range <offset, size, false>, tail...>, dummy> :: run(visitor_type & visitor, target_type & target)
  {
    static_assert(valid <size, false> :: value, "Visitor does not offer proper arithmetic method.");
    
    visitor.arithmetic((arithmetic <size, valid <size, false> :: read, valid <size, false> :: write> &)(((selector <offset, size> &) target).mask.body));
    iterator <mask <tail...>, false> :: run(visitor, target);
  }
  
  template <typename visitor_type, typename target_type> template <size_t offset, size_t size, typename... tail, bool dummy> inline void arithmetic_visitor <visitor_type, target_type> :: iterator <mask <range <offset, size, false>, tail...>, dummy> :: run(visitor_type & visitor, const target_type & target)
  {
    static_assert(valid <size, true> :: value, "Visitor does not offer proper arithmetic method.");

    visitor.arithmetic((const arithmetic <size, valid <size, true> :: read, valid <size, true> :: write> &)(((const selector <offset, size> &) target).mask.body));
    
    iterator <mask <tail...>, false> :: run(visitor, target);
  }
  
  // Static methods
  
  template <typename visitor_type, typename target_type> void arithmetic_visitor <visitor_type, target_type> :: visit(visitor_type & visitor, target_type & target)
  {
    iterator <typename compress <typename arithmetic_scanner <target_type> :: type> :: type, false> :: run(visitor, target);
  }
  
  template <typename visitor_type, typename target_type> void arithmetic_visitor <visitor_type, target_type> :: visit(visitor_type & visitor, const target_type & target)
  {
    iterator <typename compress <typename arithmetic_scanner <target_type> :: type> :: type, false> :: run(visitor, target);
  }
};

#endif

#ifndef __playground__bytewise__arithmetic_visitor__hpp
#define __playground__bytewise__arithmetic_visitor__hpp

#include "arithmetic_visitor.h"

// Includes

#include "arithmetic_scanner.hpp"
#include "compress.hpp"

namespace bytewise
{
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
    
    visitor.arithmetic(((selector <offset, size> &) target).mask.body);
    iterator <mask <tail...>, false> :: run(visitor, target);
  }
};

#endif

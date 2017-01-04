#ifndef __playground__bytewise__buffer_visitor__hpp
#define __playground__bytewise__buffer_visitor__hpp

#include "buffer_visitor.h"

namespace bytewise
{
  // path_iterator <path <>, multiple>
  
  template <typename visitor_type, typename target_type> template <bool multiple> template <typename type> inline void buffer_visitor <visitor_type, target_type> :: path_iterator <path <>, multiple> :: run(visitor_type & visitor, type & target)
  {
    visitor.template buffer <multiple> (target);
  }
  
  template <typename visitor_type, typename target_type> template <bool multiple> template <typename type> inline void buffer_visitor <visitor_type, target_type> :: path_iterator <path <>, multiple> :: run(visitor_type & visitor, const type & target)
  {
    visitor.template buffer <multiple> (target);
  }
  
  // path_iterator <path <index, tail...>, multiple>
  
  template <typename visitor_type, typename target_type> template <size_t index, size_t ... tail, bool multiple> template <typename type> inline void buffer_visitor <visitor_type, target_type> :: path_iterator <path <index, tail...>, multiple> :: run(visitor_type & visitor, type & target)
  {
    path_iterator <path <tail...>, multiple> :: run(visitor, type :: template __bytewise__ <index, false> :: get(target));
  }
  
  template <typename visitor_type, typename target_type> template <size_t index, size_t ... tail, bool multiple> template <typename type> inline void buffer_visitor <visitor_type, target_type> :: path_iterator <path <index, tail...>, multiple> :: run(visitor_type & visitor, const type & target)
  {
    path_iterator <path <tail...>, multiple> :: run(visitor, type :: template __bytewise__ <index, false> :: get(target));
  }
  
  // map_iterator <map <>, multiple>
  
  template <typename visitor_type, typename target_type> template <bool multiple> inline void buffer_visitor <visitor_type, target_type> :: map_iterator <map <>, multiple> :: run(visitor_type & visitor, target_type & target)
  {
  }
  
  template <typename visitor_type, typename target_type> template <bool multiple> inline void buffer_visitor <visitor_type, target_type> :: map_iterator <map <>, multiple> :: run(visitor_type & visitor, const target_type & target)
  {
  }
  
  // map_iterator <map <path, tail...>, multiple>
  
  template <typename visitor_type, typename target_type> template <typename path, typename... tail, bool multiple> inline void buffer_visitor <visitor_type, target_type> :: map_iterator <map <path, tail...>, multiple> :: run(visitor_type & visitor, target_type & target)
  {
    path_iterator <path, multiple> :: run(visitor, target);
    map_iterator <map <tail...>, multiple> :: run(visitor, target);
  }
  
  template <typename visitor_type, typename target_type> template <typename path, typename... tail, bool multiple> inline void buffer_visitor <visitor_type, target_type> :: map_iterator <map <path, tail...>, multiple> :: run(visitor_type & visitor, const target_type & target)
  {
    path_iterator <path, multiple> :: run(visitor, target);
    map_iterator <map <tail...>, multiple> :: run(visitor, target);
  }
  
  // Static methods
  
  template <typename visitor_type, typename target_type> inline void buffer_visitor <visitor_type, target_type> :: visit(visitor_type & visitor, target_type & target)
  {
    typedef typename buffer_scanner <target_type> :: type map;
    
    static_assert(valid <false, (map :: size > 1)> :: value, "Visitor does not offer proper buffer method.");
    
    map_iterator <map, (map :: size > 1)> :: run(visitor, target);
  }
  
  template <typename visitor_type, typename target_type> inline void buffer_visitor <visitor_type, target_type> :: visit(visitor_type & visitor, const target_type & target)
  {
    typedef typename buffer_scanner <target_type> :: type map;
    
    static_assert(valid <true, (map :: size > 1)> :: value, "Visitor does not offer proper buffer method.");
    
    map_iterator <map, (map :: size > 1)> :: run(visitor, target);
  }
};

#endif

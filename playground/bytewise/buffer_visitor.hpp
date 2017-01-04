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
};

#endif

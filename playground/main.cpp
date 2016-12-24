#include <iostream>

#include "data/buffer.hpp"

class myclass
{
  // Self
  
  typedef myclass self;
  
  // Members
  
  int a;
  int b;
  
public:
  
  // Bytewise interface
  
  template <size_t, bool> struct __bytewise__;
  
  template <size_t __bytewise_index__> struct __bytewise__a__member_exists__
  {
    template <bool __bytewise_exists__> class helper {};
    template <typename __bytewise_type__> static uint8_t sfinae(...);
    template <typename __bytewise_type__> static uint32_t sfinae(helper <__bytewise_type__ :: template __bytewise__ <__bytewise_index__, false> :: __exists__> *);
    
    static constexpr bool value = std :: is_same <uint32_t, decltype(sfinae <self> (0))> :: value;
  };
  
  template <size_t index, bool condition> struct __bytewise__a__member_iterator__;
  
  template <size_t index> struct __bytewise__a__member_iterator__ <index, false>
  {
    static constexpr size_t value = 0;
  };
  
  template <size_t index> struct __bytewise__a__member_iterator__ <index, true>
  {
    static constexpr size_t value = __bytewise__a__member_iterator__ <index + 1, __bytewise__a__member_exists__ <index + 1> :: value> :: value + 1;
  };
  
  static constexpr size_t __bytewise__a__member_index__ = __bytewise__a__member_iterator__ <0, __bytewise__a__member_exists__ <0> :: value> :: value;
  
  template <bool __bytewise_dummy__> struct __bytewise__ <__bytewise__a__member_index__, __bytewise_dummy__>
  {
    static constexpr bool __exists__ = true;
    
    static constexpr const size_t offset()
    {
      return offsetof(self, a);
    }
    
    static constexpr const size_t size()
    {
      return sizeof(decltype(((self *) nullptr)->a));
    }
    
    static constexpr const bool arithmetic()
    {
      return std :: is_arithmetic <decltype(((self *) nullptr)->a)> :: value;
    }
    
    static constexpr const bool buffer()
    {
      return std :: is_same <:: buffer, decltype(((self *) nullptr)->a)> :: value;
    }
  };
};

int main()
{
}

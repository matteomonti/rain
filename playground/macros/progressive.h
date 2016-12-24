#if !defined(__forward__) && !defined(__playground__macros__progressive__h)
#define __playground__macros__progressive__h

// Macros

#define progressive_indirect(scope, name)                           \
                                                                    \
template <size_t, bool> struct scope;                               \
                                                                    \
template <size_t __progressive_index__> struct __progressive__      \
    ## scope ## __ ## name ## __exists__                            \
{                                                                   \
  template <bool __progressive_exists__> class helper {};           \
  template <typename __progressive_type__> static uint8_t           \
      sfinae(...);                                                  \
  template <typename __progressive_type__> static uint32_t          \
      sfinae(helper <__progressive_type__ :: template scope         \
      <__progressive_index__, false> :: __exists__> *);             \
                                                                    \
  static constexpr bool value = std :: is_same <uint32_t,           \
      decltype(sfinae <self> (0))> :: value;                        \
};                                                                  \
                                                                    \
template <size_t, bool> struct __progressive__ ## scope ## __ ##    \
    name ## __iterator__;                                           \
                                                                    \
template <size_t __progressive_index__> struct __progressive__ ##   \
    scope ## __ ## name ## __iterator__ <__progressive_index__,     \
    false>                                                          \
{                                                                   \
  static constexpr size_t value = 0;                                \
};                                                                  \
                                                                    \
template <size_t __progressive_index__> struct __progressive__ ##   \
    scope ## __ ## name ## __iterator__ <__progressive_index__,     \
    true>                                                           \
{                                                                   \
  static constexpr size_t value = __progressive__ ## scope ## __    \
      ## name ## __iterator__ <__progressive_index__ + 1,           \
      __progressive__ ## scope ## __ ## name ## __exists__          \
      <__progressive_index__ + 1> :: value> :: value + 1;           \
};                                                                  \
                                                                    \
static constexpr size_t __progressive__ ## scope ## __ ## name      \
    ## __index__ = __progressive__ ## scope ## __ ## name ##        \
    __iterator__ <0, __progressive__ ## scope ## __ ## name ##      \
    __exists__ <0> :: value> :: value;                              \
                                                                    \
template <bool __progressive_dummy__> struct scope <__progressive__ \
    ## scope ## __ ## name ## __index__, __progressive_dummy__> :   \
    :: progressive

#define progressive(scope, name) progressive_indirect(scope, name)

// Classes

struct progressive
{
  static constexpr bool __exists__ = true;
};

#endif

// Forward declaration

class buffer;

#if !defined(__forward__) && !defined(__playground__data__buffer__h)
#define __playground__data__buffer__h

// Libraries

#include <stddef.h>
#include <string.h>

class buffer
{
  // Members
  
  char * _bytes;
  size_t _size;
  size_t _alloc;
  
public:
  
  // Constructors
  
  buffer();
  buffer(const char * const &, const size_t &);
  buffer(const char * const &);
  buffer(const buffer &);
  buffer(buffer &&);
  
  // Destructor
  
  ~buffer();
  
  // Getters
  
  const size_t & size() const;
  
  // Methods
  
  void alloc(const size_t &);
  
  // Operators
  
  char & operator [] (const size_t &);
  const char & operator [] (const size_t &) const;
  
  buffer & operator = (const buffer &);
  buffer & operator = (buffer &&);
  
  // Casting
  
  operator char * ();
  operator char * const () const;
};

#endif

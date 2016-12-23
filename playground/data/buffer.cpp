#include "buffer.hpp"

// Constructors

buffer :: buffer() : _size(0), _alloc(0)
{
}

buffer :: buffer(const char * const & bytes, const size_t & size) : _bytes(new char[size]), _size(size), _alloc(size)
{
  memcpy(this->_bytes, bytes, this->_size);
}

buffer :: buffer(const char * const & bytes) : buffer(bytes, strlen(bytes))
{
}

buffer :: buffer(const buffer & that) : buffer(that._bytes, that._size)
{
}

buffer :: buffer(buffer && that) : _bytes(that._bytes), _size(that._size), _alloc(that._alloc)
{
  that._alloc = 0;
}

// Destructor

buffer :: ~buffer()
{
  if(this->_alloc)
    delete [] this->_bytes;
}

// Methods

void buffer :: alloc(const size_t & size)
{
  if(this->_alloc < size)
  {
    if(this->_alloc)
      delete [] this->_bytes;
    
    this->_alloc = size;
    this->_bytes = new char[this->_alloc];
  }
  
  this->_size = size;
}

// Operators

buffer & buffer :: operator = (const buffer & that)
{
  this->alloc(that._size);
  memcpy(this->_bytes, that._bytes, this->_size);
  
  return *this;
}

buffer & buffer :: operator = (buffer && that)
{
  if(this->_alloc)
    delete [] this->_bytes;
  
  this->_size = that._size;
  this->_alloc = that._alloc;
  this->_bytes = that._bytes;
  
  that._alloc = 0;
  
  return *this;
}

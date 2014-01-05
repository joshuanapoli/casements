#ifndef WINDOWS_VERSION_TYPE_HPP
#define WINDOWS_VERSION_TYPE_HPP

//-----------------------------------------------------------------------------
// Represent an application version number.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/cstdint.hpp>
#include <iosfwd>

namespace casements
{
  // Abstraction of an application version number.
  class version_type
  {
  public:
    typedef boost::uint16_t element_type;

    version_type
      ( element_type major
      , element_type minor
      , element_type patch
      , element_type build
      );

    element_type major() const;
    element_type minor() const;
    element_type patch() const;
    element_type build() const;

  private:
    element_type major_;
    element_type minor_;
    element_type patch_;
    element_type build_;
  };

  // Test whether two versions are equal.
  bool operator==(const version_type& left, const version_type& right);

  // Test whether two versions are unequal.
  bool operator!=(const version_type& left, const version_type& right);

  // Stream inserter for version_type.
  template<typename T, typename Tr>
  std::basic_ostream<T,Tr>& operator<<(std::basic_ostream<T,Tr>& os, const version_type& version)
  {
    return os << version.major() 
       << "." << version.minor() 
       << "." << version.patch()
       << "." << version.build()
       ;
  }
}

#endif

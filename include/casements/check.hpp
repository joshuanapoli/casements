#ifndef CASEMENTS_CHECK_HPP
#define CASEMENTS_CHECK_HPP

//-----------------------------------------------------------------------------
// Check that a Win32 API call has succeeded.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <casements/error.hpp>
#include <casements/last_error.hpp>

namespace casements
{
  // Return the result if it is nonzero, otherwise throw an casements::error.
  template<typename T>
  T check(T result, const std::string& prefix = std::string())
  {
    if(result)
    {
      return result;
    }
    else
    {
      throw last_error(prefix);
    }
  }
}

#endif

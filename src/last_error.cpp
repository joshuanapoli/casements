//-----------------------------------------------------------------------------
// Get the exception class for the latest Win32 API error.
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
#include <Windows.h>

namespace casements
{
  error last_error(const std::string& action)
  {
    return error(GetLastError(), action);
  }
}

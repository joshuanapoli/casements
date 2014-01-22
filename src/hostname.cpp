//-----------------------------------------------------------------------------
// Get the hostname of the computer.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <casements/hostname.hpp>
#include <casements/check.hpp>
#include <Windows.h>

namespace casements
{
  std::string hostname()
  {
    DWORD size(0);
    (void)GetComputerNameEx
        ( ComputerNamePhysicalDnsHostname
        , 0
        , &size
        );
    std::string result(size, '\0');
    check
      ( GetComputerNameEx
        ( ComputerNamePhysicalDnsHostname
        , &*result.begin()
        , &size
        )
      , "get the computer name"
      );
    // drop a trailing NUL character
    if(!result.empty())
    {
      result.erase(result.size() - 1);
    }
    return result;
  }
}

#ifndef CASEMENTS_FORMAT_MESSAGE_FROM_SYSTEM_HPP
#define CASEMENTS_FORMAT_MESSAGE_FROM_SYSTEM_HPP

//-----------------------------------------------------------------------------
// Get a human-readable message corresponding to an HRESULT error code.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <Windows.h>

namespace casements
{
  std::string format_message_from_system(DWORD hresult);
}

#endif

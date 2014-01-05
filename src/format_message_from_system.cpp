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

#include <boost/algorithm/string/trim.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/scope_exit.hpp>
#include <casements/check.hpp>
#include <casements/format_message_from_system.hpp>
#include <cassert>
#include <Windows.h>

namespace casements
{
  namespace
  {
    std::string generic_message(boost::uint32_t result)
    {
      return "Win32 error " + boost::lexical_cast<std::string>(result);
    }
  }

  std::string format_message_from_system(boost::uint32_t result)
  {
    LPTSTR buffer = NULL;
    BOOST_SCOPE_EXIT(&buffer)
    {
      buffer = reinterpret_cast<LPTSTR>(LocalFree(buffer));
      assert(NULL == buffer);
    } BOOST_SCOPE_EXIT_END

    try
    {
      (void)check
        ( FormatMessage
          ( FORMAT_MESSAGE_FROM_SYSTEM     // use system message tables to retrieve error text
          | FORMAT_MESSAGE_ALLOCATE_BUFFER // allocate buffer on local heap for error text
          | FORMAT_MESSAGE_IGNORE_INSERTS  // We cannot know what insertion parameters system strings expect, so we send none.
          , NULL                           // unused with FORMAT_MESSAGE_FROM_SYSTEM
          , result
          , MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
          , (LPTSTR)&buffer                // output 
          , 0                              // minimum size for output buffer
          , NULL                           // No insertion parameters, as previously mentioned.
          )
        );
      if(buffer)
      {
        std::stringstream stream;
        return
          boost::algorithm::trim_right_copy(std::string(buffer))
          + " ("
          + generic_message(result)
          + ")";
      }
    }
    catch(...)
    {
    }
    return generic_message(result);
  }
}

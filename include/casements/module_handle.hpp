#ifndef CASEMENTS_MODULE_HANDLE_HPP
#define CASEMENTS_MODULE_HANDLE_HPP

//-----------------------------------------------------------------------------
// Container for a Win32 module handle.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/noncopyable.hpp>
#include <Windows.h>

namespace casements
{
  class module_handle : boost::noncopyable
  {
  public:
    // Retrieve the handle to the file used to create the calling process (.exe
    // file).
    module_handle();

    // Retrieve the handle for the module with the given name.
    explicit module_handle(const char* module_name);

    // Release the module handle.
    ~module_handle();

    // Automatically convert to the Win32 handle type.
    operator HMODULE() const;

  private:
    HMODULE hmodule_;
  };
}

#endif

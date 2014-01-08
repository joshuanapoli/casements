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

#include <cassert>
#include <casements/check.hpp>
#include <casements/module_handle.hpp>

namespace casements
{
  module_handle::module_handle()
    : hmodule_(0)
  {
    check
      ( GetModuleHandleEx(0, 0, &hmodule_)
      , std::string("get the module handle for the current process")
      );
  }

  module_handle::module_handle(const char* module_name)
    : hmodule_(0)
  {
    check
      ( GetModuleHandleEx(0, module_name, &hmodule_)
      , std::string("get the module handle for '") + module_name + "'"
      );
  }

  module_handle::~module_handle()
  {
    if(hmodule_)
    {
      BOOL free_library_succeeded(FreeLibrary(hmodule_));
      assert(free_library_succeeded);
    }
    hmodule_ = 0;
  }

  module_handle::operator HMODULE() const
  {
    return hmodule_;
  }
}

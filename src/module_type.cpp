//-----------------------------------------------------------------------------
// Retrieve properties of a Windows Module (generally, a DLL or EXE).
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/numeric/conversion/cast.hpp>
#include <cassert>
#include <casements/check.hpp>
#include <casements/file_version_info.hpp>
#include <casements/module_handle.hpp>
#include <casements/module_type.hpp>
#include <casements/version_type.hpp>

namespace casements
{
  const module_type::code_page_type module_type::english_us_code_page = "040904b0";

  module_type::module_type()
    : handle_(new module_handle())
  {
  }

  module_type::module_type(const char* module_name)
    : handle_(new module_handle(module_name))
  {
  }

  const module_handle& module_type::handle() const
  {
    return *handle_;
  }

  module_type::path_type module_type::filename() const
  {
    std::string name(MAX_PATH, '\0');
    DWORD size
      ( GetModuleFileName
        ( handle()
        , const_cast<LPCH>(name.c_str())
        , boost::numeric_cast<DWORD>(name.size())
        )
      );
    while(size == name.size())
    {
      name.resize(name.size() * 2);
      size = check
        ( GetModuleFileName
          ( handle()
          , const_cast<LPCH>(name.c_str())
          , boost::numeric_cast<DWORD>(name.size())
          )
        , "get the module file name"
       );
    }
    return module_type::path_type(name.begin(), name.begin() + static_cast<int>(size));
  }


  module_type::version_type module_type::version() const
  {
    return file_version_info(filename()).version();
  }

  module_type::string module_type::company_name(code_page_type code_page) const
  {
    return file_version_info(filename()).company_name(code_page);
  }

  module_type::string module_type::product_name(code_page_type code_page) const
  {
    return file_version_info(filename()).product_name(code_page);
  }
}

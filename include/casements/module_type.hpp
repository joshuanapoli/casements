#ifndef CASEMENTS_MODULE_TYPE_HPP
#define CASEMENTS_MODULE_TYPE_HPP

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

#include <boost/filesystem/path.hpp>
#include <string>

namespace casements
{
  class version_type;
  class module_handle;

  class module_type
  {
  public:
    typedef boost::filesystem::path path_type;
    typedef std::string string;
    typedef string code_page_type;
    typedef casements::version_type version_type;

    static const code_page_type english_us_code_page;

    // Return the the current process module.
    module_type();

    // Return the module with the given name.
    explicit module_type(const char* module_name);

    // Get the handle to this module.
    const module_handle& handle() const;

    // Retrieves the fully qualified path_type for the module. If the path_type cannot
    // be retrieved, a casements::error exception is thrown.
    path_type filename() const;

    // Get the version number from the version resource information.
    version_type version() const;

    // Get the company name.
    string company_name(code_page_type code_page = english_us_code_page) const;

    // Get the product name.
    string product_name(code_page_type code_page = english_us_code_page) const;

  private:
    boost::shared_ptr<module_handle> handle_;
  };
}

#endif

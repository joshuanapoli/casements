//-----------------------------------------------------------------------------
// Implement getting the application documents path.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <casements/documents_path.hpp>
#include <casements/module_type.hpp>

namespace casements
{
  boost::filesystem::path application_documents_path()
  {
    return casements::documents_path() / casements::module_type().product_name();
  }
}

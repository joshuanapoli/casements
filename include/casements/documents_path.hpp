#ifndef CASEMENTS_DOCUMENTS_PATH_HPP
#define CASEMENTS_DOCUMENTS_PATH_HPP

//-----------------------------------------------------------------------------
// Get the documents path.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/filesystem/path.hpp>

namespace casements
{
  boost::filesystem::path documents_path();
}

#endif

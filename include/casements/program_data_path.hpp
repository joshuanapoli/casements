#ifndef CASEMENTS_PROGRAM_DATA_PATH_HPP
#define CASEMENTS_PROGRAM_DATA_PATH_HPP

//-----------------------------------------------------------------------------
// Get the system program data path.
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
  boost::filesystem::path program_data_path();
}

#endif

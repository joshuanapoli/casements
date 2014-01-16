#ifndef CASEMENTS_GET_KNOWN_FOLDER_PATH_HPP
#define CASEMENTS_GET_KNOWN_FOLDER_PATH_HPP

//-----------------------------------------------------------------------------
// Get a known folder path.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/filesystem/path.hpp>
#include <ShTypes.h>

namespace casements
{
  boost::filesystem::path get_known_folder_path(REFKNOWNFOLDERID rfid);
}

#endif

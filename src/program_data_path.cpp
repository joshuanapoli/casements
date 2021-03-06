//-----------------------------------------------------------------------------
// Implement getting the system program data path.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <Windows.h>
#include <KnownFolders.h>

#include <casements/get_known_folder_path.hpp>
#include <casements/program_data_path.hpp>

namespace casements
{
  boost::filesystem::path program_data_path()
  {
    return get_known_folder_path(FOLDERID_ProgramData);
  }
}

// Implement getting the system program data data path.
// Copyright 2013 Joshua Napoli

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

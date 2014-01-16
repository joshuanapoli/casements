// Implement getting a known folder path.
// Copyright 2013 Joshua Napoli

#include <Windows.h>
#include <Shlobj.h>

#include <boost/lexical_cast.hpp>
#include <boost/scope_exit.hpp>
#include <casements/check.hpp>
#include <casements/get_known_folder_path.hpp>

namespace casements
{
  boost::filesystem::path get_known_folder_path(REFKNOWNFOLDERID rfid)
  {
    PWSTR path = 0;
    BOOST_SCOPE_EXIT(&path)
    {
      CoTaskMemFree(path);
      path = 0;
    } BOOST_SCOPE_EXIT_END

    if(SUCCEEDED(SHGetKnownFolderPath(rfid, 0, NULL, &path)))
    {
      if(path)
      {
        return boost::filesystem::path(path);
      }
      else
      {
        return boost::filesystem::path();
      }
    }
    else
    {
      throw last_error("get a known folder path");
    }
  }
}

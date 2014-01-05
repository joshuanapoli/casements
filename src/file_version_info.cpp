//-----------------------------------------------------------------------------
// Access file version info resource.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <casements/check.hpp>
#include <casements/file_version_info.hpp>
#include <casements/version_type.hpp>
#include <Windows.h>

namespace casements
{
  const file_version_info::code_page_type file_version_info::english_us_code_page = "040904b0";

  file_version_info::file_version_info(const boost::filesystem::path& path)
    : data(file_version_info_size(path))
  {
    std::string file_name_string(path.string());
    (void)casements::check
      ( GetFileVersionInfo
        ( file_name_string.c_str()
        , NULL
        , data.size()
        , &data[0]
        )
      , "get the file version information"
      );
  }

  casements::version_type file_version_info::version() const
  {
    UINT size = 0;
    VS_FIXEDFILEINFO* fixed_file_info = 0;
    (void)casements::check
      ( VerQueryValue
        ( &data[0]
        , TEXT("\\")
        , (LPVOID*)&fixed_file_info
        , (PUINT)&size
        )
      , "query the version value"
      );
    return casements::version_type
      ( HIWORD(fixed_file_info->dwProductVersionMS)
      , LOWORD(fixed_file_info->dwProductVersionMS)
      , HIWORD(fixed_file_info->dwProductVersionLS)
      , LOWORD(fixed_file_info->dwProductVersionLS)
      );
  }

  file_version_info::string file_version_info::company_name(code_page_type code_page) const
  {
    char* product_name(0);
    unsigned int product_name_size(0);
    string sub_block("\\StringFileInfo\\"+code_page+"\\CompanyName");
    (void)casements::check
      ( VerQueryValue
        ( &data[0]
        , sub_block.c_str()
        , reinterpret_cast<LPVOID*>(&product_name)
        , &product_name_size
        )
      , "read product name for code page " + code_page
      );
    return std::string(product_name);
  }

  file_version_info::string file_version_info::product_name(code_page_type code_page) const
  {
    char* product_name(0);
    unsigned int product_name_size(0);
    string sub_block("\\StringFileInfo\\"+code_page+"\\ProductName");
    (void)casements::check
      ( VerQueryValue
        ( &data[0]
        , sub_block.c_str()
        , reinterpret_cast<LPVOID*>(&product_name)
        , &product_name_size
        )
      , "read product name for code page " + code_page
      );
    return std::string(product_name);
  }

  file_version_info::size_t file_version_info::file_version_info_size(const boost::filesystem::path& path)
  {
    DWORD dummy=0;
    std::string file_name_string(path.string());
    return casements::check
      ( GetFileVersionInfoSize(file_name_string.c_str(), &dummy)
      , "get the file version information data size"
      );
  }
}

#ifndef WINDOWS_FILE_VERSION_INFO_HPP
#define WINDOWS_FILE_VERSION_INFO_HPP

// Access file version info resource.
// Copyright 2014 Joshua Napoli

#include <boost/filesystem/path.hpp>
#include <string>
#include <vector>

namespace casements
{
  class version_type;

  // Abstraction of version resource data embedded in a module.
  // See http://msdn.microsoft.com/en-us/library/windows/desktop/ms646981(v=vs.85).aspx
  class file_version_info
  {
  public:
    typedef std::size_t size_t;
    typedef std::string string;
    typedef string code_page_type;

    static const code_page_type english_us_code_page;

    // Read the version information from the module at the given path.
    explicit file_version_info(const boost::filesystem::path& path);

    // Retrieve the version information.
    version_type version() const;

    // Get the company name from the version information.
    string company_name(code_page_type code_page = english_us_code_page) const;

    // Get the product name from the version information.
    string product_name(code_page_type code_page = english_us_code_page) const;

  private:

    // Get the size (in bytes) of the version data contained in the module at 
    // the given path.
    static size_t file_version_info_size(const boost::filesystem::path& path);

    std::vector<unsigned char> data;
  };
}

#endif

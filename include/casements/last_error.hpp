#ifndef CASEMENTS_LAST_ERROR_HPP
#define CASEMENTS_LAST_ERROR_HPP

// Get the exception class for the latest Win32 API error.
// Copyright 2014 Joshua Napoli

#include <string>

namespace casements
{
  class error;

  // Return the exception class for the latest Win32 API error, if an error has occurred.
  error last_error(const std::string& action = std::string());
}

#endif

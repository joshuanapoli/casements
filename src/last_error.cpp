// Get the exception class for the latest Win32 API error.
// Copyright 2014 Joshua Napoli

#include <casements/error.hpp>
#include <casements/last_error.hpp>
#include <Windows.h>

namespace casements
{
  error last_error(const std::string& action)
  {
    return error(GetLastError(), action);
  }
}

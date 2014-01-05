#ifndef CASEMENTS_ERROR_HPP
#define CASEMENTS_ERROR_HPP

//-----------------------------------------------------------------------------
// Exception class to represent a Win32 API error code.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#include <iostream>
#include <string>
#include <Windows.h>

namespace casements
{
  // Exception class to represent a Win32 API error code.
  class error : public std::runtime_error
  {
  public:
    typedef DWORD error_code_type;

    // Construct an error exception with the given error_code.
    explicit error(error_code_type error_code);

    // Construct an error exception with the given error_code, explaining the failing action.
    error(error_code_type error_code, const std::string& action);

    // Get the error_code.
    error_code_type get_error_code() const noexcept;

    // Get the action.
    const std::string& get_action() const noexcept;

  private:
    const error_code_type error_code_;
    const std::string action_;
  };

  // Test whether two error objects have the same error code and action.
  bool operator==(const error& left, const error& right);

  // Test whether two error objects are not equal.
  bool operator!=(const error& left, const error& right);

  template<typename T, typename Tr>
  std::basic_ostream<T,Tr>& operator<<(std::basic_ostream<T,Tr>& os, const error& e)
  {
    return os << e.what();
  }
}

#endif

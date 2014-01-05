// Exception class to represent a Win32 API error code.
// Copyright 2014 Joshua Napoli

#include <casements/error.hpp>
#include <casements/format_message_from_system.hpp>

namespace casements
{
  error::error(error_code_type error_code)
    : std::runtime_error(format_message_from_system(error_code))
    , error_code_(error_code)
  {
  }

  error::error(error_code_type error_code, const std::string& action) noexcept
    : std::runtime_error("Failed to " + action + ". " + format_message_from_system(error_code))
    , error_code_(error_code)
    , action_(action)
  {
  }

  error::error_code_type error::get_error_code() const noexcept
  {
    return error_code_;
  }

  const std::string& error::get_action() const noexcept
  {
    return action_;
  }

  bool operator==(const error& left, const error& right)
  {
    return left.get_error_code() == right.get_error_code()
        && left.get_action() == right.get_action();
  }

  bool operator!=(const error& left, const error& right)
  {
    return !(left == right);
  }
}

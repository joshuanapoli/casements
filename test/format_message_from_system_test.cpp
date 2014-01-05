// Test getting a human-readable message corresponding to an HRESULT error code.
// Copyright 2014 Joshua Napoli

#include <boost/test/unit_test.hpp>
#include <casements/format_message_from_system.hpp>

BOOST_AUTO_TEST_CASE(should_get_system_message_for_known_error_code)
{
  BOOST_CHECK_EQUAL
    ( casements::format_message_from_system(ERROR_INVALID_FUNCTION)
    , "Incorrect function. (Win32 error 1)"
    );
}

BOOST_AUTO_TEST_CASE(should_get_generic_message_for_unknown_error_code)
{
  BOOST_CHECK_EQUAL
    ( casements::format_message_from_system(20000)
    , "Win32 error 20000"
    );
}

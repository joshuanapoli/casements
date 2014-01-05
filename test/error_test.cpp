// Test the error exception class.
// Copyright 2014 Joshua Napoli

#include <boost/lexical_cast.hpp>
#include <boost/test/unit_test.hpp>
#include <casements/error.hpp>

BOOST_AUTO_TEST_CASE(error_class_has_system_message_for_known_error_code)
{
  BOOST_CHECK_EQUAL
    ( std::string(casements::error(ERROR_PATH_NOT_FOUND).what())
    , "The system cannot find the path specified. (Win32 error 3)"
    );
}

BOOST_AUTO_TEST_CASE(error_class_has_generic_message_for_unknown_error_code)
{
  BOOST_CHECK_EQUAL
    ( std::string(casements::error(20001).what())
    , "Win32 error 20001"
    );
}

BOOST_AUTO_TEST_CASE(error_has_action)
{
  BOOST_CHECK_EQUAL
    ( casements::error(ERROR_FILE_NOT_FOUND, "open a file").what()
    , "Failed to open a file. The system cannot find the file specified. (Win32 error 2)"
    );
}

BOOST_AUTO_TEST_CASE(error_has_error_code)
{
  BOOST_CHECK_EQUAL
    ( casements::error(ERROR_BAD_ENVIRONMENT).get_error_code()
    , ERROR_BAD_ENVIRONMENT
    );
}

BOOST_AUTO_TEST_CASE(errors_with_same_code_are_equal)
{
  const casements::error error_1(ERROR_INVALID_HANDLE);
  const casements::error error_2(ERROR_INVALID_HANDLE);
  BOOST_CHECK_EQUAL(error_1, error_2);
}

BOOST_AUTO_TEST_CASE(errors_with_different_codes_are_not_equal)
{
  const casements::error error_1(ERROR_ARENA_TRASHED);
  const casements::error error_2(ERROR_NOT_ENOUGH_MEMORY);
  BOOST_CHECK(error_1 != error_2);
}

BOOST_AUTO_TEST_CASE(error_stream_inserter)
{
  BOOST_CHECK_EQUAL
    ( boost::lexical_cast<std::string>
      ( casements::error(ERROR_INVALID_BLOCK)
      )
    , "The storage control block address is invalid. (Win32 error 9)"
    );
}

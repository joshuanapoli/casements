//-----------------------------------------------------------------------------
// Test the error exception class.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/lexical_cast.hpp>
#include <boost/test/unit_test.hpp>
#include <casements/error.hpp>

BOOST_AUTO_TEST_CASE(error_class_has_system_message_for_known_error_code)
{
  BOOST_CHECK_EQUAL
    ( std::string(casements::error(3).what())
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
    ( casements::error(2, "open a file").what()
    , "Failed to open a file. The system cannot find the file specified. (Win32 error 2)"
    );
}

BOOST_AUTO_TEST_CASE(error_has_error_code)
{
  BOOST_CHECK_EQUAL
    ( casements::error(10).get_error_code()
    , 10
    );
}

BOOST_AUTO_TEST_CASE(errors_with_same_code_are_equal)
{
  const casements::error error_1(6);
  const casements::error error_2(6);
  BOOST_CHECK_EQUAL(error_1, error_2);
}

BOOST_AUTO_TEST_CASE(errors_with_different_codes_are_not_equal)
{
  const casements::error error_1(7);
  const casements::error error_2(8);
  BOOST_CHECK(error_1 != error_2);
}

BOOST_AUTO_TEST_CASE(error_stream_inserter)
{
  BOOST_CHECK_EQUAL
    ( boost::lexical_cast<std::string>
      ( casements::error(9)
      )
    , "The storage control block address is invalid. (Win32 error 9)"
    );
}

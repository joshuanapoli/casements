//-----------------------------------------------------------------------------
// Test getting the exception class for the latest error.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <casements/error.hpp>
#include <casements/last_error.hpp>
#include <Windows.h>

BOOST_AUTO_TEST_CASE(last_error_returns_error_class_even_when_successful)
{
  SetLastError(ERROR_SUCCESS);
  BOOST_CHECK_EQUAL
    ( casements::last_error()
    , casements::error(ERROR_SUCCESS)
    );
}

BOOST_AUTO_TEST_CASE(last_error_returns_error_class_with_current_code)
{
  SetLastError(ERROR_TOO_MANY_OPEN_FILES);
  BOOST_CHECK_EQUAL
    ( casements::last_error()
    , casements::error(ERROR_TOO_MANY_OPEN_FILES)
    );
}

BOOST_AUTO_TEST_CASE(last_error_action)
{
  const std::string action("delete a file");
  BOOST_CHECK_EQUAL
    ( casements::last_error(action).get_action()
    , action
    );
}

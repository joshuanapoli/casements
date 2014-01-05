//-----------------------------------------------------------------------------
// Test checking that a Win32 API call has succeeded.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <casements/check.hpp>

BOOST_AUTO_TEST_CASE(successful_values_are_nonzero)
{
  BOOST_CHECK_EQUAL
    ( casements::check(1234)
    , 1234
    );
}

BOOST_AUTO_TEST_CASE(error_thrown_for_unsuccessful_result)
{
  BOOST_CHECK_THROW
    ( casements::check(0)
    , casements::error
    );
}

BOOST_AUTO_TEST_CASE(thrown_error_has_action)
{
  const std::string action("read an environment variable");
  try
  {
    casements::check(0, action);
    BOOST_FAIL("expected a casements::error to be thrown.");
  }
  catch(const casements::error& error)
  {
    BOOST_CHECK_EQUAL
      ( error.get_action()
      , action
      );
  }
}

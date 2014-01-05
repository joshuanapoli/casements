//-----------------------------------------------------------------------------
// Test human-readable messages corresponding to an Win32 error code.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <casements/format_message_from_system.hpp>

BOOST_AUTO_TEST_CASE(should_get_system_message_for_known_error_code)
{
  BOOST_CHECK_EQUAL
    ( casements::format_message_from_system(1)
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

//-----------------------------------------------------------------------------
// Unit test casements::module_handle.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <casements/module_handle.hpp>

BOOST_AUTO_TEST_CASE(should_get_handle_of_current_process)
{
  casements::module_handle current_process;
  BOOST_CHECK(current_process);
}

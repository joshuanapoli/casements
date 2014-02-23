//-----------------------------------------------------------------------------
// Test getting the hostname of the computer.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <casements/hostname.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(hostname_is_not_empty)
{
  std::string hostname(casements::hostname());
  std::cout << "hostname: " << hostname << std::endl;
  BOOST_CHECK(!hostname.empty());
}

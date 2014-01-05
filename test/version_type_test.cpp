//-----------------------------------------------------------------------------
// Unit test for the windows::version_type class.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <sstream>
#include <casements/version_type.hpp>

BOOST_AUTO_TEST_CASE(should_get_major_version)
{
  BOOST_CHECK_EQUAL
    ( casements::version_type(1,2,3,4).major()
    , 1
    );
}

BOOST_AUTO_TEST_CASE(should_get_minor_version)
{
  BOOST_CHECK_EQUAL
    ( casements::version_type(1,2,3,4).minor()
    , 2
    );
}

BOOST_AUTO_TEST_CASE(should_get_patch_version)
{
  BOOST_CHECK_EQUAL
    ( casements::version_type(1,2,3,4).patch()
    , 3
    );
}

BOOST_AUTO_TEST_CASE(should_get_build_version)
{
  BOOST_CHECK_EQUAL
    ( casements::version_type(1,2,3,4).build()
    , 4
    );
}

BOOST_AUTO_TEST_CASE(should_compare_versions_for_equality)
{
  BOOST_CHECK_EQUAL
    ( casements::version_type(1,2,3,4)
    , casements::version_type(1,2,3,4)
    );
  BOOST_CHECK_NE
    ( casements::version_type(1,1,1,1)
    , casements::version_type(9,1,1,1)
    );
  BOOST_CHECK_NE
    ( casements::version_type(1,1,1,1)
    , casements::version_type(1,9,1,1)
    );
  BOOST_CHECK_NE
    ( casements::version_type(1,1,1,1)
    , casements::version_type(1,1,9,1)
    );
  BOOST_CHECK_NE
    ( casements::version_type(1,1,1,1)
    , casements::version_type(1,1,1,9)
    );
}

BOOST_AUTO_TEST_CASE(should_print_version)
{
  std::stringstream ss;
  ss << casements::version_type(1,2,3,4);
  BOOST_CHECK_EQUAL
    ( ss.str()
    , "1.2.3.4"
    );
}

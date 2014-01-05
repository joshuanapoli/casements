//-----------------------------------------------------------------------------
// Unit test for accessing file version info resource.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <casements/file_version_info.hpp>
#include <casements/version_type.hpp>
#include <windows/module_type.hpp>

BOOST_AUTO_TEST_CASE(should_read_file_version_info)
{
  windows::module_type current_process;
  BOOST_CHECK_NO_THROW(casements::file_version_info(current_process.filename()))
}

BOOST_AUTO_TEST_CASE(should_get_version)
{
  windows::module_type current_process;
  casements::file_version_info file_version_info(current_process.filename());
  casements::version_type version(file_version_info.version());
  BOOST_CHECK_EQUAL(version, casements::version_type(1,2,3,4));
}

BOOST_AUTO_TEST_CASE(should_get_company_name)
{
  windows::module_type current_process;
  casements::file_version_info file_version_info(current_process.filename());
  BOOST_CHECK_EQUAL(file_version_info.company_name(), "Napoli Visual Software");
}

BOOST_AUTO_TEST_CASE(should_get_product_name)
{
  windows::module_type current_process;
  casements::file_version_info file_version_info(current_process.filename());
  BOOST_CHECK_EQUAL(file_version_info.product_name(), "casement_test");
}

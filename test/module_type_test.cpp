//-----------------------------------------------------------------------------
// Unit test for the casements::module_type.
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
#include <casements/module_type.hpp>
#include <casements/version_type.hpp>

BOOST_AUTO_TEST_CASE(should_get_current_module)
{
  casements::module_type current_process;
  BOOST_CHECK(current_process.handle());
}

BOOST_AUTO_TEST_CASE(should_get_filename_of_current_process)
{
  casements::module_type current_process;
  BOOST_CHECK_EQUAL
    ( boost::filesystem::path("casements_test.exe")
    , current_process.filename().filename()
    );
}

BOOST_AUTO_TEST_CASE(should_get_version_of_current_process)
{
  casements::module_type current_process;
  BOOST_CHECK_EQUAL
    ( casements::version_type(1,2,3,4)
    , current_process.version()
    );
}

BOOST_AUTO_TEST_CASE(should_get_company_name_of_current_process)
{
  casements::module_type current_process;
  BOOST_CHECK_EQUAL
    ( "Napoli Visual Software"
    , current_process.company_name()
    );
}

BOOST_AUTO_TEST_CASE(should_get_product_name_of_current_process)
{
  casements::module_type current_process;
  BOOST_CHECK_EQUAL
    ( "casement_test"
    , current_process.product_name()
    );
}

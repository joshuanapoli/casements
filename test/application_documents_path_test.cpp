//-----------------------------------------------------------------------------
// Test getting the application documents data path.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <casements/application_documents_path.hpp>

BOOST_AUTO_TEST_CASE(should_get_application_documents_path)
{
  BOOST_CHECK_EQUAL
    ( casements::application_documents_path()
    , boost::filesystem::path(std::getenv("USERPROFILE")) / "Documents" / "casement_test"
    );
}

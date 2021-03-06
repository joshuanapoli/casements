//-----------------------------------------------------------------------------
// Unit test for getting a known folder path.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014
// Joshua Napoli <jnapoli@alum.mit.edu>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <boost/cstdlib.hpp>
#include <Guiddef.h>
#include <Knownfolders.h>
#include <casements/get_known_folder_path.hpp>

BOOST_AUTO_TEST_CASE(should_get_program_data_folder)
{
  BOOST_CHECK_EQUAL
    ( casements::get_known_folder_path(FOLDERID_ProgramData)
    , boost::filesystem::path(std::getenv("ALLUSERSPROFILE"))
    );
}

// Unit test for getting a known folder path.
// Copyright 2013 Joshua Napoli

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

// Implement version_type.
// Copyright 2014 Joshua Napoli

#include <casements/version_type.hpp>

namespace casements
{
  version_type::version_type
    ( element_type major_element
    , element_type minor_element
    , element_type patch_element
    , element_type build_element
    )
    : major_(major_element)
    , minor_(minor_element)
    , patch_(patch_element)
    , build_(build_element)
  {
  }

  version_type::element_type version_type::major() const
  {
    return major_;
  }

  version_type::element_type version_type::minor() const
  {
    return minor_;
  }

  version_type::element_type version_type::patch() const
  {
    return patch_;
  }

  version_type::element_type version_type::build() const
  {
    return build_;
  }

  bool operator==(const version_type& left, const version_type& right)
  {
    return left.major() == right.major()
      && left.minor() == right.minor()
      && left.patch() == right.patch()
      && left.build() == right.build()
      ;
  }

  bool operator!=(const version_type& left, const version_type& right)
  {
    return !(left == right);
  }
}

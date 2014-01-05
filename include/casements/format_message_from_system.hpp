#ifndef CASEMENTS_FORMAT_MESSAGE_FROM_SYSTEM_HPP
#define CASEMENTS_FORMAT_MESSAGE_FROM_SYSTEM_HPP

// Get a human-readable message corresponding to an HRESULT error code.
// Copyright 2014 Joshua Napoli

#include <string>
#include <Windows.h>

namespace casements
{
  std::string format_message_from_system(DWORD hresult);
}

#endif

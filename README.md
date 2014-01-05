Casements
=========

The casements library provides adapts a few bits of the Win32 API for C++. The
Casements interface avoids the need to include the troublesome Windows.h header
in application code. The application should add [casements/include](include) to
its list of include paths. Source files are under the [casements/src](src)
directory and are built using the [casements_lib](casements_lib.vcproj) Visual
Studio project file. Unit tests are under [casements/test](test) and are built
using the [casements_test](casements_test.vcproj) project file. The casements
library depends on the [Boost C++ libraries](http://www.boost.org).


API Errors
----------

Most Win32 API calls return zero if they fail. The `casements::check` template
function can be used to test for failure. If the call was successful, the
result is returned to the application. On error, a `casements::error` is
thrown. The application can provide an "action" description that can serve as
code documentation and improve the error message. For example:

```c++
HICON hicon = casements::check
  ( ::ExtractIcon(hinst, "myfile.dll", IDI_ICON1)
  , "get a handle to the main application icon"
  );
```

If the `ExtractIcon` call fails, then the `casements::error` will have a
helpful message, such as "Failed to get a handle to the main application icon.
The system cannot find the file specified. (Win32 error2)".

Some API functions have a different return value convention. When using a
custom error test, the `casements::last_error` gives a convienent way to
construct the exception object for the latest error. For example:

```c++
BOOL get_message_result = GetMessage(&message, 0, 0, 0);
if(-1 == get_message_result)
{
  throw casements::last_error("get the next message");
}
```


Reading Version Resource Information
------------------------------------

The `casements::file_version_info` class provides easy access to version
resource information. This is useful to avoid repeating version strings within
the application source code. The application should read its own version
resource to format the text of the "about" box.


License
=======

This library is available under the Boost Software License.

� 2014 Joshua Napoli

Distributed under the Boost Software License, Version 1.0. 
(See Accompanying File LICENSE_1_0.Txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
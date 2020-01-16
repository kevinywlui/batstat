# batstat

Battery statistics tool supporting multiple batteries

This tool was created to help me display battery information on my Thinkpad
T480 which has 2 batteries. It was only been tested on a Thinkpad T480.

## Usage

* Call `batstat` with no arguments to get information similar to calling `acpi`.
* Call `batstat --i3blocks` to get some color as well.

## Third-party

The following third-party libraries were used:

* [cxxopts](https://github.com/jarro2783/cxxopts)
* [fmtlib](https://github.com/fmtlib/fmt)

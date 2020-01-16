# batstat

Battery statistics tool supporting multiple batteries

This tool was created to help me display battery information on my Thinkpad
T480 which has 2 batteries. It has only been tested on my Thinkpad T480.

## Build

I use `cmake` and `ninja` to build `batstat`. The output binary will be in the
`build` directory.
```
mkdir build
cd build
cmake -GNinja ..
ninja
```

## Usage

* Call `batstat` with no arguments to get information similar to calling `acpi`.
* Call `batstat --i3blocks` to get some color as well.

## Third-party

The following third-party libraries were used:

* [cxxopts](https://github.com/jarro2783/cxxopts)
* [fmtlib](https://github.com/fmtlib/fmt)

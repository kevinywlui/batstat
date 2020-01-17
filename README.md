# batteries_stats

`batteries_stats` is a tool for aggregating statistics about multiple
batteries. This tool provides information similar to running `acpi -b`. But
unlike `acpi -b` this tool will combine the individual battery information so
that you know the total battery percentage, time until depletion of both
batteries, and more. This is done by reading files found in
`/sys/class/power_supply/BAT*/`.

## Shortcomings/Todos

This tool has only been tested on my Thinkpad T480. There isn't much error
handling and testing.

## Build

This tool is built with the help of `cmake` and `ninja`. The `cmake` command
has been wrapped into the `Makefile` so simply run
```
make
```
and the resulting binary will appear in the `build` directory.

## Usage

* Call `batstat` with no arguments to get information similar to calling `acpi`.
* Call `batstat --i3blocks` to get some color as well.

## Third-party

The following third-party libraries were used:

* [cxxopts](https://github.com/jarro2783/cxxopts)
* [fmtlib](https://github.com/fmtlib/fmt)

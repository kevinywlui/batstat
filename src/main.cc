#include <totalinfo.h>
#include <iostream>
#include <cxxopts.hpp>
#include <fmt/format.h>

int main() {
  Totalinfo totalinfo;

  float percentage = totalinfo.energy_frac*100;
  std::string status_abbr = totalinfo.status_abbr;


  fmt::print("{:.0f}% {} {}\n", percentage, status_abbr, totalinfo.time_string);
  fmt::print("{:.0f}% {} {}\n", percentage, status_abbr, totalinfo.time_string);
  
  std::string color_code;
  if (percentage < 20)
    color_code = "#A93226";
  else if (percentage < 40)
    color_code = "#BA4A00";
  else if (percentage < 80)
    color_code = "#F1C40F";
  else
    color_code = "#239B56";
  fmt::print("{}\n", color_code);
}

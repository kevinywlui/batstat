#include <totalinfo.h>
#include <fmt/format.h>
#include <cmath>
#include <iostream>

int main() {

  Totalinfo totalinfo;

  float percentage = totalinfo.energy_frac*100;
  std::string status_abbr = totalinfo.status_abbr;

  std::string time_string;
  if (totalinfo.hours_until_comp < 0) {
    time_string = "";
  }
  else {
    uint32_t hours = std::floor(totalinfo.hours_until_comp);
    if (hours > 99) {
      time_string = "Inf";
    }
    else {
      uint32_t minutes = std::floor((totalinfo.hours_until_comp-hours)*60);
      time_string = fmt::format("({:0>2}:{:0>2})", hours, minutes);
    }
  }

  fmt::print("{:.0f}% {} {}\n", percentage, status_abbr, time_string);
  fmt::print("{:.0f}% {} {}\n", percentage, status_abbr, time_string);
  
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

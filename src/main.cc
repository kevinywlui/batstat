#include <totalinfo.h>
#include <iostream>
#include <cxxopts.hpp>
#include <fmt/format.h>

int main(int argc, char* argv[]) {
  // Form strings to be printed
  Totalinfo totalinfo;

  float percentage = totalinfo.energy_frac*100;
  std::string status_abbr = totalinfo.status_abbr;

  std::string batstat = fmt::format("{:.0f}% {} {}", percentage, status_abbr, totalinfo.time_string);

  std::string color_code;
  if (percentage < 20)
    color_code = "#A93226";
  else if (percentage < 40)
    color_code = "#BA4A00";
  else if (percentage < 80)
    color_code = "#F1C40F";
  else
    color_code = "#239B56";

  try {
    cxxopts::Options options("batstat", "Battery statistics tool supporting multiple batteries");
    options.add_options()
      ("h,help", "Display help")
      ("p,percentage", "Return only percentage")
      ("i3blocks", "Enable i3blocks colors")
      ;
    auto result = options.parse(argc, argv);

    if (result.count("help")) {
      std::cout << options.help() << std::endl;
      return 0;
    }


    // percentage print mode
    if (result.count("percentage")) {
      std::cout << percentage << std::endl;
      return 0;
    }

    // i3block print mode
    if (result.count("i3blocks")) {
      fmt::print("{0}\n{0}\n{1}\n", batstat, color_code);
      return 0;
    }
    
    std::cout << batstat << std::endl;
    return 0;
  }  
  catch (const cxxopts::OptionException& e)
  {
    std::cout << "error parsing options: " << e.what() << std::endl;
    return 1;
  }
}

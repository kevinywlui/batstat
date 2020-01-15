#include <totalinfo.h>
#include <cxxopts.hpp>

#include <iostream>
#include <iomanip>

#include <sstream>

int main() {

  Totalinfo totalinfo;
  std::cout << totalinfo.energy_frac;

  

/*   // abbreviate the status */ 
/*   std::string status_abbrev; */
/*   if (is_charging) { */
/*     status_abbrev = "CHR"; */
/*   } */
/*   else if (is_discharging) { */
/*     status_abbrev = "DIS"; */
/*   } */
/*   else { */
/*     status_abbrev = "FULL"; */
/*   } */

/*   // determine hours until completing either the charge or discharge */
/*   // format the time string */
/*   std::ostringstream time_string; */
/*   float hours_until_comp; */
/*   if (total_power_now == 0) { */
/*     time_string << "NaN"; */
/*   } */
/*   else { */
/*     if (is_charging) { */
/*       hours_until_comp = (total_energy_full - total_energy_now) / float(total_power_now); */
/*     } */
/*     else { */
/*       hours_until_comp = total_energy_now / float(total_power_now); */
/*     } */

/*     if (hours_until_comp > 100) { */
/*       time_string << "Inf"; */
/*     } */
/*     else { */
/*       uint16_t hours = std::floor(hours_until_comp); */
/*       uint16_t minutes = std::round((hours_until_comp - hours) * 60); */
/*       time_string << std::setw(2) << std::setfill('0') << hours; */
/*       time_string << ":"; */
/*       time_string << std::setw(2) << std::setfill('0') << minutes; */
/*     } */
/*   } */



/*   // print the current total percentage */
/*   std::cout << std::fixed << std::setprecision(0) << total_frac*100 << "%" << " "; */
/*   // print the status */
/*   std::cout << status_abbrev << " "; */
/*   // print time string */
/*   std::cout << "(" << time_string.str() << ")"; */
/*   // print a newline */
/*   std::cout << std::endl; */

}

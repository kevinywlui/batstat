#include <batinfo.h>

#include <iostream>
#include <iomanip>

#include <sstream>
#include <vector>
#include <cmath>

#include <filesystem>
namespace fs = std::filesystem;

int main() {

  // determine number of batteries
  uint16_t num_batteries = 1;
  fs::path power_supply_path = "/sys/class/power_supply";
  auto bat_path = power_supply_path / ("BAT" + std::to_string(num_batteries));
  while (fs::exists(bat_path)) {
    num_batteries++;
    bat_path = power_supply_path / ("BAT" + std::to_string(num_batteries));
  }

  // store all bat info in a vector
  std::vector<Batinfo> bat_vec;
  for (uint16_t i=0; i < num_batteries; i++) {
    bat_vec.push_back(Batinfo(i));
  }

  // sum up the totals
  uint32_t total_energy_now = 0;
  uint32_t total_energy_full = 0;
  uint32_t total_power_now = 0;
  for (auto bat: bat_vec) {
    total_energy_now += bat.energy_now;
    total_energy_full += bat.energy_full;
    total_power_now += bat.power_now;
  }
  float total_frac = total_energy_now / float(total_energy_full);

  // determine total status
  bool is_charging = false;
  bool is_discharging = false;
  for (auto bat: bat_vec) {
    if (bat.status == "Charging") {
      is_charging = true;
      break;
    }
    else if (bat.status == "Discharging") {
      is_discharging = true;
      break;
    }
  }

  // abbreviate the status 
  std::string status_abbrev;
  if (is_charging) {
    status_abbrev = "CHR";
  }
  else if (is_discharging) {
    status_abbrev = "DIS";
  }
  else {
    status_abbrev = "FULL";
  }

  // determine hours until completing either the charge or discharge
  // format the time string
  std::ostringstream time_string;
  float hours_until_comp;
  if (total_power_now == 0) {
    time_string << "NaN";
  }
  else {
    if (is_charging) {
      hours_until_comp = (total_energy_full - total_energy_now) / float(total_power_now);
    }
    else {
      hours_until_comp = total_energy_now / float(total_power_now);
    }

    if (hours_until_comp > 100) {
      time_string << "Inf";
    }
    else {
      uint16_t hours = std::floor(hours_until_comp);
      uint16_t minutes = std::round((hours_until_comp - hours) * 60);
      time_string << std::setw(2) << std::setfill('0') << hours;
      time_string << ":";
      time_string << std::setw(2) << std::setfill('0') << minutes;
    }
  }



  // print the current total percentage
  std::cout << std::fixed << std::setprecision(0) << total_frac*100 << "%" << " ";
  // print the status
  std::cout << status_abbrev << " ";
  // print time string
  std::cout << "(" << time_string.str() << ")";
  // print a newline
  std::cout << std::endl;

}

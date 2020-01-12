#include "batinfo.h"
#include <iostream>
#include <iomanip>

#include <vector>
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
  uint32_t total_now = 0;
  uint32_t total_full = 0;
  for (auto bat: bat_vec) {
    total_now += bat.energy_now;
    total_full += bat.energy_full;
  }
  float total_frac = total_now / float(total_full);

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

  // print the current total percentage
  std::cout << std::fixed << std::setprecision(0) << total_frac*100 << "%" << " ";
  // print the status
  std::cout << status_abbrev << " ";


}

#include "batinfo.h"
#include "totalinfo.h"

#include <vector>

#include <filesystem>
namespace fs = std::filesystem;

Totalinfo::Totalinfo() {
  
  // Get number of batteries
  num_batteries = 1;
  fs::path power_supply_path = "/sys/class/power_supply";
  auto bat_path = power_supply_path / ("BAT" + std::to_string(num_batteries));
  while (fs::exists(bat_path)) {
    num_batteries++;
    bat_path = power_supply_path / ("BAT" + std::to_string(num_batteries));
  }

  std::vector<Batinfo> bat_vec;
  for (uint32_t i=0; i < num_batteries; i++) {
    bat_vec.push_back(Batinfo(i));
  }

  // sum up the totals
  energy_now = 0;
  energy_full = 0;
  power_now = 0;
  for (auto bat: bat_vec) {
    energy_now += bat.energy_now;
    energy_full += bat.energy_full;
    power_now += bat.power_now;
  }
  float energy_frac = energy_now / float(energy_full);

  // determine total status
  bool is_charging = false;
  bool is_discharging = false;
  for (auto bat: bat_vec) {
    if (bat.is_charging) {
      is_charging = true;
      break;
    }
    else if (bat.is_discharging) {
      is_discharging = true;
      break;
    }
  }
}

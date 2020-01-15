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
  energy_frac = energy_now / float(energy_full);

  // determine total status
  is_charging = false;
  is_discharging = false;
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
  is_full = !(is_charging || is_discharging);

  // determine the status strings
  if (is_charging) {
    status = "Charging";
    status_abbr = "CHR";
  }
  else if (is_discharging) {
    status = "Discharging";
    status_abbr = "DIS";
  }
  else {
    status = "Full";
    status_abbr = "FULL";
  }

  // determine number of hours until finish charging or discharging
  if (is_full) {
    hours_until_comp = -1;
  }
  else if (power_now == 0) {
    hours_until_comp = -1;
  }
  else if (is_charging) {
    hours_until_comp = (energy_full - energy_now) / float(power_now);
  }
  else {
    hours_until_comp = energy_now / float(power_now);
  }
}

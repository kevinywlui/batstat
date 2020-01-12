#include "batinfo.h"
#include <iostream>

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

  // store all batinfo in a vector
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

  std::cout << total_now / float(total_full) << std::endl;
}

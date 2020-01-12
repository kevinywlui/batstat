#include "batinfo.h"

#include <iostream>
#include <fstream>

#include <string>

#include <filesystem>
namespace fs = std::filesystem;

Batinfo::Batinfo(uint16_t bat_num) {

  this->bat_num = bat_num;

  // form path to BAT folder
  fs::path power_supply_path = "/sys/class/power_supply";
  auto bat_path = power_supply_path / ("BAT" + std::to_string(bat_num));

  // retrieve energy_full data
  auto energy_full_file = bat_path / "energy_full";

  std::ifstream energy_full_stream (energy_full_file);
  std::string energy_full_string;
  if (energy_full_stream.is_open()) {
    std::getline(energy_full_stream, energy_full_string);
  }
  energy_full_stream.close();

  energy_full = std::stoi(energy_full_string);

  // retrieve energy_full data
  auto energy_now_file = bat_path / "energy_now";

  std::ifstream energy_now_stream (energy_now_file);
  std::string energy_now_string;
  if (energy_now_stream.is_open()) {
    std::getline(energy_now_stream, energy_now_string);
  }
  energy_now_stream.close();

  energy_now = std::stoi(energy_now_string);
}

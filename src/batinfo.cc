#include "batinfo.h"

#include <iostream>
#include <fstream>

#include <filesystem>
namespace fs = std::filesystem;

Batinfo::Batinfo(uint16_t bat_num) {

  this->bat_num = bat_num;

  energy_full = std::stoi(get_data("energy_full"));
  energy_now = std::stoi(get_data("energy_now"));
  power_now = std::stoi(get_data("power_now"));

  status = get_data("status");
  is_charging = (status == "Charging");
  is_discharging = (status == "Discharging");
  is_full = (status == "Full");
}

std::string Batinfo::get_data(std::string data_name) {
  // store the retrieved data in a string
  std::string data;

  // form path to BAT folder
  fs::path power_supply_path = "/sys/class/power_supply";
  auto bat_path = power_supply_path / ("BAT" + std::to_string(bat_num));

  // retrieve data
  auto data_file = bat_path / data_name;

  std::ifstream data_stream (data_file);
  std::string data_string;
  std::getline(data_stream, data);
  data_stream.close();
  return data;
}

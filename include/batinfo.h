// class for accessing information found in
// `/sys/class/power_supply/BAT*

#include <cstdint>
#include <string>

class Batinfo {
  public:
    Batinfo(uint16_t);

    uint32_t energy_full;
    uint32_t energy_now;
    uint32_t power_now;

    std::string status;

  private:
    // Read information from `/sys/class/power_supply/BAT{bat_num}`
    uint16_t bat_num;

    // Return the string obtained by reading `/../../BAT{bat_num}/{data_name}`
    std::string get_data(std::string);
};

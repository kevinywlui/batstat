// class for accessing information found in
// `/sys/class/power_supply/BAT*

#include <cstdint>
#include <string>

class Batinfo {
  public:
    Batinfo(uint16_t);

    uint32_t energy_full;
    uint32_t energy_now;

    std::string status;

  private:
    int bat_num;
};

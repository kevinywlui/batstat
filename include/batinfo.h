// class for accessing information found in
// `/sys/class/power_supply/BAT*

#include <cstdint>

class Batinfo {
  public:
    Batinfo(uint16_t);

    uint32_t energy_full;
    uint32_t energy_now;

  private:
    int bat_num;
};

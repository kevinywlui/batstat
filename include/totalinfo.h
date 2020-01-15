// class for accessing information found in
// `/sys/class/power_supply/BAT*

#include <cstdint>
#include <string>

class Totalinfo {
  public:
    Totalinfo();

    uint32_t num_batteries;

    uint32_t energy_full;
    uint32_t energy_now;
    uint32_t power_now;

    float energy_frac;

    bool is_charging;
    bool is_discharging;
    bool is_full;

    std::string status;
    std::string status_abbr;

    float hours_until_comp;
};

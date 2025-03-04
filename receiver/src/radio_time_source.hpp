#pragma once

#include <RH_ASK.h>

class RadioTimeSource {

  public:

    struct Config {
        int rx_pin;
        int speed;
        float tx_rate;
        int rx_status_led_pin;
    };

    static RadioTimeSource* Create(const Config &config);
    void Sync();
    unsigned long GetReferenceMillis() const { return reference_millis_; }
    
    void RadioTimeMock(unsigned long micros);

  private:
    RadioTimeSource() = default;
    
    Config config_ = {};
    unsigned long reference_millis_ = 0;
    RH_ASK* receiver = nullptr;

    bool rx_status_led;
};
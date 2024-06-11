#include "DebounceIntrptLib.h"

DebounceIntrptLib::DebounceIntrptLib(PinName pin, uint32_t debounce_time_ms, Callback<void()> cb, bool momentary) 
    : _pin(pin), _debounce_time_ms(debounce_time_ms), _last_read(1), _last_stable_state(1), _callback(cb), _momentary(momentary) {
    _pin.rise(callback(this, &DebounceIntrptLib::on_rise));
    _pin.fall(callback(this, &DebounceIntrptLib::on_fall));
}

int DebounceIntrptLib::read() {
    core_util_critical_section_enter();
    int stable_state = _last_stable_state;
    core_util_critical_section_exit();
    return stable_state;
}

void DebounceIntrptLib::on_rise() {
    _last_read = 1;
    _timeout.attach(callback(this, &DebounceIntrptLib::check_state), std::chrono::milliseconds(_debounce_time_ms));
}

void DebounceIntrptLib::on_fall() {
    _last_read = 0;
    _timeout.attach(callback(this, &DebounceIntrptLib::check_state), std::chrono::milliseconds(_debounce_time_ms));
}

void DebounceIntrptLib::check_state() {
    if (_last_read == _pin.read()) {
        core_util_critical_section_enter();
        _last_stable_state = _last_read;
        core_util_critical_section_exit();
        if (_momentary) {
            if (_last_stable_state == 0) {
                _callback();  // Call the callback function on button press for momentary switch
            }
        } else {
            _callback();  // Call the callback function when the state is stable for bi-stable switch
        }
    }
}

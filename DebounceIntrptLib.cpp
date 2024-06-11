#include "DebounceIntrptLib.h"

DebounceLib::DebounceLib(PinName pin, uint32_t debounce_time_ms, Callback<void()> cb) 
    : _pin(pin), _debounce_time_ms(debounce_time_ms), _last_read(1), _last_stable_state(1), _callback(cb) {
    _pin.rise(callback(this, &DebounceLib::on_rise));
    _pin.fall(callback(this, &DebounceLib::on_fall));
}

int DebounceLib::read() {
    core_util_critical_section_enter();
    int stable_state = _last_stable_state;
    core_util_critical_section_exit();
    return stable_state;
}

void DebounceLib::on_rise() {
    _last_read = 1;
    _timeout.attach(callback(this, &DebounceLib::check_state), std::chrono::milliseconds(_debounce_time_ms));
}

void DebounceLib::on_fall() {
    _last_read = 0;
    _timeout.attach(callback(this, &DebounceLib::check_state), std::chrono::milliseconds(_debounce_time_ms));
}

void DebounceLib::check_state() {
    if (_last_read == _pin.read()) {
        core_util_critical_section_enter();
        _last_stable_state = _last_read;
        core_util_critical_section_exit();
        _callback();  // Call the callback function when the state is stable
    }
}

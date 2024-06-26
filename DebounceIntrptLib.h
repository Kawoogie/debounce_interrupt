#ifndef DEBOUNCE_INTRPT_LIB_H
#define DEBOUNCE_INTRPT_LIB_H

#include "mbed.h"

/**
 * @class DebounceIntrptLib
 * @brief A library for debouncing switches.
 * 
 * This library debounces a switch connected to a specified pin and triggers a callback
 * function when the switch state changes and remains stable for a specified debounce time.
 */
class DebounceIntrptLib {
public:
    /**
     * @brief Constructor for DebounceIntrptLib.
     * 
     * @param pin The pin to which the switch is connected.
     * @param debounce_time_ms The debounce time in milliseconds.
     * @param cb The callback function to be called when the switch state is stable.
     * @param momentary Set to true if the switch is momentary, false if bi-stable.
     * 
     * @note The accepted values for debounce_time_ms are in the range of 1 to 1000 milliseconds.
     */
    DebounceIntrptLib(PinName pin, uint32_t debounce_time_ms, Callback<void()> cb, bool momentary = false);

    /**
     * @brief Reads the last stable state of the switch.
     * 
     * @return The last stable state of the switch (0 or 1).
     */
    int read();

private:
    InterruptIn _pin;              /**< The pin to which the switch is connected. */
    Timeout _timeout;              /**< Timeout object for debouncing. */
    uint32_t _debounce_time_ms;    /**< Debounce time in milliseconds. */
    volatile int _last_read;       /**< Last read state of the switch (0 or 1). */
    volatile int _last_stable_state; /**< Last stable state of the switch (0 or 1). */
    Callback<void()> _callback;    /**< Callback function to be called when the switch state is stable. */
    bool _momentary;               /**< True if the switch is momentary, false if bi-stable. */

    /**
     * @brief Interrupt handler for rising edge.
     */
    void on_rise();

    /**
     * @brief Interrupt handler for falling edge.
     */
    void on_fall();

    /**
     * @brief Checks if the state is stable.
     */
    void check_state();
};

#endif // DEBOUNCE_INTRPT_LIB_H

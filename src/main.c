#include "main.h"

timer_t match_timer;

void initialize() {

    vision_signature_s_t yellow = vision_signature_from_utility(1, 1025, 1703, 1364, -3093, -2777, -2935, 6.100, 0);
    lcd_initialize();

    vision_set_signature(VISION_PORT, 1, &yellow);
    vision_set_zero_point(VISION_PORT, E_VISION_ZERO_CENTER);
    vision_clear_led(VISION_PORT);
    vision_set_exposure(VISION_PORT, 50);

    for(int i = 0; i < NUM_MOTORS; ++i) {
        motor_set_gearing(motors[i], E_MOTOR_GEARSET_18);
        motor_set_encoder_units(motors[i], E_MOTOR_ENCODER_DEGREES);
    }
    motor_set_reversed(LEFT_MOTOR_A, true);
    motor_set_reversed(LEFT_MOTOR_B, true);
    motor_set_reversed(RIGHT_MOTOR_C, true);

}

void disabled() {
}

void competition_initialize() {

}


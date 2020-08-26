#ifndef F28069_AUTO_H
#define F28069_AUTO_H

#include "pid.h"
#include "pwm.h"

typedef struct _AUTO_Obj_
{
    int32 command_motor_speed;              // Motor speed command: [0,1000]
    int32 command_servo_position;           // Servo angle command: [12000,22500]
    int32 command_gimbal_position;          // Gimbal angle command: [3480,1820]
    int32 shadow_motor_speed;               // Motor speed command: [0,1000]
    int32 shadow_servo_position;            // Servo angle command: [12000,22500]
    int32 shadow_gimbal_position;           // Gimbal angle command: [3480,1820]
    int32 battery_voltage_uint;             // Battery voltage ADC result
    float  battery_voltage_f;               // Battery voltage float
    float  motor_position;                  // Motor position
    float  motor_position_pre;              // Motor previous position
    float  motor_speed;                     // Measured motor speed
    float  motor_speed_pre;                 // Measured motor speed previous
    float  motor_pwm;                       // PWM
    float  motor_pwm_pre;                   // PWM previous

    float  gimbal_position;                 // Gimbal position
    float  gimbal_position_pre;             // Gimbal previous position
    float  gimbal_speed;                    // Gimbal speed
    float  gimbal_speed_pre;                // Gimbal previous speed
    float  gimbal_current;                  // Gimbal current
    float  gimbal_current_pre;              // Gimbal previous current
    float  gimbal_current_phase;            // Gimbal current phase
    Uint32 gimbal_phase_order;              // Gimbal phase order
    float  gimbal_position_difference;      // Gimbal position difference
    Uint32 gimbal_direction;                // Gimbal direction
    Uint32 gimbal_direction_pre;            // Gimbal previous direction
    Uint32 gimbal_current_sample_num;       // Gimbal current sampling number

    Uint32 count_10khz;

    PID_Obj PID_Motor;
    PID_Obj PID_Gimbal_Position;
    PID_Obj PID_Gimbal_Current;

} AUTO_Obj;

//! \brief Defines the AUTO handle
//!
typedef struct _AUTO_Obj_ *AUTO_Handle;

void Init_Auto(AUTO_Handle auto_handle);


#endif /* F28069_AUTO_H */
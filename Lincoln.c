//###########################################################################
//
// FILE:   Lincoln.c
//
// TITLE:  Lincoln Racing
//
//!  This project is for the control part of an autonomous driving vehicle.
//!  the PID controller output for the gimbal.
//
//###########################################################################

#include "include/main.h"

int16 command_motor_speed = 0;
int16 command_servo_angle = 0;
int16 command_gimbal_angle = 0;

int  PWM_CNT = 150;
int  GIMBAL_CNT_4A = 300;
int  GIMBAL_CNT_4B = 300;
int  GIMBAL_CNT_5A = 0;
int  GIMBAL_CNT_5B = 0;
int  GIMBAL_CNT_6A = 0;
int  GIMBAL_CNT_6B = 3000;
int  SERVO_CNT = 17250;  //when pulse width = 1.5ms, servo at neutral(16875 + 375offset)  left 11250 right 22500

int32 ecap1_t1 = 0;
int32 ecap1_t2 = 0;
float encoder_motor_position = 0;

int32 ecap2_t1 = 0;
int32 ecap2_t2 = 0;

int32 ecap3_t1 = 0;
int32 ecap3_t2 = 0;
float encoder_gimbal_position = 0;

// system state machine
// 0: Initial
// 1: online
// 2: fault
int state_machine = 0; 


void main(void)
{
    // Initialize the system
    Init_system();

    // Forever loop
    for(;;){
    }
}


// cpu_timer0_isr
// The main ISR for control loop
__interrupt void cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;
    
    EPwm1Regs.CMPA.half.CMPA = PWM_CNT;
    EPwm2Regs.CMPA.half.CMPA = SERVO_CNT;
    EPwm4Regs.CMPA.half.CMPA = GIMBAL_CNT_4A;
    EPwm4Regs.CMPB = GIMBAL_CNT_4B;
    EPwm5Regs.CMPA.half.CMPA = GIMBAL_CNT_5A;
    EPwm5Regs.CMPB = GIMBAL_CNT_5B;
    EPwm6Regs.CMPA.half.CMPA = GIMBAL_CNT_6A;
    EPwm6Regs.CMPB = GIMBAL_CNT_6B;

    ecap1_t1 = ECap1Regs.CAP1;
    ecap1_t2 = ECap1Regs.CAP2;
    ecap2_t1 = ECap2Regs.CAP1;
    ecap2_t2 = ECap2Regs.CAP2;
    ecap3_t1 = ECap3Regs.CAP1;
    ecap3_t2 = ECap3Regs.CAP2;
    encoder_motor_position = ((float)ecap1_t1 / (float)ecap1_t2)*4119 - 24;
    encoder_gimbal_position = ((float)ecap3_t1 / (float)ecap3_t2)*4119 - 24;

    // Acknowledge this interrupt to receive more interrupts from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}



//
// End of File
//


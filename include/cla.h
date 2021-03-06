#ifndef F28069_CLA_H
#define F28069_CLA_H

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"
#include "pwm.h"
#include "adc.h"
#include "bldc.h"
#include "auto.h"

#define CLA_PROG_ENABLE      0x0001
#define CLARAM0_ENABLE       0x0010
#define CLARAM1_ENABLE       0x0020
#define CLARAM2_ENABLE       0x0040
#define CLA_RAM0CPUE         0x0100
#define CLA_RAM1CPUE         0x0200
#define CLA_RAM2CPUE         0x0400

//
// These are defined by the linker file and used to copy
// the CLA code from its load address to its run address
// in CLA program memory
//
extern Uint16 Cla1funcsLoadStart;
extern Uint16 Cla1funcsLoadEnd;
extern Uint16 Cla1funcsLoadSize;
extern Uint16 Cla1funcsRunStart;
extern Uint16 Cla1Prog_Start;

//
// These are defined by the linker file and used to copy
// the CLA math tables from its load address to its run address
// into one of the CLA data RAMs
//
extern Uint16 Cla1mathTablesLoadStart;
extern Uint16 Cla1mathTablesLoadEnd;
extern Uint16 Cla1mathTablesLoadSize;
extern Uint16 Cla1mathTablesRunStart;

//
// CLA Variables
//

extern Uint16 ADC_Results[16];
extern AUTO_Obj Lincoln_Auto;
extern AUTO_Handle Lincoln_Auto_Handle;

void Init_CLA(void);

//
// CLA C Tasks
//
__interrupt void Cla1Task1();

#endif // end of F28069_CLA_H definition



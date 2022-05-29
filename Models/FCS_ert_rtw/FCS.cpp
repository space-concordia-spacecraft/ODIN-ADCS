//
// File: FCS.cpp
//
// Code generated for Simulink model 'FCS'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Sat May 28 23:44:17 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR (32-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FCS.h"
#include "FCS_private.h"

// Model step function
void FCSModelClass::step()
{
  // (no output/update code required)
}

// Model initialize function
void FCSModelClass::initialize()
{
  // ConstCode for Outport: '<Root>/Cmd'
  FCS_Y.Cmd[0] = FCS_ConstB.radstorpm1[0];
  FCS_Y.Cmd[1] = FCS_ConstB.radstorpm1[1];
  FCS_Y.Cmd[2] = FCS_ConstB.radstorpm1[2];
}

// Model terminate function
void FCSModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
FCSModelClass::FCSModelClass():
  FCS_U()
  ,FCS_Y()
  ,FCS_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
FCSModelClass::~FCSModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
FCSModelClass::RT_MODEL_FCS_T * FCSModelClass::getRTM()
{
  return (&FCS_M);
}

//
// File trailer for generated code.
//
// [EOF]
//

//
// File: FCS.h
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
#ifndef RTW_HEADER_FCS_h_
#define RTW_HEADER_FCS_h_
#include "rtwtypes.h"
#include "FCS_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Class declaration for model FCS
class FCSModelClass {
  // public data and function members
 public:
  // Invariant block signals (default storage)
  typedef const struct tag_ConstB_FCS_T {
    real_T TmpSignalConversionAtGainIn[4];
    real_T Gain[4];                    // '<S5>/Gain'
    real_T Gain1[4];                   // '<S5>/Gain1'
    real_T Gain4[4];                   // '<S5>/Gain4'
    real_T Gain2[4];                   // '<S5>/Gain2'
    real_T MatrixConcatenate[16];      // '<S5>/Matrix Concatenate'
    real_T Gain_d[4];                  // '<S1>/Gain'
    real_T MatrixMultiply[4];          // '<S1>/Matrix Multiply'
    real_T Product[3];                 // '<S8>/Product'
    real_T Gain_dc[3];                 // '<S8>/Gain'
    real_T Kd;                         // '<S8>/Kd'
    real_T cmd_torque[3];              // '<S8>/Sum'
    real_T radstorpm1[3];              // '<S8>/rad//s to rpm1'
  } ConstB_FCS_T;

  // External inputs (root inport signals with default storage)
  typedef struct {
    real_T Measurements;               // '<Root>/Measurements'
    real_T w_wheels;                   // '<Root>/w_wheels'
  } ExtU_FCS_T;

  // External outputs (root outports fed by signals with default storage)
  typedef struct {
    real_T Position;                   // '<Root>/Position'
    real_T Velocity;                   // '<Root>/Velocity'
    real_T Cmd[3];                     // '<Root>/Cmd'
  } ExtY_FCS_T;

  // Real-time Model Data Structure
  struct RT_MODEL_FCS_T {
    const char_T * volatile errorStatus;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  FCSModelClass();

  // Destructor
  ~FCSModelClass();

  // Root-level structure-based inputs set method

  // Root inports set method
  void setExternalInputs(const ExtU_FCS_T* pExtU_FCS_T)
  {
    FCS_U = *pExtU_FCS_T;
  }

  // Root-level structure-based outputs get method

  // Root outports get method
  const FCSModelClass::ExtY_FCS_T & getExternalOutputs() const
  {
    return FCS_Y;
  }

  // Real-Time Model get method
  FCSModelClass::RT_MODEL_FCS_T * getRTM();

  // private data and function members
 private:
  // External inputs
  ExtU_FCS_T FCS_U;

  // External outputs
  ExtY_FCS_T FCS_Y;

  // Real-Time Model
  RT_MODEL_FCS_T FCS_M;
};

extern const FCSModelClass::ConstB_FCS_T FCS_ConstB;// constant block i/o

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S4>/Product' : Unused code path elimination
//  Block '<S8>/Kp' : Eliminated nontunable gain of 1


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'FCS'
//  '<S1>'   : 'FCS/Attitude error'
//  '<S2>'   : 'FCS/Controller'
//  '<S3>'   : 'FCS/Guidance'
//  '<S4>'   : 'FCS/State Estimator'
//  '<S5>'   : 'FCS/Attitude error/Q'
//  '<S6>'   : 'FCS/Controller/Detumbling'
//  '<S7>'   : 'FCS/Controller/Momemtum unloading'
//  '<S8>'   : 'FCS/Controller/Three axis attitude controller'
//  '<S9>'   : 'FCS/Guidance/SGP4 propagator'

#endif                                 // RTW_HEADER_FCS_h_

//
// File trailer for generated code.
//
// [EOF]
//

/*
 * Controller.h
 *
 * Code generation for model "Controller".
 *
 * Model version              : 1.18
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Sun Feb 20 15:56:59 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Controller_COMMON_INCLUDES_
# define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

#include "Controller_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S2>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S2>/Scope1' */
} DW_Controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T q0;                           /* '<Root>/q0' */
  real_T q1;                           /* '<Root>/q1' */
  real_T q2;                           /* '<Root>/q2' */
  real_T q3;                           /* '<Root>/q3' */
  real_T omega_b[3];                   /* '<Root>/w_body' */
  real_T BT[3];                        /* '<Root>/B [T]' */
} ExtU_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T cmd_rpm[3];                   /* '<Root>/cmd_rpm ' */
  real_T cmd_M[3];                     /* '<Root>/cmd_M' */
} ExtY_Controller_T;

/* Parameters (default storage) */
struct P_Controller_T_ {
  real_T Jw;                           /* Variable: Jw
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T m_max;                        /* Variable: m_max
                                        * Referenced by:
                                        *   '<S5>/Gain'
                                        *   '<S5>/Gain1'
                                        *   '<S5>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Kp_Gain;                      /* Expression: 1
                                        * Referenced by: '<S4>/Kp'
                                        */
  real_T Kd_Gain;                      /* Expression: 0.2
                                        * Referenced by: '<S4>/Kd'
                                        */
  real_T radstorpm1_Gain;              /* Expression: 1/0.104719755
                                        * Referenced by: '<S4>/rad//s to rpm1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Constant_Value[3];            /* Expression: [1;0;0]
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value[3];           /* Expression: [0;1;0]
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant2_Value[3];           /* Expression: [0;0;1]
                                        * Referenced by: '<S5>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Controller_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Controller_T Controller_P;

/* Block states (default storage) */
extern DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Controller_T Controller_Y;

/* Model entry point functions */
extern void Controller_initialize(void);
extern void Controller_step(void);
extern void Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller_T *const Controller_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('TEST/Controller')    - opens subsystem TEST/Controller
 * hilite_system('TEST/Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TEST'
 * '<S1>'   : 'TEST/Controller'
 * '<S2>'   : 'TEST/Controller/Detumbling'
 * '<S3>'   : 'TEST/Controller/Momemtum management'
 * '<S4>'   : 'TEST/Controller/Three axis controller'
 * '<S5>'   : 'TEST/Controller/Detumbling/Bang-Bang'
 * '<S6>'   : 'TEST/Controller/Detumbling/Cross Product'
 * '<S7>'   : 'TEST/Controller/Detumbling/norm'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

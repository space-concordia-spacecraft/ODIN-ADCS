/*
 * Controller.c
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

#include "Controller.h"
#include "Controller_private.h"

/* Block states (default storage) */
DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controller_T Controller_Y;

/* Real-time model */
RT_MODEL_Controller_T Controller_M_;
RT_MODEL_Controller_T *const Controller_M = &Controller_M_;

/* Model step function */
void Controller_step(void)
{
  /* local block i/o variables */
  real_T rtb_Gain_p[3];
  real_T rtb_Gain2;
  real_T rtb_Gain1_o;
  real_T rtb_Gain_a;
  real_T rtb_Add;

  /* Product: '<S4>/Product' incorporates:
   *  Inport: '<Root>/q0'
   *  Inport: '<Root>/q1'
   *  Inport: '<Root>/q2'
   *  Inport: '<Root>/q3'
   */
  rtb_Gain_p[0] = Controller_U.q1 * Controller_U.q0;
  rtb_Gain_p[1] = Controller_U.q2 * Controller_U.q0;
  rtb_Gain_p[2] = Controller_U.q3 * Controller_U.q0;

  /* Gain: '<S4>/Gain1' */
  rtb_Add = 1.0 / Controller_P.Jw;

  /* Outport: '<Root>/cmd_rpm ' incorporates:
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Kd'
   *  Gain: '<S4>/Kp'
   *  Gain: '<S4>/rad//s to rpm1'
   *  Inport: '<Root>/w_body'
   *  Sum: '<S4>/Sum'
   */
  Controller_Y.cmd_rpm[0] = (Controller_P.Gain_Gain * rtb_Gain_p[0] *
    Controller_P.Kp_Gain + Controller_P.Kd_Gain * Controller_U.omega_b[0]) *
    rtb_Add * Controller_P.radstorpm1_Gain;

  /* Sum: '<S6>/Add3' incorporates:
   *  Inport: '<Root>/B [T]'
   *  Inport: '<Root>/w_body'
   *  Product: '<S6>/Element product'
   */
  rtb_Gain_p[0] = Controller_U.omega_b[1] * Controller_U.BT[2] -
    Controller_U.omega_b[2] * Controller_U.BT[1];

  /* Outport: '<Root>/cmd_rpm ' incorporates:
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Kd'
   *  Gain: '<S4>/Kp'
   *  Gain: '<S4>/rad//s to rpm1'
   *  Inport: '<Root>/w_body'
   *  Sum: '<S4>/Sum'
   */
  Controller_Y.cmd_rpm[1] = (Controller_P.Gain_Gain * rtb_Gain_p[1] *
    Controller_P.Kp_Gain + Controller_P.Kd_Gain * Controller_U.omega_b[1]) *
    rtb_Add * Controller_P.radstorpm1_Gain;

  /* Sum: '<S6>/Add3' incorporates:
   *  Inport: '<Root>/B [T]'
   *  Inport: '<Root>/w_body'
   *  Product: '<S6>/Element product'
   */
  rtb_Gain_p[1] = Controller_U.omega_b[2] * Controller_U.BT[0] -
    Controller_U.omega_b[0] * Controller_U.BT[2];

  /* Outport: '<Root>/cmd_rpm ' incorporates:
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Kd'
   *  Gain: '<S4>/Kp'
   *  Gain: '<S4>/rad//s to rpm1'
   *  Inport: '<Root>/w_body'
   *  Sum: '<S4>/Sum'
   */
  Controller_Y.cmd_rpm[2] = (Controller_P.Gain_Gain * rtb_Gain_p[2] *
    Controller_P.Kp_Gain + Controller_P.Kd_Gain * Controller_U.omega_b[2]) *
    rtb_Add * Controller_P.radstorpm1_Gain;

  /* Sum: '<S6>/Add3' incorporates:
   *  Inport: '<Root>/B [T]'
   *  Inport: '<Root>/w_body'
   *  Product: '<S6>/Element product'
   */
  rtb_Gain_p[2] = Controller_U.omega_b[0] * Controller_U.BT[1] -
    Controller_U.omega_b[1] * Controller_U.BT[0];

  /* Product: '<S7>/Product' incorporates:
   *  Inport: '<Root>/B [T]'
   */
  rtb_Gain2 = Controller_U.BT[0] * Controller_U.BT[0];

  /* Product: '<S7>/Product1' incorporates:
   *  Inport: '<Root>/B [T]'
   */
  rtb_Gain1_o = Controller_U.BT[1] * Controller_U.BT[1];

  /* Product: '<S7>/Product2' incorporates:
   *  Inport: '<Root>/B [T]'
   */
  rtb_Gain_a = Controller_U.BT[2] * Controller_U.BT[2];

  /* Sum: '<S7>/Add' */
  rtb_Add = (rtb_Gain2 + rtb_Gain1_o) + rtb_Gain_a;

  /* Gain: '<S2>/Gain' incorporates:
   *  Product: '<S2>/Divide'
   */
  rtb_Gain_p[0] = rtb_Gain_p[0] / rtb_Add * Controller_P.Gain_Gain_k;

  /* Outport: '<Root>/cmd_M' */
  Controller_Y.cmd_M[0] = rtb_Gain_p[0];

  /* Gain: '<S2>/Gain' incorporates:
   *  Product: '<S2>/Divide'
   */
  rtb_Gain_p[1] = rtb_Gain_p[1] / rtb_Add * Controller_P.Gain_Gain_k;

  /* Outport: '<Root>/cmd_M' */
  Controller_Y.cmd_M[1] = rtb_Gain_p[1];

  /* Gain: '<S2>/Gain' incorporates:
   *  Product: '<S2>/Divide'
   */
  rtb_Gain_p[2] = rtb_Gain_p[2] / rtb_Add * Controller_P.Gain_Gain_k;

  /* Outport: '<Root>/cmd_M' */
  Controller_Y.cmd_M[2] = rtb_Gain_p[2];

  /* DotProduct: '<S5>/Dot Product' incorporates:
   *  Constant: '<S5>/Constant'
   *  Inport: '<Root>/B [T]'
   */
  rtb_Gain_a = (Controller_P.Constant_Value[0] * Controller_U.BT[0] +
                Controller_P.Constant_Value[1] * Controller_U.BT[1]) +
    Controller_P.Constant_Value[2] * Controller_U.BT[2];

  /* Signum: '<S5>/Sign' */
  if (rtb_Gain_a < 0.0) {
    rtb_Add = -1.0;
  } else if (rtb_Gain_a > 0.0) {
    rtb_Add = 1.0;
  } else if (rtb_Gain_a == 0.0) {
    rtb_Add = 0.0;
  } else {
    rtb_Add = (rtNaN);
  }

  /* End of Signum: '<S5>/Sign' */

  /* Gain: '<S5>/Gain' */
  rtb_Gain_a = -Controller_P.m_max * rtb_Add;

  /* DotProduct: '<S5>/Dot Product1' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Inport: '<Root>/B [T]'
   */
  rtb_Gain1_o = (Controller_P.Constant1_Value[0] * Controller_U.BT[0] +
                 Controller_P.Constant1_Value[1] * Controller_U.BT[1]) +
    Controller_P.Constant1_Value[2] * Controller_U.BT[2];

  /* Signum: '<S5>/Sign1' */
  if (rtb_Gain1_o < 0.0) {
    rtb_Add = -1.0;
  } else if (rtb_Gain1_o > 0.0) {
    rtb_Add = 1.0;
  } else if (rtb_Gain1_o == 0.0) {
    rtb_Add = 0.0;
  } else {
    rtb_Add = (rtNaN);
  }

  /* End of Signum: '<S5>/Sign1' */

  /* Gain: '<S5>/Gain1' */
  rtb_Gain1_o = -Controller_P.m_max * rtb_Add;

  /* DotProduct: '<S5>/Dot Product2' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Inport: '<Root>/B [T]'
   */
  rtb_Gain2 = (Controller_P.Constant2_Value[0] * Controller_U.BT[0] +
               Controller_P.Constant2_Value[1] * Controller_U.BT[1]) +
    Controller_P.Constant2_Value[2] * Controller_U.BT[2];

  /* Signum: '<S5>/Sign2' */
  if (rtb_Gain2 < 0.0) {
    rtb_Add = -1.0;
  } else if (rtb_Gain2 > 0.0) {
    rtb_Add = 1.0;
  } else if (rtb_Gain2 == 0.0) {
    rtb_Add = 0.0;
  } else {
    rtb_Add = (rtNaN);
  }

  /* End of Signum: '<S5>/Sign2' */

  /* Gain: '<S5>/Gain2' */
  rtb_Gain2 = -Controller_P.m_max * rtb_Add;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Controller_M->rtwLogInfo, (&Controller_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [1000.0s, 0.0s] */
    if ((rtmGetTFinal(Controller_M)!=-1) &&
        !((rtmGetTFinal(Controller_M)-Controller_M->Timing.taskTime0) >
          Controller_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Controller_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Controller_M->Timing.clockTick0)) {
    ++Controller_M->Timing.clockTickH0;
  }

  Controller_M->Timing.taskTime0 = Controller_M->Timing.clockTick0 *
    Controller_M->Timing.stepSize0 + Controller_M->Timing.clockTickH0 *
    Controller_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Controller_M, 0,
                sizeof(RT_MODEL_Controller_T));
  rtmSetTFinal(Controller_M, 50000.0);
  Controller_M->Timing.stepSize0 = 1000.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Controller_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Controller_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Controller_M->rtwLogInfo, (NULL));
    rtliSetLogT(Controller_M->rtwLogInfo, "tout");
    rtliSetLogX(Controller_M->rtwLogInfo, "");
    rtliSetLogXFinal(Controller_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Controller_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Controller_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Controller_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Controller_M->rtwLogInfo, 1);
    rtliSetLogY(Controller_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Controller_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Controller_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  (void) memset((void *)&Controller_Y, 0,
                sizeof(ExtY_Controller_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Controller_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Controller_M), Controller_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Controller_M)));
}

/* Model terminate function */
void Controller_terminate(void)
{
  /* (no terminate code required) */
}

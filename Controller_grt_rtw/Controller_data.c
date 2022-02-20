/*
 * Controller_data.c
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

/* Block parameters (default storage) */
P_Controller_T Controller_P = {
  /* Variable: Jw
   * Referenced by: '<S4>/Gain1'
   */
  2.029E-6,

  /* Variable: m_max
   * Referenced by:
   *   '<S5>/Gain'
   *   '<S5>/Gain1'
   *   '<S5>/Gain2'
   */
  0.24,

  /* Expression: 2
   * Referenced by: '<S4>/Gain'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S4>/Kp'
   */
  1.0,

  /* Expression: 0.2
   * Referenced by: '<S4>/Kd'
   */
  0.2,

  /* Expression: 1/0.104719755
   * Referenced by: '<S4>/rad//s to rpm1'
   */
  9.5492965964253838,

  /* Expression: -1
   * Referenced by: '<S2>/Gain'
   */
  -1.0,

  /* Expression: [1;0;0]
   * Referenced by: '<S5>/Constant'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: [0;1;0]
   * Referenced by: '<S5>/Constant1'
   */
  { 0.0, 1.0, 0.0 },

  /* Expression: [0;0;1]
   * Referenced by: '<S5>/Constant2'
   */
  { 0.0, 0.0, 1.0 }
};

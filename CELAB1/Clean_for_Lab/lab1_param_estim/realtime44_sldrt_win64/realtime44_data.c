/*
 * realtime44_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtime44".
 *
 * Model version              : 1.4
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Apr  4 11:14:19 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "realtime44.h"

/* Block parameters (default storage) */
P_realtime44_T realtime44_P = {
  /* Variable: inert_est
   * Referenced by: '<S8>/Vector'
   */
  {
    450.0,
    1.0,
    10.0,

    { 32.142857142857146, -32.142857142857146, 32.142857142857146,
      -32.142857142857146, 32.142857142857146, -32.142857142857146,
      32.142857142857146, -32.142857142857146, 32.142857142857146,
      -32.142857142857146, 32.142857142857146, -32.142857142857146,
      32.142857142857146, -32.142857142857146, 32.142857142857146,
      -32.142857142857146, 32.142857142857146, -32.142857142857146,
      32.142857142857146, -32.142857142857146 }
  },

  /* Variable: frict_est
   * Referenced by: '<S6>/Vector'
   */
  {
    45.0,
    5.0,
    9.0,

    { 45.0, 90.0, 135.0, 180.0, 225.0, 270.0, 315.0, 360.0, 405.0, 0.0, -45.0,
      -90.0, -135.0, -180.0, -225.0, -270.0, -315.0, -360.0, -405.0 }
  },

  /* Variable: sens
   * Referenced by:
   *   '<Root>/pulse2deg'
   *   '<S4>/1//R_shunt'
   */
  {
    {
      0.5
    },

    {
      2000.0,
      0.18,
      0.0031415926535897933,
      5.5555555555555554,
      318.3098861837907
    },

    {
      {
        10000.0,
        5.0,
        345.0,
        6.0213859193804371
      },
      0.014492753623188406,
      0.83037361613162786,
      69.0,
      1.2042771838760873
    }
  },

  /* Variable: filt
   * Referenced by:
   *   '<S4>/Butterworth Derivative'
   *   '<S4>/Butterworth Derivative1'
   *   '<S4>/Low-Pass i_a'
   */
  {
    {
      125.66370614359172,
      0.70710678118654746,

      { 15791.367041742973, 0.0 },

      { 1.0, 177.71531752633462, 15791.367041742973 }
    },

    {
      125.66370614359172,
      0.70710678118654746,
      15791.367041742973,

      { 1.0, 177.71531752633462, 15791.367041742973 }
    }
  },

  /* Variable: gbox
   * Referenced by: '<S4>/Gearbox'
   */
  {
    14.0,
    0.8,
    1.0,
    1.4e-6,
    1.0,
    14.0,
    0.8,
    4.2e-6
  },

  /* Variable: PID
   * Referenced by:
   *   '<S1>/Kd'
   *   '<S1>/Ki'
   *   '<S1>/Kp'
   */
  {
    90.0,
    60.0,
    0.4,
    0.00097252,
    0.15,
    33.333333333333336
  },

  /* Variable: step_resp
   * Referenced by: '<S7>/Vector'
   */
  {
    360.0,
    5.0,
    1.0,
    360.0
  },

  /* Variable: sIn
   * Referenced by: '<S2>/Step'
   */
  {
    3.0,
    20.0
  },

  /* Variable: degs2rpm
   * Referenced by: '<S4>/degs2rpm'
   */
  0.16666666666666666,

  /* Variable: rpm2degs
   * Referenced by:
   *   '<S2>/rpm2degs'
   *   '<S2>/rpm2degs1'
   */
  6.0,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<S3>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<S3>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<S3>/Encoder Input'
   */
  INFINITY,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<S3>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<S3>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<S3>/Analog Output'
   */
  10.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<S3>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<S3>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<S3>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<S3>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<S3>/Analog Input'
   */
  { 0, 1 },

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<S3>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<S3>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<S3>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<S3>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<S3>/Analog Output'
   */
  0,

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S11>/FixPt Switch'
   */
  18U,

  /* Mask Parameter: WrapToZero_Threshold_p
   * Referenced by: '<S14>/FixPt Switch'
   */
  0U,

  /* Mask Parameter: WrapToZero_Threshold_n
   * Referenced by: '<S17>/FixPt Switch'
   */
  19U,

  /* Expression: 0
   * Referenced by: '<S2>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator2'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S5>/Gain1'
   */
  0.017453292519943295,

  /* Computed Parameter: RealDerivative_A
   * Referenced by: '<S1>/Real Derivative'
   */
  -1028.2564882984411,

  /* Computed Parameter: RealDerivative_C
   * Referenced by: '<S1>/Real Derivative'
   */
  -1.0573114057278421E+6,

  /* Computed Parameter: RealDerivative_D
   * Referenced by: '<S1>/Real Derivative'
   */
  1028.2564882984411,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S1>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/Saturation'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator1'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S11>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S14>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S17>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S12>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S10>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition_n
   * Referenced by: '<S9>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value_l
   * Referenced by: '<S13>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_a
   * Referenced by: '<S16>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition_i
   * Referenced by: '<S15>/Output'
   */
  0U
};

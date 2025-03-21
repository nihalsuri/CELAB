/*
 * realtimeModel_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtimeModel".
 *
 * Model version              : 1.2
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Mar 21 13:28:15 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "realtimeModel.h"

/* Block parameters (default storage) */
P_realtimeModel_T realtimeModel_P = {
  /* Variable: sIn
   * Referenced by:
   *   '<S3>/Vector'
   *   '<S5>/Vector'
   */
  {
    { 10.0, 30.0, 50.0, 90.0, 180.0, 360.0 },
    3.0,
    0.0,
    5.0,
    9.0,
    45.0,
    1.0,
    10.0,
    450.0,
    95.0,

    { 45.0, 90.0, 135.0, 180.0, 225.0, 270.0, 315.0, 360.0, 405.0, 0.0, -45.0,
      -90.0, -135.0, -180.0, -225.0, -270.0, -315.0, -360.0, -405.0 },
    11.0,

    { 10.0, 0.0, 30.0, 0.0, 50.0, 0.0, 90.0, 0.0, 180.0, 0.0, 360.0 },
    33.0,

    { 450.0, -450.0, 450.0, -450.0, 450.0, -450.0, 450.0, -450.0, 450.0, -450.0,
      450.0, -450.0, 450.0, -450.0, 450.0, -450.0, 450.0, -450.0, 450.0, -450.0
    },
    20.0
  },

  /* Variable: sens
   * Referenced by:
   *   '<Root>/pulse2deg'
   *   '<S1>/1//R_shunt'
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
   *   '<S1>/Butterworth Derivative'
   *   '<S1>/Butterworth Derivative1'
   *   '<S1>/Low-Pass i_a'
   */
  {
    {
      75.398223686155035,
      0.70710678118654746,

      { 5684.89213502747, 0.0 },

      { 1.0, 106.62919051580077, 5684.89213502747 }
    },

    {
      94.247779607693786,
      0.70710678118654746,
      8882.64396098042,

      { 1.0, 133.28648814475096, 8882.64396098042 }
    }
  },

  /* Variable: gbox
   * Referenced by: '<S1>/Gearbox'
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
   *   '<S2>/Gain'
   *   '<S2>/Gain1'
   *   '<S2>/Gain2'
   *   '<S2>/Saturation1'
   */
  {
    90.0,
    70.0,
    0.4,
    0.0014024826245610485,
    7.0
  },

  /* Variable: degs2rpm
   * Referenced by: '<S1>/degs2rpm'
   */
  0.16666666666666666,

  /* Variable: rpm2degs
   * Referenced by:
   *   '<Root>/rpm2degs'
   *   '<Root>/rpm2degs1'
   */
  6.0,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<S6>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<S6>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<S6>/Encoder Input'
   */
  INFINITY,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<S6>/Analog Input'
   */
  10.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<S6>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<S6>/Analog Output'
   */
  10.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<S6>/Analog Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<S6>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<S6>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<S6>/Analog Input'
   */
  { 0, 1 },

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<S6>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<S6>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<S6>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<S6>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<S6>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<S6>/Analog Output'
   */
  0,

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S16>/FixPt Switch'
   */
  19U,

  /* Mask Parameter: WrapToZero_Threshold_n
   * Referenced by: '<S10>/FixPt Switch'
   */
  18U,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S7>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S2>/Transfer Fcn'
   */
  -713.02131127149028,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S2>/Transfer Fcn'
   */
  -508399.39032731543,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<S2>/Transfer Fcn'
   */
  713.02131127149028,

  /* Expression: 10
   * Referenced by: '<S2>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S2>/Saturation'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S10>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S16>/Constant'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S15>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S14>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value_a
   * Referenced by: '<S9>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition_i
   * Referenced by: '<S8>/Output'
   */
  0U
};

/*
 * realtimemodel_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtimemodel".
 *
 * Model version              : 1.8
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri May 16 12:51:20 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "realtimemodel.h"

/* Block parameters (default storage) */
P_realtimemodel_T realtimemodel_P = {
  /* Variable: LQR
   * Referenced by: '<S2>/State-Space'
   */
  {
    100.0,
    10.0,
    0.26179938779914941,
    10.0,
    0.01,

    { 0.0, -1481.5602756824496, 1.0, 0.0 },

    { 0.0, 1.0 },

    { 14815.602756824497, 0.0 },
    0.0,

    { 0.0, -1481.5602756824496, 1.0, 0.0 },

    { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

    { 0.0, 14815.602756824497, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.8197186342054885, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0 },

    { 14.590250444496643, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 219502085.04802564, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
    0.01,

    { 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 14.590250444496643, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      219502085.04802564, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
    0.01
  },

  /* Variable: feedback
   * Referenced by:
   *   '<S2>/Input feedforward gain (Nu)'
   *   '<S2>/Integral gain'
   *   '<S2>/State feedback gain'
   *   '<S2>/State feedforward gain(Nx)'
   */
  {
    { 42.217775824846683, -116.48596752676717, 3.8510760998188514,
      0.6374378026013805, 27245.885734770945, -3783.4575536682337 },

    { 1.0, -0.0, -0.0, 0.0, -0.0, 0.0, 0.0 },

    { 1.0, -0.0, -0.0, 0.0, -0.0, 0.0 },
    0.0,

    { 31.622776601683864, 42.217775824846683, -116.48596752676717,
      3.8510760998188514, 0.6374378026013805, 27245.885734770945,
      -3783.4575536682337 },
    31.622776601683864,

    { 42.217775824846683, -116.48596752676717, 3.8510760998188514,
      0.6374378026013805, 27245.885734770945, -3783.4575536682337 }
  },

  /* Variable: sens
   * Referenced by:
   *   '<Root>/Pulses2Deg'
   *   '<S1>/V2Deg1'
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
    },

    {
      {
        10000.0,
        5.0,
        340.0,
        5.9341194567807207
      },
      0.014705882352941176,
      0.84258499283944588,
      68.0,
      1.1868238913561442,

      {
        3.5e-7
      }
    }
  },

  /* Variable: sIn
   * Referenced by:
   *   '<Root>/Step2'
   *   '<S2>/Integrator Choice'
   *   '<S7>/Lower Limit'
   *   '<S7>/Upper Limit'
   */
  {
    0.0,
    1.0,
    0.0001,
    50.0,
    3.0,
    3.0,
    0.2,
    0.7
  },

  /* Variable: deg2rad
   * Referenced by:
   *   '<S2>/deg2rad'
   *   '<S2>/deg2rad_1'
   */
  0.017453292519943295,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<S4>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<S4>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<S4>/Encoder Input'
   */
  INFINITY,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<S4>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<S4>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<S4>/Analog Output'
   */
  10.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<S4>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<S4>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<S4>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<S4>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<S4>/Analog Input'
   */
  { 2, 3 },

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<S4>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<S4>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<S4>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<S4>/Analog Input'
   */
  1,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<S4>/Analog Output'
   */
  0,

  /* Computed Parameter: Out_Y0
   * Referenced by: '<S6>/Out'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.0020000000000000005,

  /* Expression: 0
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: uV_Y0
   * Referenced by: '<S2>/u [V]'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: eye(2,2)
   * Referenced by: '<S2>/State-Space'
   */
  { 1.0, 0.0, 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S2>/State-Space'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S2>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S2>/Saturation'
   */
  -10.0,

  /* Expression: 50
   * Referenced by: '<Root>/Pulse Generator'
   */
  50.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  1000.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  500.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Realderivative_A
   * Referenced by: '<S3>/Real derivative'
   */
  { -444.2882938158366, -98696.044010893587 },

  /* Computed Parameter: Realderivative_C
   * Referenced by: '<S3>/Real derivative'
   */
  { 98696.044010893587, 0.0 },

  /* Computed Parameter: Realderivative1_A
   * Referenced by: '<S3>/Real derivative1'
   */
  { -444.2882938158366, -98696.044010893587 },

  /* Computed Parameter: Realderivative1_C
   * Referenced by: '<S3>/Real derivative1'
   */
  { 98696.044010893587, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Step2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step2'
   */
  1.0
};

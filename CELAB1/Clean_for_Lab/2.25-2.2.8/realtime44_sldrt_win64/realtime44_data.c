/*
 * realtime44_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtime44".
 *
 * Model version              : 1.6
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Apr  4 12:21:41 2025
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
  /* Variable: sens
   * Referenced by: '<Root>/Gain1'
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
   * Referenced by: '<S1>/High-pass filter (real derivative)'
   */
  {
    {
      314.15926535897933,
      0.70710678118654746,

      { 98696.044010893587, 0.0 },

      { 1.0, 444.2882938158366, 98696.044010893587 }
    }
  },

  /* Variable: sIn
   * Referenced by:
   *   '<Root>/Constant'
   *   '<Root>/Sine Wave'
   *   '<Root>/Step'
   */
  {
    6.0,
    90.0,
    0.5,
    12.566370614359172,
    1.0,
    5.0
  },

  /* Variable: deg2rad
   * Referenced by:
   *   '<S2>/deg2rad'
   *   '<S2>/deg2rad2'
   */
  0.017453292519943295,

  /* Variable: degs2rpm
   * Referenced by: '<S1>/degs2rpm'
   */
  0.16666666666666666,

  /* Variable: rpm2rads
   * Referenced by: '<S2>/rpm2rads'
   */
  0.10471975511965977,

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

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression:  [feedback.K(4) feedback.K(5)]
   * Referenced by: '<S2>/Gain'
   */
  { 52.151571256837833, 0.664283910710894 },

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S2>/Transfer Fcn'
   */
  { -0.0, -157.91367041742973, -0.0 },

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S2>/Transfer Fcn'
   */
  { 1661.7021102943338, 24951.812430143946, 270796.46554307052 },

  /* Expression: 10
   * Referenced by: '<S2>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S2>/Saturation'
   */
  -10.0
};

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
 * C source code generated on : Fri Apr  4 12:39:23 2025
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
   * Referenced by: '<Root>/pulse2deg'
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

  /* Variable: feedback
   * Referenced by:
   *   '<S3>/Input feedforward gain (Nu)'
   *   '<S3>/Integrator feedback'
   *   '<S3>/State feedback gain'
   *   '<S3>/State feedforward gain(Nx)'
   */
  {
    {
      {
        { 572.96806579017152, 33.874345248271347, 0.54040493265390943 },
        572.96806579017152,

        { 33.874345248271347, 0.54040493265390943 }
      }
    },

    {
      {
        { 6.9928977934353931, 0.051651342565983034 },
        15.0
      }
    },

    { 1.0, -0.0 },
    0.0
  },

  /* Variable: sIn
   * Referenced by: '<S1>/Vector'
   */
  {
    { 0.0, 40.0, 0.0, 70.0, 0.0, 120.0, 0.0 },
    7.0,
    5.0,
    34.0
  },

  /* Variable: filt
   * Referenced by: '<S2>/High-pass filter (real derivative)'
   */
  {
    {
      314.15926535897933,
      0.70710678118654746,

      { 98696.044010893587, 0.0 },

      { 1.0, 444.2882938158366, 98696.044010893587 }
    }
  },

  /* Variable: deg2rad
   * Referenced by:
   *   '<S3>/deg2rad'
   *   '<S3>/deg2rad2'
   */
  0.017453292519943295,

  /* Variable: degs2rpm
   * Referenced by: '<S2>/degs2rpm'
   */
  0.16666666666666666,

  /* Variable: rpm2rads
   * Referenced by: '<S3>/rpm2rads'
   */
  0.10471975511965977,

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
  { 0, 1 },

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
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<S4>/Analog Output'
   */
  0,

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S7>/FixPt Switch'
   */
  6U,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S3>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S3>/Saturation'
   */
  -10.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S7>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S5>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S6>/FixPt Constant'
   */
  1U
};

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
 * C source code generated on : Fri May 16 13:25:17 2025
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
  /* Variable: sens
   * Referenced by: '<S1>/Gain2'
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

  /* Variable: obs3
   * Referenced by: '<S4>/Discrete State-Space'
   */
  {
    2.450875136158456,
    0.0067379469990854687,

    { 4.2669993224671865, -2.4343612693896439 },

    { 0.0, 1.0 },

    { 0.0, 0.0, 1.0, 2.450875136158456 }
  },

  /* Variable: feedback3
   * Referenced by:
   *   '<S2>/Input feedforward gain (Nu)'
   *   '<S2>/Integral gain'
   *   '<S2>/State feedback gain'
   *   '<S2>/State feedforward gain(Nx)'
   */
  {
    2.657683383273119,

    { 7.2680620682879162, 0.062112755460561775 },

    { 1.0, -0.0 },
    0.0
  },

  /* Variable: deg2rad
   * Referenced by:
   *   '<S2>/deg2rad'
   *   '<S2>/deg2rad2'
   */
  0.017453292519943295,

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
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Step'
   */
  50.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: zeros(2,2)
   * Referenced by: '<S4>/Discrete State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S4>/Discrete State-Space'
   */
  0.0,

  /* Expression: obs3.J0(:,2)
   * Referenced by: '<S4>/2nd Col of J0'
   */
  { 1.0, 2.450875136158456 },

  /* Expression: 10
   * Referenced by: '<S2>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S2>/Saturation'
   */
  -10.0
};

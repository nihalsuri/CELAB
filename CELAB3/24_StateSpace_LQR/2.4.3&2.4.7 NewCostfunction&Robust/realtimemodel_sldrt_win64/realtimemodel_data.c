/*
 * realtimemodel_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtimemodel".
 *
 * Model version              : 1.7
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri May 16 12:31:47 2025
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

  /* Variable: feedback
   * Referenced by:
   *   '<S8>/Input feedforward gain (Nu)'
   *   '<S8>/State feedback gain'
   *   '<S8>/State feedforward gain(Nx)'
   *   '<S9>/Input feedforward gain (Nu)'
   *   '<S9>/Integral gain'
   *   '<S9>/State feedback gain'
   *   '<S9>/State feedforward gain(Nx)'
   */
  {
    { 38.197186342054756, -69.579968896809945, 3.2455503056392354,
      0.63077956818641723 },

    { 1.0, -0.0, -0.0, 0.0, 0.0 },

    { 1.0, -0.0, -0.0, 0.0 },
    0.0,

    { 38.208392464894395, -69.576141924439256, 3.2461721952485414,
      0.63130546709697943 },
    0.10000000000010843
  },

  /* Variable: sIn
   * Referenced by:
   *   '<Root>/Step1'
   *   '<S2>/Constant'
   *   '<S2>/Step'
   *   '<S2>/Step2'
   *   '<S7>/Lower Limit'
   *   '<S7>/Upper Limit'
   */
  {
    0.0,
    0.0,
    0.0001,
    50.0,
    3.0,
    3.0,
    0.2,
    0.7
  },

  /* Variable: deg2rad
   * Referenced by:
   *   '<S8>/deg2rad'
   *   '<S8>/deg2rad_1'
   *   '<S9>/deg2rad'
   *   '<S9>/deg2rad_1'
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
   * Referenced by: '<S8>/u [V]'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S8>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S8>/Saturation'
   */
  -10.0,

  /* Computed Parameter: uV_Y0_e
   * Referenced by: '<S9>/u [V]'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Integrator'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S9>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S9>/Saturation'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step1'
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
   * Referenced by: '<S2>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Step2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Step2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0
};

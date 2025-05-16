/*
 * realtimemodel_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtimemodel".
 *
 * Model version              : 1.3
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri May 16 11:50:36 2025
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
   * Referenced by: '<Root>/Pulses2Deg'
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
   *   '<Root>/Step1'
   *   '<S1>/Constant'
   */
  {
    0.0,
    0.0,
    1.0,
    120.0,
    0.0001,
    3.0,
    3.0,
    0.2,
    0.3
  },

  /* Variable: PID
   * Referenced by:
   *   '<S3>/Gain'
   *   '<S3>/Gain1'
   *   '<S3>/Gain2'
   *   '<S3>/Gain3'
   *   '<S4>/Gain'
   *   '<S4>/Gain1'
   *   '<S4>/Gain2'
   */
  {
    2.0,
    3.0,
    5.0,
    0.0506964268213032,
    5.882352941176471
  },

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<S2>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<S2>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<S2>/Encoder Input'
   */
  INFINITY,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<S2>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<S2>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<S2>/Analog Output'
   */
  10.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<S2>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<S2>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<S2>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<S2>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<S2>/Analog Input'
   */
  { 2, 3 },

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<S2>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<S2>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<S2>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<S2>/Analog Input'
   */
  1,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<S2>/Analog Output'
   */
  0,

  /* Expression: 12
   * Referenced by: '<S4>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<S4>/Saturation'
   */
  -12.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step1'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S5>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S3>/Transfer Fcn'
   */
  -19.7252560525585,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S3>/Transfer Fcn'
   */
  -389.0857263389957,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<S3>/Transfer Fcn'
   */
  19.7252560525585,

  /* Expression: 12
   * Referenced by: '<S3>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<S3>/Saturation'
   */
  -12.0,

  /* Expression: pi/180
   * Referenced by: '<S6>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A_h
   * Referenced by: '<S4>/Transfer Fcn'
   */
  -19.7252560525585,

  /* Computed Parameter: TransferFcn_C_k
   * Referenced by: '<S4>/Transfer Fcn'
   */
  -389.0857263389957,

  /* Computed Parameter: TransferFcn_D_k
   * Referenced by: '<S4>/Transfer Fcn'
   */
  19.7252560525585,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0
};

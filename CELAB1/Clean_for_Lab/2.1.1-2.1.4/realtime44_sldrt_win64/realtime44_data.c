/*
 * realtime44_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtime44".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Apr  4 11:39:55 2025
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
  /* Variable: feedforward
   * Referenced by:
   *   '<S7>/Vector'
   *   '<S8>/Vector'
   *   '<S17>/Vector'
   */
  {
    900.0,
    0.5,
    2.0,

    { 900.0, 0.0, -900.0, -900.0, 0.0, 900.0, 900.0, 0.0, -900.0, -900.0, 0.0,
      900.0 }
  },

  /* Variable: sens
   * Referenced by: '<Root>/Gain'
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
   *   '<S5>/Butterworth Derivative1'
   *   '<S6>/Butterworth Derivative1'
   *   '<S6>/Butterworth Derivative2'
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

  /* Variable: PID
   * Referenced by:
   *   '<S2>/Kd'
   *   '<S2>/Ki'
   *   '<S2>/Kp'
   */
  {
    7.845,
    100.8347,
    0.0763,
    0.00097252,
    0.15,
    30.0
  },

  /* Variable: windup
   * Referenced by: '<S16>/Vector'
   */
  {
    360.0,
    5.0,
    1.0,
    360.0
  },

  /* Variable: sIn
   * Referenced by:
   *   '<S1>/Step'
   *   '<S1>/Step1'
   *   '<S3>/Step'
   */
  {
    2.0,
    6.0
  },

  /* Variable: degs2rpm
   * Referenced by:
   *   '<Root>/degs2rpm1'
   *   '<Root>/degs2rpm2'
   *   '<S5>/degs2rpm1'
   *   '<S6>/degs2rpm1'
   */
  0.16666666666666666,

  /* Variable: rpm2degs
   * Referenced by:
   *   '<S1>/rpm2degs1'
   *   '<S1>/rpm2degs2'
   *   '<S3>/rpm2degs1'
   */
  6.0,

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
   * Referenced by: '<S11>/FixPt Switch'
   */
  11U,

  /* Mask Parameter: WrapToZero_Threshold_g
   * Referenced by: '<S14>/FixPt Switch'
   */
  11U,

  /* Mask Parameter: WrapToZero_Threshold_m
   * Referenced by: '<S20>/FixPt Switch'
   */
  0U,

  /* Mask Parameter: WrapToZero_Threshold_e
   * Referenced by: '<S23>/FixPt Switch'
   */
  11U,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator2'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S15>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Computed Parameter: RealDerivative_A
   * Referenced by: '<S2>/Real Derivative'
   */
  -1028.2564882984411,

  /* Computed Parameter: RealDerivative_C
   * Referenced by: '<S2>/Real Derivative'
   */
  -1.0573114057278421E+6,

  /* Computed Parameter: RealDerivative_D
   * Referenced by: '<S2>/Real Derivative'
   */
  1028.2564882984411,

  /* Expression: 10
   * Referenced by: '<S2>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S2>/Saturation'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator1'
   */
  0.0,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S11>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S14>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_k
   * Referenced by: '<S20>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S23>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S12>/Output'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_g
   * Referenced by: '<S18>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S10>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition_f
   * Referenced by: '<S9>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value_a
   * Referenced by: '<S13>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_b
   * Referenced by: '<S19>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_j
   * Referenced by: '<S22>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition_h
   * Referenced by: '<S21>/Output'
   */
  0U
};

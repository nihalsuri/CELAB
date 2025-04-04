/*
 * realtime44_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(struct_c5vVpuBCuvBcHq3zEoVR5C),
  sizeof(struct_qNekjJ1RglMGc2fPYYDfGB),
  sizeof(struct_M3GTBhBY6Ysk6vVyrpXTEH),
  sizeof(struct_vHPMdAr9HfDgWNbG6U3SfC),
  sizeof(struct_nZqFUEOh71pPhzsMP64FWD),
  sizeof(struct_DqRrFctOcoTwJhkxMXTGZG),
  sizeof(struct_t4jfYKvXkqvqbOrnXV9flF),
  sizeof(struct_8LnTg2HasR61N4e63tMdJ),
  sizeof(struct_i3LpJ6wE5WSH5fTRRwU1pH),
  sizeof(struct_w2rpjrheReKyNwtRQGQEfF),
  sizeof(struct_OYB0L6tkYmibNjdB0Biu2E),
  sizeof(struct_5qY1uoShzFQMDeMPZ5vyJ),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "int64_T",
  "uint64_T",
  "struct_c5vVpuBCuvBcHq3zEoVR5C",
  "struct_qNekjJ1RglMGc2fPYYDfGB",
  "struct_M3GTBhBY6Ysk6vVyrpXTEH",
  "struct_vHPMdAr9HfDgWNbG6U3SfC",
  "struct_nZqFUEOh71pPhzsMP64FWD",
  "struct_DqRrFctOcoTwJhkxMXTGZG",
  "struct_t4jfYKvXkqvqbOrnXV9flF",
  "struct_8LnTg2HasR61N4e63tMdJ",
  "struct_i3LpJ6wE5WSH5fTRRwU1pH",
  "struct_w2rpjrheReKyNwtRQGQEfF",
  "struct_OYB0L6tkYmibNjdB0Biu2E",
  "struct_5qY1uoShzFQMDeMPZ5vyJ",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&realtime44_B.omega_lrpm), 0, 0, 14 },

  { (char_T *)(&realtime44_B.FixPtSwitch), 3, 0, 4 }
  ,

  { (char_T *)(&realtime44_DW.omega_motorrpm_PWORK.LoggedData[0]), 11, 0, 9 },

  { (char_T *)(&realtime44_DW.Output_DSTATE), 3, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&realtime44_P.feedforward), 17, 0, 1 },

  { (char_T *)(&realtime44_P.sens), 24, 0, 1 },

  { (char_T *)(&realtime44_P.filt), 28, 0, 1 },

  { (char_T *)(&realtime44_P.PID), 25, 0, 1 },

  { (char_T *)(&realtime44_P.windup), 18, 0, 1 },

  { (char_T *)(&realtime44_P.sIn), 19, 0, 1 },

  { (char_T *)(&realtime44_P.degs2rpm), 0, 0, 11 },

  { (char_T *)(&realtime44_P.EncoderInput_Channels), 6, 0, 8 },

  { (char_T *)(&realtime44_P.WrapToZero_Threshold), 3, 0, 4 },

  { (char_T *)(&realtime44_P.Step_Time), 0, 0, 18 },

  { (char_T *)(&realtime44_P.Constant_Value_l), 3, 0, 12 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  11U,
  rtPTransitions
};

/* [EOF] realtime44_dt.h */

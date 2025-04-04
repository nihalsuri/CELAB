/*
 * realtime44_dt.h
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
  sizeof(struct_JmbS1NTaRoFDP7AWEpmGfB),
  sizeof(struct_qNekjJ1RglMGc2fPYYDfGB),
  sizeof(struct_iAyH5DzK0NcqCq11O1IAtF),
  sizeof(struct_i3LpJ6wE5WSH5fTRRwU1pH),
  sizeof(struct_M3GTBhBY6Ysk6vVyrpXTEH),
  sizeof(struct_vHPMdAr9HfDgWNbG6U3SfC),
  sizeof(struct_nZqFUEOh71pPhzsMP64FWD),
  sizeof(struct_DqRrFctOcoTwJhkxMXTGZG),
  sizeof(struct_t4jfYKvXkqvqbOrnXV9flF),
  sizeof(struct_8LnTg2HasR61N4e63tMdJ),
  sizeof(struct_w2rpjrheReKyNwtRQGQEfF),
  sizeof(struct_OYB0L6tkYmibNjdB0Biu2E),
  sizeof(struct_5qY1uoShzFQMDeMPZ5vyJ),
  sizeof(struct_tqEcQv8wI4rPb7WqAAnbuH),
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
  "struct_JmbS1NTaRoFDP7AWEpmGfB",
  "struct_qNekjJ1RglMGc2fPYYDfGB",
  "struct_iAyH5DzK0NcqCq11O1IAtF",
  "struct_i3LpJ6wE5WSH5fTRRwU1pH",
  "struct_M3GTBhBY6Ysk6vVyrpXTEH",
  "struct_vHPMdAr9HfDgWNbG6U3SfC",
  "struct_nZqFUEOh71pPhzsMP64FWD",
  "struct_DqRrFctOcoTwJhkxMXTGZG",
  "struct_t4jfYKvXkqvqbOrnXV9flF",
  "struct_8LnTg2HasR61N4e63tMdJ",
  "struct_w2rpjrheReKyNwtRQGQEfF",
  "struct_OYB0L6tkYmibNjdB0Biu2E",
  "struct_5qY1uoShzFQMDeMPZ5vyJ",
  "struct_tqEcQv8wI4rPb7WqAAnbuH",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&realtime44_B.omega_lrpm), 0, 0, 13 },

  { (char_T *)(&realtime44_B.FixPtSwitch), 3, 0, 3 }
  ,

  { (char_T *)(&realtime44_DW.Omega_loadrpm_PWORK.LoggedData), 11, 0, 9 },

  { (char_T *)(&realtime44_DW.Output_DSTATE), 3, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&realtime44_P.inert_est), 19, 0, 1 },

  { (char_T *)(&realtime44_P.frict_est), 17, 0, 1 },

  { (char_T *)(&realtime44_P.sens), 26, 0, 1 },

  { (char_T *)(&realtime44_P.filt), 29, 0, 1 },

  { (char_T *)(&realtime44_P.gbox), 30, 0, 1 },

  { (char_T *)(&realtime44_P.PID), 20, 0, 1 },

  { (char_T *)(&realtime44_P.step_resp), 18, 0, 1 },

  { (char_T *)(&realtime44_P.sIn), 21, 0, 1 },

  { (char_T *)(&realtime44_P.degs2rpm), 0, 0, 11 },

  { (char_T *)(&realtime44_P.EncoderInput_Channels), 6, 0, 8 },

  { (char_T *)(&realtime44_P.WrapToZero_Threshold), 3, 0, 3 },

  { (char_T *)(&realtime44_P.Step_Time), 0, 0, 12 },

  { (char_T *)(&realtime44_P.Constant_Value), 3, 0, 9 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  13U,
  rtPTransitions
};

/* [EOF] realtime44_dt.h */

/*
 * realtime44_dt.h
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
  sizeof(struct_bqXfskVfKnpGQWgWt5iSAG),
  sizeof(struct_vHPMdAr9HfDgWNbG6U3SfC),
  sizeof(struct_nZqFUEOh71pPhzsMP64FWD),
  sizeof(struct_DqRrFctOcoTwJhkxMXTGZG),
  sizeof(struct_t4jfYKvXkqvqbOrnXV9flF),
  sizeof(struct_8LnTg2HasR61N4e63tMdJ),
  sizeof(struct_w2rpjrheReKyNwtRQGQEfF),
  sizeof(struct_LYXsnuLmZkcUvicgq9G2LH),
  sizeof(int32_T),
  sizeof(int32_T),
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
  "struct_bqXfskVfKnpGQWgWt5iSAG",
  "struct_vHPMdAr9HfDgWNbG6U3SfC",
  "struct_nZqFUEOh71pPhzsMP64FWD",
  "struct_DqRrFctOcoTwJhkxMXTGZG",
  "struct_t4jfYKvXkqvqbOrnXV9flF",
  "struct_8LnTg2HasR61N4e63tMdJ",
  "struct_w2rpjrheReKyNwtRQGQEfF",
  "struct_LYXsnuLmZkcUvicgq9G2LH",
  "struct_ZfLjnmLlX3yC1iHvCWo1uC",
  "struct_hDq0yPoHBiSVH1Fuw8ePMG",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&realtime44_B.thi_ldeg), 0, 0, 3 }
  ,

  { (char_T *)(&realtime44_DW.EncoderInput_PWORK), 11, 0, 5 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  2U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&realtime44_P.sens), 22, 0, 1 },

  { (char_T *)(&realtime44_P.filt), 24, 0, 1 },

  { (char_T *)(&realtime44_P.sIn), 17, 0, 1 },

  { (char_T *)(&realtime44_P.deg2rad), 0, 0, 12 },

  { (char_T *)(&realtime44_P.EncoderInput_Channels), 6, 0, 8 },

  { (char_T *)(&realtime44_P.SineWave_Bias), 0, 0, 14 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] realtime44_dt.h */

/*
 * realtimemodel_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtimemodel".
 *
 * Model version              : 1.3
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri May 16 11:07:27 2025
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
  sizeof(struct_PsxgvbRLes4DlOQfHx6iWC),
  sizeof(struct_vHPMdAr9HfDgWNbG6U3SfC),
  sizeof(struct_nZqFUEOh71pPhzsMP64FWD),
  sizeof(struct_DqRrFctOcoTwJhkxMXTGZG),
  sizeof(struct_t4jfYKvXkqvqbOrnXV9flF),
  sizeof(struct_i7ZlkOl9k9qbhxQhPErSIE),
  sizeof(struct_nhbocl71hD6FRzHagkwJFB),
  sizeof(struct_4jr0aBoeUcVnCi5PWU4anE),
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
  "struct_PsxgvbRLes4DlOQfHx6iWC",
  "struct_vHPMdAr9HfDgWNbG6U3SfC",
  "struct_nZqFUEOh71pPhzsMP64FWD",
  "struct_DqRrFctOcoTwJhkxMXTGZG",
  "struct_t4jfYKvXkqvqbOrnXV9flF",
  "struct_i7ZlkOl9k9qbhxQhPErSIE",
  "struct_nhbocl71hD6FRzHagkwJFB",
  "struct_4jr0aBoeUcVnCi5PWU4anE",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&realtimemodel_B.th_ddeg), 0, 0, 3 }
  ,

  { (char_T *)(&realtimemodel_DW.DiscreteTimeIntegrator_DSTATE), 0, 0, 1 },

  { (char_T *)(&realtimemodel_DW.AnalogInput_PWORK), 11, 0, 5 },

  { (char_T *)(&realtimemodel_DW.Average_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&realtimemodel_DW.Average_MODE), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&realtimemodel_P.sens), 24, 0, 1 },

  { (char_T *)(&realtimemodel_P.sIn), 17, 0, 1 },

  { (char_T *)(&realtimemodel_P.AnalogOutput_FinalValue), 0, 0, 9 },

  { (char_T *)(&realtimemodel_P.AnalogInput_Channels[0]), 6, 0, 8 },

  { (char_T *)(&realtimemodel_P.Out_Y0), 0, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] realtimemodel_dt.h */

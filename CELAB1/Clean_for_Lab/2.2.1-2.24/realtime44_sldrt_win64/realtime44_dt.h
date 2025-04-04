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
 * C source code generated on : Fri Apr  4 12:39:23 2025
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
  sizeof(struct_3PxRKnguvZJWZpmBEPjwDC),
  sizeof(struct_w2rpjrheReKyNwtRQGQEfF),
  sizeof(struct_LYXsnuLmZkcUvicgq9G2LH),
  sizeof(struct_xtO7tMu82TeSoV7AA0ueE),
  sizeof(struct_91orgUEmTCcvCW7OEYG4IE),
  sizeof(struct_aZ8HH0GxQ9zbTovc9IB59F),
  sizeof(struct_WOXaLT8EEGpugwsNakDiBC),
  sizeof(struct_fNvLKrmGPjNwFpotE81xaF),
  sizeof(struct_vHPMdAr9HfDgWNbG6U3SfC),
  sizeof(struct_nZqFUEOh71pPhzsMP64FWD),
  sizeof(struct_DqRrFctOcoTwJhkxMXTGZG),
  sizeof(struct_t4jfYKvXkqvqbOrnXV9flF),
  sizeof(struct_8LnTg2HasR61N4e63tMdJ),
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
  "struct_3PxRKnguvZJWZpmBEPjwDC",
  "struct_w2rpjrheReKyNwtRQGQEfF",
  "struct_LYXsnuLmZkcUvicgq9G2LH",
  "struct_xtO7tMu82TeSoV7AA0ueE",
  "struct_91orgUEmTCcvCW7OEYG4IE",
  "struct_aZ8HH0GxQ9zbTovc9IB59F",
  "struct_WOXaLT8EEGpugwsNakDiBC",
  "struct_fNvLKrmGPjNwFpotE81xaF",
  "struct_vHPMdAr9HfDgWNbG6U3SfC",
  "struct_nZqFUEOh71pPhzsMP64FWD",
  "struct_DqRrFctOcoTwJhkxMXTGZG",
  "struct_t4jfYKvXkqvqbOrnXV9flF",
  "struct_8LnTg2HasR61N4e63tMdJ",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&realtime44_B.pulse2deg), 0, 0, 7 },

  { (char_T *)(&realtime44_B.FixPtSwitch), 3, 0, 1 }
  ,

  { (char_T *)(&realtime44_DW.EncoderInput_PWORK), 11, 0, 5 },

  { (char_T *)(&realtime44_DW.Output_DSTATE), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&realtime44_P.sens), 29, 0, 1 },

  { (char_T *)(&realtime44_P.feedback), 24, 0, 1 },

  { (char_T *)(&realtime44_P.sIn), 17, 0, 1 },

  { (char_T *)(&realtime44_P.filt), 19, 0, 1 },

  { (char_T *)(&realtime44_P.deg2rad), 0, 0, 12 },

  { (char_T *)(&realtime44_P.EncoderInput_Channels), 6, 0, 8 },

  { (char_T *)(&realtime44_P.WrapToZero_Threshold), 3, 0, 1 },

  { (char_T *)(&realtime44_P.Integrator_IC), 0, 0, 3 },

  { (char_T *)(&realtime44_P.Constant_Value), 3, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  9U,
  rtPTransitions
};

/* [EOF] realtime44_dt.h */

/*
 * realtimemodel_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtimemodel".
 *
 * Model version              : 1.8
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri May 16 13:13:52 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef realtimemodel_types_h_
#define realtimemodel_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_RrN3B6TGuHXuTo2ke8b2GF_
#define DEFINED_TYPEDEF_FOR_struct_RrN3B6TGuHXuTo2ke8b2GF_

typedef struct {
  real_T motor_or_nominal;
  real_T intOn;
  real_T solver_time;
  real_T position;
  real_T step_time;
  real_T simulation_time;
  real_T t0;
  real_T t1;
} struct_RrN3B6TGuHXuTo2ke8b2GF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_vHPMdAr9HfDgWNbG6U3SfC_
#define DEFINED_TYPEDEF_FOR_struct_vHPMdAr9HfDgWNbG6U3SfC_

typedef struct {
  real_T Rs;
} struct_vHPMdAr9HfDgWNbG6U3SfC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nZqFUEOh71pPhzsMP64FWD_
#define DEFINED_TYPEDEF_FOR_struct_nZqFUEOh71pPhzsMP64FWD_

typedef struct {
  real_T ppr;
  real_T pulse2deg;
  real_T pulse2rad;
  real_T deg2pulse;
  real_T rad2pulse;
} struct_nZqFUEOh71pPhzsMP64FWD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DqRrFctOcoTwJhkxMXTGZG_
#define DEFINED_TYPEDEF_FOR_struct_DqRrFctOcoTwJhkxMXTGZG_

typedef struct {
  real_T R;
  real_T V;
  real_T th_deg;
  real_T th;
} struct_DqRrFctOcoTwJhkxMXTGZG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_t4jfYKvXkqvqbOrnXV9flF_
#define DEFINED_TYPEDEF_FOR_struct_t4jfYKvXkqvqbOrnXV9flF_

typedef struct {
  struct_DqRrFctOcoTwJhkxMXTGZG range;
  real_T deg2V;
  real_T rad2V;
  real_T V2deg;
  real_T V2rad;
} struct_t4jfYKvXkqvqbOrnXV9flF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_i7ZlkOl9k9qbhxQhPErSIE_
#define DEFINED_TYPEDEF_FOR_struct_i7ZlkOl9k9qbhxQhPErSIE_

typedef struct {
  real_T var;
} struct_i7ZlkOl9k9qbhxQhPErSIE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nhbocl71hD6FRzHagkwJFB_
#define DEFINED_TYPEDEF_FOR_struct_nhbocl71hD6FRzHagkwJFB_

typedef struct {
  struct_DqRrFctOcoTwJhkxMXTGZG range;
  real_T deg2V;
  real_T rad2V;
  real_T V2deg;
  real_T V2rad;
  struct_i7ZlkOl9k9qbhxQhPErSIE noise;
} struct_nhbocl71hD6FRzHagkwJFB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4jr0aBoeUcVnCi5PWU4anE_
#define DEFINED_TYPEDEF_FOR_struct_4jr0aBoeUcVnCi5PWU4anE_

typedef struct {
  struct_vHPMdAr9HfDgWNbG6U3SfC curr;
  struct_nZqFUEOh71pPhzsMP64FWD enc;
  struct_t4jfYKvXkqvqbOrnXV9flF pot1;
  struct_nhbocl71hD6FRzHagkwJFB pot2;
} struct_4jr0aBoeUcVnCi5PWU4anE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_PgmIS4SOnZBuutpNyb6QwH_
#define DEFINED_TYPEDEF_FOR_struct_PgmIS4SOnZBuutpNyb6QwH_

typedef struct {
  real_T K[4];
  real_T gains[5];
  real_T Nx[4];
  real_T Nu;
  real_T robustK[4];
  real_T robustKi;
} struct_PgmIS4SOnZBuutpNyb6QwH;

#endif

/* Parameters (default storage) */
typedef struct P_realtimemodel_T_ P_realtimemodel_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_realtimemodel_T RT_MODEL_realtimemodel_T;

#endif                                 /* realtimemodel_types_h_ */

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
 * C source code generated on : Fri May 16 13:25:17 2025
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

#ifndef DEFINED_TYPEDEF_FOR_struct_8LnTg2HasR61N4e63tMdJ_
#define DEFINED_TYPEDEF_FOR_struct_8LnTg2HasR61N4e63tMdJ_

typedef struct {
  struct_vHPMdAr9HfDgWNbG6U3SfC curr;
  struct_nZqFUEOh71pPhzsMP64FWD enc;
  struct_t4jfYKvXkqvqbOrnXV9flF pot1;
} struct_8LnTg2HasR61N4e63tMdJ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_RpRKyQmph6vEfxzPyew3r_
#define DEFINED_TYPEDEF_FOR_struct_RpRKyQmph6vEfxzPyew3r_

typedef struct {
  real_T Ki;
  real_T K[2];
  real_T Nx[2];
  real_T Nu;
} struct_RpRKyQmph6vEfxzPyew3r;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_OWdElbvfJfRElaZMHZHwIE_
#define DEFINED_TYPEDEF_FOR_struct_OWdElbvfJfRElaZMHZHwIE_

typedef struct {
  real_T L;
  real_T phi0;
  real_T gamma0[2];
  real_T H0[2];
  real_T J0[4];
} struct_OWdElbvfJfRElaZMHZHwIE;

#endif

/* Parameters (default storage) */
typedef struct P_realtimemodel_T_ P_realtimemodel_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_realtimemodel_T RT_MODEL_realtimemodel_T;

#endif                                 /* realtimemodel_types_h_ */

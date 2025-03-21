/*
 * realtimeModel_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtimeModel".
 *
 * Model version              : 1.2
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Mar 21 13:28:15 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef realtimeModel_types_h_
#define realtimeModel_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_P1VnLP8PQiYhv321vzV45D_
#define DEFINED_TYPEDEF_FOR_struct_P1VnLP8PQiYhv321vzV45D_

typedef struct {
  real_T mag_steps[6];
  real_T length_steps;
  real_T pid;
  real_T step_time;
  real_T step_number;
  real_T step_omega;
  real_T acc_step_time;
  real_T acc_cycles;
  real_T acceleration;
  real_T t_est;
  real_T omega_l[19];
  real_T num_resp;
  real_T resp[11];
  real_T t_resp;
  real_T A[20];
  real_T t_sim;
} struct_P1VnLP8PQiYhv321vzV45D;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_8LnTg2HasR61N4e63tMdJ_
#define DEFINED_TYPEDEF_FOR_struct_8LnTg2HasR61N4e63tMdJ_

typedef struct {
  struct_vHPMdAr9HfDgWNbG6U3SfC curr;
  struct_nZqFUEOh71pPhzsMP64FWD enc;
  struct_t4jfYKvXkqvqbOrnXV9flF pot1;
} struct_8LnTg2HasR61N4e63tMdJ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_w2rpjrheReKyNwtRQGQEfF_
#define DEFINED_TYPEDEF_FOR_struct_w2rpjrheReKyNwtRQGQEfF_

typedef struct {
  real_T omega_c;
  real_T delta;
  real_T num[2];
  real_T den[3];
} struct_w2rpjrheReKyNwtRQGQEfF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_OYB0L6tkYmibNjdB0Biu2E_
#define DEFINED_TYPEDEF_FOR_struct_OYB0L6tkYmibNjdB0Biu2E_

typedef struct {
  real_T omega_ci;
  real_T delta_i;
  real_T num;
  real_T den[3];
} struct_OYB0L6tkYmibNjdB0Biu2E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_5qY1uoShzFQMDeMPZ5vyJ_
#define DEFINED_TYPEDEF_FOR_struct_5qY1uoShzFQMDeMPZ5vyJ_

typedef struct {
  struct_w2rpjrheReKyNwtRQGQEfF butt;
  struct_OYB0L6tkYmibNjdB0Biu2E low;
} struct_5qY1uoShzFQMDeMPZ5vyJ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_tqEcQv8wI4rPb7WqAAnbuH_
#define DEFINED_TYPEDEF_FOR_struct_tqEcQv8wI4rPb7WqAAnbuH_

typedef struct {
  real_T N1;
  real_T eta1;
  real_T N2;
  real_T J72;
  real_T eta2;
  real_T N;
  real_T eta;
  real_T J;
} struct_tqEcQv8wI4rPb7WqAAnbuH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ZTMEIrmHloBmbyeqMeVVnG_
#define DEFINED_TYPEDEF_FOR_struct_ZTMEIrmHloBmbyeqMeVVnG_

typedef struct {
  real_T Kp;
  real_T Ki;
  real_T Kd;
  real_T Tl;
  real_T i_saturation;
} struct_ZTMEIrmHloBmbyeqMeVVnG;

#endif

/* Parameters (default storage) */
typedef struct P_realtimeModel_T_ P_realtimeModel_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_realtimeModel_T RT_MODEL_realtimeModel_T;

#endif                                 /* realtimeModel_types_h_ */

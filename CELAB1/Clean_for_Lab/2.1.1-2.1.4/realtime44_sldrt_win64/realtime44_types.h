/*
 * realtime44_types.h
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

#ifndef realtime44_types_h_
#define realtime44_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_c5vVpuBCuvBcHq3zEoVR5C_
#define DEFINED_TYPEDEF_FOR_struct_c5vVpuBCuvBcHq3zEoVR5C_

typedef struct {
  real_T acc;
  real_T time;
  real_T num;
  real_T ref[12];
} struct_c5vVpuBCuvBcHq3zEoVR5C;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qNekjJ1RglMGc2fPYYDfGB_
#define DEFINED_TYPEDEF_FOR_struct_qNekjJ1RglMGc2fPYYDfGB_

typedef struct {
  real_T mag;
  real_T time;
  real_T num;
  real_T ref;
} struct_qNekjJ1RglMGc2fPYYDfGB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_M3GTBhBY6Ysk6vVyrpXTEH_
#define DEFINED_TYPEDEF_FOR_struct_M3GTBhBY6Ysk6vVyrpXTEH_

typedef struct {
  real_T program;
  real_T time;
} struct_M3GTBhBY6Ysk6vVyrpXTEH;

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

#ifndef DEFINED_TYPEDEF_FOR_struct_i3LpJ6wE5WSH5fTRRwU1pH_
#define DEFINED_TYPEDEF_FOR_struct_i3LpJ6wE5WSH5fTRRwU1pH_

typedef struct {
  real_T Kp;
  real_T Ki;
  real_T Kd;
  real_T Tl;
  real_T t_s5;
  real_T Kw;
} struct_i3LpJ6wE5WSH5fTRRwU1pH;

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

/* Parameters (default storage) */
typedef struct P_realtime44_T_ P_realtime44_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_realtime44_T RT_MODEL_realtime44_T;

#endif                                 /* realtime44_types_h_ */

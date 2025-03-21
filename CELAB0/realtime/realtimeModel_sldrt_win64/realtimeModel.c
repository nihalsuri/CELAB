/*
 * realtimeModel.c
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

#include "realtimeModel.h"
#include "rtwtypes.h"
#include "realtimeModel_private.h"
#include <string.h>
#include "realtimeModel_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCIe-6321", 4294967295U, 7, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_realtimeModel_T realtimeModel_B;

/* Continuous states */
X_realtimeModel_T realtimeModel_X;

/* Disabled State Vector */
XDis_realtimeModel_T realtimeModel_XDis;

/* Block states (default storage) */
DW_realtimeModel_T realtimeModel_DW;

/* Real-time model */
static RT_MODEL_realtimeModel_T realtimeModel_M_;
RT_MODEL_realtimeModel_T *const realtimeModel_M = &realtimeModel_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (realtimeModel_M->Timing.TaskCounters.TID[2])++;
  if ((realtimeModel_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [1.0s, 0.0s] */
    realtimeModel_M->Timing.TaskCounters.TID[2] = 0;
  }

  realtimeModel_M->Timing.sampleHits[2] =
    (realtimeModel_M->Timing.TaskCounters.TID[2] == 0) ? 1 : 0;
  (realtimeModel_M->Timing.TaskCounters.TID[3])++;
  if ((realtimeModel_M->Timing.TaskCounters.TID[3]) > 2999) {/* Sample time: [3.0s, 0.0s] */
    realtimeModel_M->Timing.TaskCounters.TID[3] = 0;
  }

  realtimeModel_M->Timing.sampleHits[3] =
    (realtimeModel_M->Timing.TaskCounters.TID[3] == 0) ? 1 : 0;
  (realtimeModel_M->Timing.TaskCounters.TID[4])++;
  if ((realtimeModel_M->Timing.TaskCounters.TID[4]) > 4999) {/* Sample time: [5.0s, 0.0s] */
    realtimeModel_M->Timing.TaskCounters.TID[4] = 0;
  }

  realtimeModel_M->Timing.sampleHits[4] =
    (realtimeModel_M->Timing.TaskCounters.TID[4] == 0) ? 1 : 0;
}

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 11;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  realtimeModel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  realtimeModel_output();
  realtimeModel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  realtimeModel_output();
  realtimeModel_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  realtimeModel_output();
  realtimeModel_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  realtimeModel_output();
  realtimeModel_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  realtimeModel_output();
  realtimeModel_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void realtimeModel_output(void)
{
  real_T rtb_Gain1_c;
  real_T rtb_Output;
  real_T rtb_Sum;
  real_T rtb_Sum_tmp;
  uint8_T rtb_FixPtSum1;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(realtimeModel_M)) {
    /* set solver stop time */
    if (!(realtimeModel_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&realtimeModel_M->solverInfo,
                            ((realtimeModel_M->Timing.clockTickH0 + 1) *
        realtimeModel_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&realtimeModel_M->solverInfo,
                            ((realtimeModel_M->Timing.clockTick0 + 1) *
        realtimeModel_M->Timing.stepSize0 + realtimeModel_M->Timing.clockTickH0 *
        realtimeModel_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(realtimeModel_M)) {
    realtimeModel_M->Timing.t[0] = rtsiGetT(&realtimeModel_M->solverInfo);
  }

  /* TransferFcn: '<S1>/Butterworth Derivative' incorporates:
   *  TransferFcn: '<S1>/Butterworth Derivative1'
   */
  rtb_Gain1_c = realtimeModel_P.filt.butt.num[0] /
    realtimeModel_P.filt.butt.den[0];
  rtb_Sum = rtb_Gain1_c * realtimeModel_X.ButterworthDerivative_CSTATE[0];
  rtb_Sum_tmp = realtimeModel_P.filt.butt.num[1] /
    realtimeModel_P.filt.butt.den[0];
  rtb_Sum += rtb_Sum_tmp * realtimeModel_X.ButterworthDerivative_CSTATE[1];

  /* Gain: '<S1>/Gearbox' incorporates:
   *  Gain: '<S1>/degs2rpm'
   */
  realtimeModel_B.omega_mrpm = realtimeModel_P.degs2rpm * rtb_Sum *
    realtimeModel_P.gbox.N;
  tmp = (rtmIsMajorTimeStep(realtimeModel_M) &&
         realtimeModel_M->Timing.TaskCounters.TID[1] == 0);
  if (tmp) {
  }

  /* TransferFcn: '<S1>/Butterworth Derivative1' */
  realtimeModel_B.am_motorrpms = 0.0;
  realtimeModel_B.am_motorrpms += rtb_Gain1_c *
    realtimeModel_X.ButterworthDerivative1_CSTATE[0];
  realtimeModel_B.am_motorrpms += rtb_Sum_tmp *
    realtimeModel_X.ButterworthDerivative1_CSTATE[1];
  if (tmp) {
  }

  /* TransferFcn: '<S1>/Low-Pass i_a' */
  realtimeModel_B.i_aAfiltered = 0.0;
  realtimeModel_B.i_aAfiltered += 0.0 * realtimeModel_X.LowPassi_a_CSTATE[0];
  realtimeModel_B.i_aAfiltered += realtimeModel_P.filt.low.num /
    realtimeModel_P.filt.low.den[0] * realtimeModel_X.LowPassi_a_CSTATE[1];
  if (tmp) {
  }

  /* S-Function (sldrtai): '<S6>/Analog Input' */
  /* S-Function Block: <S6>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) realtimeModel_P.AnalogInput_RangeMode;
    parm.rangeidx = realtimeModel_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                   realtimeModel_P.AnalogInput_Channels, &realtimeModel_B.VaVb[0],
                   &parm);
  }

  /* S-Function (sldrtei): '<S6>/Encoder Input' */
  /* S-Function Block: <S6>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtimeModel_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &realtimeModel_P.EncoderInput_Channels, &rtb_Sum, &parm);
  }

  /* Gain: '<S1>/1//R_shunt' incorporates:
   *  Sum: '<Root>/Sum'
   */
  realtimeModel_B.i_a = 1.0 / realtimeModel_P.sens.curr.Rs *
    (realtimeModel_B.VaVb[0] - realtimeModel_B.VaVb[1]);
  if (tmp) {
  }

  /* Gain: '<Root>/pulse2deg' */
  realtimeModel_B.thi_measdeg = realtimeModel_P.sens.enc.pulse2deg * rtb_Sum;
  if (tmp) {
  }

  /* Gain: '<S7>/Gain1' incorporates:
   *  Integrator: '<Root>/Integrator2'
   *  Sum: '<Root>/Sum1'
   */
  rtb_Gain1_c = (realtimeModel_X.Integrator2_CSTATE -
                 realtimeModel_B.thi_measdeg) * realtimeModel_P.Gain1_Gain;

  /* Integrator: '<S2>/Integrator' */
  rtb_Sum = realtimeModel_X.Integrator_CSTATE;

  /* Gain: '<S2>/Gain' */
  realtimeModel_B.Gain = realtimeModel_P.PID.Kd * rtb_Gain1_c;

  /* Saturate: '<S2>/Saturation1' */
  if (rtb_Sum > realtimeModel_P.PID.i_saturation) {
    rtb_Sum = realtimeModel_P.PID.i_saturation;
  } else if (rtb_Sum < -realtimeModel_P.PID.i_saturation) {
    rtb_Sum = -realtimeModel_P.PID.i_saturation;
  }

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Saturate: '<S2>/Saturation1'
   *  TransferFcn: '<S2>/Transfer Fcn'
   */
  rtb_Sum = (realtimeModel_P.PID.Kp * rtb_Gain1_c + rtb_Sum) +
    (realtimeModel_P.TransferFcn_C * realtimeModel_X.TransferFcn_CSTATE +
     realtimeModel_P.TransferFcn_D * realtimeModel_B.Gain);

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Sum > realtimeModel_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    realtimeModel_B.Saturation = realtimeModel_P.Saturation_UpperSat;
  } else if (rtb_Sum < realtimeModel_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    realtimeModel_B.Saturation = realtimeModel_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    realtimeModel_B.Saturation = rtb_Sum;
  }

  /* End of Saturate: '<S2>/Saturation' */
  if (tmp) {
  }

  /* Integrator: '<Root>/Integrator1' */
  realtimeModel_B.degs = realtimeModel_X.Integrator1_CSTATE;

  /* Gain: '<S2>/Gain2' */
  realtimeModel_B.Gain2 = realtimeModel_P.PID.Ki * rtb_Gain1_c;
  tmp = (rtmIsMajorTimeStep(realtimeModel_M) &&
         realtimeModel_M->Timing.TaskCounters.TID[2] == 0);
  if (tmp) {
    /* Sum: '<S15>/FixPt Sum1' incorporates:
     *  Constant: '<S15>/FixPt Constant'
     *  UnitDelay: '<S14>/Output'
     */
    rtb_FixPtSum1 = (uint8_T)(realtimeModel_DW.Output_DSTATE +
      realtimeModel_P.FixPtConstant_Value);

    /* Switch: '<S16>/FixPt Switch' */
    if (rtb_FixPtSum1 > realtimeModel_P.WrapToZero_Threshold) {
      /* Switch: '<S16>/FixPt Switch' incorporates:
       *  Constant: '<S16>/Constant'
       */
      realtimeModel_B.FixPtSwitch = realtimeModel_P.Constant_Value_b;
    } else {
      /* Switch: '<S16>/FixPt Switch' */
      realtimeModel_B.FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S16>/FixPt Switch' */

    /* MultiPortSwitch: '<S5>/Output' incorporates:
     *  Constant: '<S5>/Vector'
     *  UnitDelay: '<S14>/Output'
     */
    rtb_Output = realtimeModel_P.sIn.A[realtimeModel_DW.Output_DSTATE];
  }

  /* S-Function (sldrtao): '<S6>/Analog Output' */
  /* S-Function Block: <S6>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtimeModel_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtimeModel_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtimeModel_P.AnalogOutput_Channels, ((real_T*)
        (&realtimeModel_B.Saturation)), &parm);
    }
  }

  if (tmp) {
    /* Gain: '<Root>/rpm2degs1' */
    realtimeModel_B.degs2 = realtimeModel_P.rpm2degs * rtb_Output;
  }

  if (rtmIsMajorTimeStep(realtimeModel_M) &&
      realtimeModel_M->Timing.TaskCounters.TID[4] == 0) {
    /* Sum: '<S9>/FixPt Sum1' incorporates:
     *  Constant: '<S9>/FixPt Constant'
     *  UnitDelay: '<S8>/Output'
     */
    rtb_FixPtSum1 = (uint8_T)(realtimeModel_DW.Output_DSTATE_e +
      realtimeModel_P.FixPtConstant_Value_a);

    /* Switch: '<S10>/FixPt Switch' */
    if (rtb_FixPtSum1 > realtimeModel_P.WrapToZero_Threshold_n) {
      /* Switch: '<S10>/FixPt Switch' incorporates:
       *  Constant: '<S10>/Constant'
       */
      realtimeModel_B.FixPtSwitch_i = realtimeModel_P.Constant_Value;
    } else {
      /* Switch: '<S10>/FixPt Switch' */
      realtimeModel_B.FixPtSwitch_i = rtb_FixPtSum1;
    }

    /* End of Switch: '<S10>/FixPt Switch' */

    /* Gain: '<Root>/rpm2degs' incorporates:
     *  Constant: '<S3>/Vector'
     *  MultiPortSwitch: '<S3>/Output'
     *  UnitDelay: '<S8>/Output'
     */
    realtimeModel_B.omega_refdegs = realtimeModel_P.rpm2degs *
      realtimeModel_P.sIn.omega_l[realtimeModel_DW.Output_DSTATE_e];
  }
}

/* Model update function */
void realtimeModel_update(void)
{
  if (rtmIsMajorTimeStep(realtimeModel_M) &&
      realtimeModel_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S14>/Output' */
    realtimeModel_DW.Output_DSTATE = realtimeModel_B.FixPtSwitch;
  }

  if (rtmIsMajorTimeStep(realtimeModel_M) &&
      realtimeModel_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update for UnitDelay: '<S8>/Output' */
    realtimeModel_DW.Output_DSTATE_e = realtimeModel_B.FixPtSwitch_i;
  }

  if (rtmIsMajorTimeStep(realtimeModel_M)) {
    rt_ertODEUpdateContinuousStates(&realtimeModel_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++realtimeModel_M->Timing.clockTick0)) {
    ++realtimeModel_M->Timing.clockTickH0;
  }

  realtimeModel_M->Timing.t[0] = rtsiGetSolverStopTime
    (&realtimeModel_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++realtimeModel_M->Timing.clockTick1)) {
      ++realtimeModel_M->Timing.clockTickH1;
    }

    realtimeModel_M->Timing.t[1] = realtimeModel_M->Timing.clockTick1 *
      realtimeModel_M->Timing.stepSize1 + realtimeModel_M->Timing.clockTickH1 *
      realtimeModel_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(realtimeModel_M) &&
      realtimeModel_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++realtimeModel_M->Timing.clockTick2)) {
      ++realtimeModel_M->Timing.clockTickH2;
    }

    realtimeModel_M->Timing.t[2] = realtimeModel_M->Timing.clockTick2 *
      realtimeModel_M->Timing.stepSize2 + realtimeModel_M->Timing.clockTickH2 *
      realtimeModel_M->Timing.stepSize2 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(realtimeModel_M) &&
      realtimeModel_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [3.0s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick3"
     * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick3 and the high bits
     * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++realtimeModel_M->Timing.clockTick3)) {
      ++realtimeModel_M->Timing.clockTickH3;
    }

    realtimeModel_M->Timing.t[3] = realtimeModel_M->Timing.clockTick3 *
      realtimeModel_M->Timing.stepSize3 + realtimeModel_M->Timing.clockTickH3 *
      realtimeModel_M->Timing.stepSize3 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(realtimeModel_M) &&
      realtimeModel_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update absolute timer for sample time: [5.0s, 0.0s] */
    /* The "clockTick4" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick4"
     * and "Timing.stepSize4". Size of "clockTick4" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick4 and the high bits
     * Timing.clockTickH4. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++realtimeModel_M->Timing.clockTick4)) {
      ++realtimeModel_M->Timing.clockTickH4;
    }

    realtimeModel_M->Timing.t[4] = realtimeModel_M->Timing.clockTick4 *
      realtimeModel_M->Timing.stepSize4 + realtimeModel_M->Timing.clockTickH4 *
      realtimeModel_M->Timing.stepSize4 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void realtimeModel_derivatives(void)
{
  XDot_realtimeModel_T *_rtXdot;
  real_T ButterworthDerivative_CSTATE_tmp;
  real_T ButterworthDerivative_CSTATE_tmp_0;
  _rtXdot = ((XDot_realtimeModel_T *) realtimeModel_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/Butterworth Derivative' incorporates:
   *  TransferFcn: '<S1>/Butterworth Derivative1'
   */
  ButterworthDerivative_CSTATE_tmp = -realtimeModel_P.filt.butt.den[1] /
    realtimeModel_P.filt.butt.den[0];
  _rtXdot->ButterworthDerivative_CSTATE[0] = ButterworthDerivative_CSTATE_tmp *
    realtimeModel_X.ButterworthDerivative_CSTATE[0];
  ButterworthDerivative_CSTATE_tmp_0 = -realtimeModel_P.filt.butt.den[2] /
    realtimeModel_P.filt.butt.den[0];
  _rtXdot->ButterworthDerivative_CSTATE[0] += ButterworthDerivative_CSTATE_tmp_0
    * realtimeModel_X.ButterworthDerivative_CSTATE[1];
  _rtXdot->ButterworthDerivative_CSTATE[1] =
    realtimeModel_X.ButterworthDerivative_CSTATE[0];
  _rtXdot->ButterworthDerivative_CSTATE[0] += realtimeModel_B.thi_measdeg;

  /* Derivatives for TransferFcn: '<S1>/Butterworth Derivative1' */
  _rtXdot->ButterworthDerivative1_CSTATE[0] = ButterworthDerivative_CSTATE_tmp *
    realtimeModel_X.ButterworthDerivative1_CSTATE[0];
  _rtXdot->ButterworthDerivative1_CSTATE[0] +=
    ButterworthDerivative_CSTATE_tmp_0 *
    realtimeModel_X.ButterworthDerivative1_CSTATE[1];
  _rtXdot->ButterworthDerivative1_CSTATE[1] =
    realtimeModel_X.ButterworthDerivative1_CSTATE[0];
  _rtXdot->ButterworthDerivative1_CSTATE[0] += realtimeModel_B.omega_mrpm;

  /* Derivatives for TransferFcn: '<S1>/Low-Pass i_a' */
  _rtXdot->LowPassi_a_CSTATE[0] = -realtimeModel_P.filt.low.den[1] /
    realtimeModel_P.filt.low.den[0] * realtimeModel_X.LowPassi_a_CSTATE[0];
  _rtXdot->LowPassi_a_CSTATE[0] += -realtimeModel_P.filt.low.den[2] /
    realtimeModel_P.filt.low.den[0] * realtimeModel_X.LowPassi_a_CSTATE[1];
  _rtXdot->LowPassi_a_CSTATE[1] = realtimeModel_X.LowPassi_a_CSTATE[0];
  _rtXdot->LowPassi_a_CSTATE[0] += realtimeModel_B.i_a;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = realtimeModel_B.degs;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = realtimeModel_B.Gain2;

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = realtimeModel_P.TransferFcn_A *
    realtimeModel_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += realtimeModel_B.Gain;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = realtimeModel_B.degs2;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = realtimeModel_B.omega_refdegs;
}

/* Model initialize function */
void realtimeModel_initialize(void)
{
  /* Start for S-Function (sldrtao): '<S6>/Analog Output' */

  /* S-Function Block: <S6>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtimeModel_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtimeModel_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtimeModel_P.AnalogOutput_Channels,
                     &realtimeModel_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for TransferFcn: '<S1>/Butterworth Derivative' */
  realtimeModel_X.ButterworthDerivative_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Butterworth Derivative1' */
  realtimeModel_X.ButterworthDerivative1_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Low-Pass i_a' */
  realtimeModel_X.LowPassi_a_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Butterworth Derivative' */
  realtimeModel_X.ButterworthDerivative_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Butterworth Derivative1' */
  realtimeModel_X.ButterworthDerivative1_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Low-Pass i_a' */
  realtimeModel_X.LowPassi_a_CSTATE[1] = 0.0;

  /* InitializeConditions for S-Function (sldrtei): '<S6>/Encoder Input' */

  /* S-Function Block: <S6>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtimeModel_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &realtimeModel_P.EncoderInput_Channels, NULL, &parm);
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  realtimeModel_X.Integrator2_CSTATE = realtimeModel_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  realtimeModel_X.Integrator_CSTATE = realtimeModel_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn' */
  realtimeModel_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  realtimeModel_X.Integrator1_CSTATE = realtimeModel_P.Integrator1_IC;

  /* InitializeConditions for UnitDelay: '<S14>/Output' */
  realtimeModel_DW.Output_DSTATE = realtimeModel_P.Output_InitialCondition;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  realtimeModel_X.Integrator_CSTATE_j = realtimeModel_P.Integrator_IC_c;

  /* InitializeConditions for UnitDelay: '<S8>/Output' */
  realtimeModel_DW.Output_DSTATE_e = realtimeModel_P.Output_InitialCondition_i;
}

/* Model terminate function */
void realtimeModel_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S6>/Analog Output' */

  /* S-Function Block: <S6>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtimeModel_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtimeModel_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtimeModel_P.AnalogOutput_Channels,
                     &realtimeModel_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  realtimeModel_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  realtimeModel_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  realtimeModel_initialize();
}

void MdlTerminate(void)
{
  realtimeModel_terminate();
}

/* Registration function */
RT_MODEL_realtimeModel_T *realtimeModel(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)realtimeModel_M, 0,
                sizeof(RT_MODEL_realtimeModel_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&realtimeModel_M->solverInfo,
                          &realtimeModel_M->Timing.simTimeStep);
    rtsiSetTPtr(&realtimeModel_M->solverInfo, &rtmGetTPtr(realtimeModel_M));
    rtsiSetStepSizePtr(&realtimeModel_M->solverInfo,
                       &realtimeModel_M->Timing.stepSize0);
    rtsiSetdXPtr(&realtimeModel_M->solverInfo, &realtimeModel_M->derivs);
    rtsiSetContStatesPtr(&realtimeModel_M->solverInfo, (real_T **)
                         &realtimeModel_M->contStates);
    rtsiSetNumContStatesPtr(&realtimeModel_M->solverInfo,
      &realtimeModel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&realtimeModel_M->solverInfo,
      &realtimeModel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&realtimeModel_M->solverInfo,
      &realtimeModel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&realtimeModel_M->solverInfo,
      &realtimeModel_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&realtimeModel_M->solverInfo, (boolean_T**)
      &realtimeModel_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&realtimeModel_M->solverInfo, (&rtmGetErrorStatus
      (realtimeModel_M)));
    rtsiSetRTModelPtr(&realtimeModel_M->solverInfo, realtimeModel_M);
  }

  rtsiSetSimTimeStep(&realtimeModel_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&realtimeModel_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&realtimeModel_M->solverInfo, false);
  realtimeModel_M->intgData.y = realtimeModel_M->odeY;
  realtimeModel_M->intgData.f[0] = realtimeModel_M->odeF[0];
  realtimeModel_M->intgData.f[1] = realtimeModel_M->odeF[1];
  realtimeModel_M->intgData.f[2] = realtimeModel_M->odeF[2];
  realtimeModel_M->intgData.f[3] = realtimeModel_M->odeF[3];
  realtimeModel_M->intgData.f[4] = realtimeModel_M->odeF[4];
  realtimeModel_M->intgData.f[5] = realtimeModel_M->odeF[5];
  realtimeModel_M->contStates = ((real_T *) &realtimeModel_X);
  realtimeModel_M->contStateDisabled = ((boolean_T *) &realtimeModel_XDis);
  realtimeModel_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&realtimeModel_M->solverInfo, (void *)
                    &realtimeModel_M->intgData);
  rtsiSetSolverName(&realtimeModel_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = realtimeModel_M->Timing.sampleTimeTaskIDArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlTsMap[i] = i;
    }

    realtimeModel_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    realtimeModel_M->Timing.sampleTimes =
      (&realtimeModel_M->Timing.sampleTimesArray[0]);
    realtimeModel_M->Timing.offsetTimes =
      (&realtimeModel_M->Timing.offsetTimesArray[0]);

    /* task periods */
    realtimeModel_M->Timing.sampleTimes[0] = (0.0);
    realtimeModel_M->Timing.sampleTimes[1] = (0.001);
    realtimeModel_M->Timing.sampleTimes[2] = (1.0);
    realtimeModel_M->Timing.sampleTimes[3] = (3.0);
    realtimeModel_M->Timing.sampleTimes[4] = (5.0);

    /* task offsets */
    realtimeModel_M->Timing.offsetTimes[0] = (0.0);
    realtimeModel_M->Timing.offsetTimes[1] = (0.0);
    realtimeModel_M->Timing.offsetTimes[2] = (0.0);
    realtimeModel_M->Timing.offsetTimes[3] = (0.0);
    realtimeModel_M->Timing.offsetTimes[4] = (0.0);
  }

  rtmSetTPtr(realtimeModel_M, &realtimeModel_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = realtimeModel_M->Timing.sampleHitArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlSampleHits[i] = 1;
    }

    realtimeModel_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(realtimeModel_M, 20.0);
  realtimeModel_M->Timing.stepSize0 = 0.001;
  realtimeModel_M->Timing.stepSize1 = 0.001;
  realtimeModel_M->Timing.stepSize2 = 1.0;
  realtimeModel_M->Timing.stepSize3 = 3.0;
  realtimeModel_M->Timing.stepSize4 = 5.0;

  /* External mode info */
  realtimeModel_M->Sizes.checksums[0] = (2301908632U);
  realtimeModel_M->Sizes.checksums[1] = (1023167600U);
  realtimeModel_M->Sizes.checksums[2] = (1057146191U);
  realtimeModel_M->Sizes.checksums[3] = (2836019777U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    realtimeModel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(realtimeModel_M->extModeInfo,
      &realtimeModel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(realtimeModel_M->extModeInfo,
                        realtimeModel_M->Sizes.checksums);
    rteiSetTPtr(realtimeModel_M->extModeInfo, rtmGetTPtr(realtimeModel_M));
  }

  realtimeModel_M->solverInfoPtr = (&realtimeModel_M->solverInfo);
  realtimeModel_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&realtimeModel_M->solverInfo, 0.001);
  rtsiSetSolverMode(&realtimeModel_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  realtimeModel_M->blockIO = ((void *) &realtimeModel_B);
  (void) memset(((void *) &realtimeModel_B), 0,
                sizeof(B_realtimeModel_T));

  /* parameters */
  realtimeModel_M->defaultParam = ((real_T *)&realtimeModel_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &realtimeModel_X;
    realtimeModel_M->contStates = (x);
    (void) memset((void *)&realtimeModel_X, 0,
                  sizeof(X_realtimeModel_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &realtimeModel_XDis;
    realtimeModel_M->contStateDisabled = (xdis);
    (void) memset((void *)&realtimeModel_XDis, 0,
                  sizeof(XDis_realtimeModel_T));
  }

  /* states (dwork) */
  realtimeModel_M->dwork = ((void *) &realtimeModel_DW);
  (void) memset((void *)&realtimeModel_DW, 0,
                sizeof(DW_realtimeModel_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    realtimeModel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 34;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  realtimeModel_M->Sizes.numContStates = (11);/* Number of continuous states */
  realtimeModel_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  realtimeModel_M->Sizes.numY = (0);   /* Number of model outputs */
  realtimeModel_M->Sizes.numU = (0);   /* Number of model inputs */
  realtimeModel_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  realtimeModel_M->Sizes.numSampTimes = (5);/* Number of sample times */
  realtimeModel_M->Sizes.numBlocks = (48);/* Number of blocks */
  realtimeModel_M->Sizes.numBlockIO = (14);/* Number of block outputs */
  realtimeModel_M->Sizes.numBlockPrms = (42);/* Sum of parameter "widths" */
  return realtimeModel_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

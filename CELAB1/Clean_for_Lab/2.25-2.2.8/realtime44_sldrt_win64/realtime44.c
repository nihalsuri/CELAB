/*
 * realtime44.c
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

#include "realtime44.h"
#include "rtwtypes.h"
#include <math.h>
#include "realtime44_private.h"
#include <string.h>
#include "realtime44_dt.h"

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
B_realtime44_T realtime44_B;

/* Continuous states */
X_realtime44_T realtime44_X;

/* Disabled State Vector */
XDis_realtime44_T realtime44_XDis;

/* Block states (default storage) */
DW_realtime44_T realtime44_DW;

/* Real-time model */
static RT_MODEL_realtime44_T realtime44_M_;
RT_MODEL_realtime44_T *const realtime44_M = &realtime44_M_;

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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  realtime44_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  realtime44_output();
  realtime44_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  realtime44_output();
  realtime44_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  realtime44_output();
  realtime44_derivatives();

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
  realtime44_output();
  realtime44_derivatives();

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
  realtime44_output();
  realtime44_derivatives();

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
void realtime44_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[2];
  real_T rtb_Saturation;
  real_T rtb_deg2rad2;
  real_T rtb_degs2rpm;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(realtime44_M)) {
    /* set solver stop time */
    if (!(realtime44_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&realtime44_M->solverInfo,
                            ((realtime44_M->Timing.clockTickH0 + 1) *
        realtime44_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&realtime44_M->solverInfo,
                            ((realtime44_M->Timing.clockTick0 + 1) *
        realtime44_M->Timing.stepSize0 + realtime44_M->Timing.clockTickH0 *
        realtime44_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(realtime44_M)) {
    realtime44_M->Timing.t[0] = rtsiGetT(&realtime44_M->solverInfo);
  }

  /* S-Function (sldrtei): '<S3>/Encoder Input' */
  /* S-Function Block: <S3>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtime44_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &realtime44_P.EncoderInput_Channels, &rtb_deg2rad2, &parm);
  }

  tmp = rtmIsMajorTimeStep(realtime44_M);
  if (tmp) {
    /* S-Function (sldrtai): '<S3>/Analog Input' */
    /* S-Function Block: <S3>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtime44_P.AnalogInput_RangeMode;
      parm.rangeidx = realtime44_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     realtime44_P.AnalogInput_Channels, &rtb_AnalogInput[0],
                     &parm);
    }
  }

  /* Gain: '<Root>/Gain1' */
  realtime44_B.thi_ldeg = realtime44_P.sens.enc.pulse2deg * rtb_deg2rad2;

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Step: '<Root>/Step'
   */
  if ((int32_T)realtime44_P.sIn.program == 1) {
    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Sin: '<Root>/Sine Wave'
     */
    realtime44_B.MultiportSwitch = sin(realtime44_P.sIn.Freq *
      realtime44_M->Timing.t[0] + realtime44_P.SineWave_Phase) *
      realtime44_P.sIn.Amp + realtime44_P.SineWave_Bias;
  } else if (realtime44_M->Timing.t[0] < realtime44_P.Step_Time) {
    /* Step: '<Root>/Step' incorporates:
     *  MultiPortSwitch: '<Root>/Multiport Switch'
     */
    realtime44_B.MultiportSwitch = realtime44_P.Step_Y0;
  } else {
    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Step: '<Root>/Step'
     */
    realtime44_B.MultiportSwitch = realtime44_P.sIn.Amp;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */
  if (tmp) {
  }

  /* TransferFcn: '<S1>/High-pass filter (real derivative)' */
  rtb_deg2rad2 = realtime44_P.filt.high.num[0] / realtime44_P.filt.high.den[0] *
    realtime44_X.Highpassfilterrealderivative_CSTATE[0];

  /* Gain: '<S1>/degs2rpm' incorporates:
   *  TransferFcn: '<S1>/High-pass filter (real derivative)'
   */
  rtb_degs2rpm = (realtime44_P.filt.high.num[1] / realtime44_P.filt.high.den[0] *
                  realtime44_X.Highpassfilterrealderivative_CSTATE[1] +
                  rtb_deg2rad2) * realtime44_P.degs2rpm;

  /* Gain: '<S2>/deg2rad2' */
  rtb_deg2rad2 = realtime44_P.deg2rad * realtime44_B.thi_ldeg;

  /* TransferFcn: '<S2>/Transfer Fcn' */
  rtb_Saturation = realtime44_P.TransferFcn_C[0] *
    realtime44_X.TransferFcn_CSTATE[0];

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/rpm2rads'
   *  SignalConversion generated from: '<S2>/Gain'
   *  TransferFcn: '<S2>/Transfer Fcn'
   */
  rtb_Saturation = ((realtime44_P.TransferFcn_C[1] *
                     realtime44_X.TransferFcn_CSTATE[1] + rtb_Saturation) +
                    realtime44_P.TransferFcn_C[2] *
                    realtime44_X.TransferFcn_CSTATE[2]) - (realtime44_P.rpm2rads
    * rtb_degs2rpm * realtime44_P.Gain_Gain[1] + realtime44_P.Gain_Gain[0] *
    rtb_deg2rad2);

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Saturation > realtime44_P.Saturation_UpperSat) {
    rtb_Saturation = realtime44_P.Saturation_UpperSat;
  } else if (rtb_Saturation < realtime44_P.Saturation_LowerSat) {
    rtb_Saturation = realtime44_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Sum: '<S2>/Sum1' incorporates:
   *  Gain: '<S2>/deg2rad'
   */
  realtime44_B.Sum1 = realtime44_P.deg2rad * realtime44_B.MultiportSwitch -
    rtb_deg2rad2;

  /* S-Function (sldrtao): '<S3>/Analog Output' */
  /* S-Function Block: <S3>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtime44_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtime44_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtime44_P.AnalogOutput_Channels, ((real_T*)
        (&rtb_Saturation)), &parm);
    }
  }
}

/* Model update function */
void realtime44_update(void)
{
  if (rtmIsMajorTimeStep(realtime44_M)) {
    rt_ertODEUpdateContinuousStates(&realtime44_M->solverInfo);
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
  if (!(++realtime44_M->Timing.clockTick0)) {
    ++realtime44_M->Timing.clockTickH0;
  }

  realtime44_M->Timing.t[0] = rtsiGetSolverStopTime(&realtime44_M->solverInfo);

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
    if (!(++realtime44_M->Timing.clockTick1)) {
      ++realtime44_M->Timing.clockTickH1;
    }

    realtime44_M->Timing.t[1] = realtime44_M->Timing.clockTick1 *
      realtime44_M->Timing.stepSize1 + realtime44_M->Timing.clockTickH1 *
      realtime44_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void realtime44_derivatives(void)
{
  XDot_realtime44_T *_rtXdot;
  _rtXdot = ((XDot_realtime44_T *) realtime44_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/High-pass filter (real derivative)' */
  _rtXdot->Highpassfilterrealderivative_CSTATE[0] = -realtime44_P.filt.high.den
    [1] / realtime44_P.filt.high.den[0] *
    realtime44_X.Highpassfilterrealderivative_CSTATE[0];
  _rtXdot->Highpassfilterrealderivative_CSTATE[0] +=
    -realtime44_P.filt.high.den[2] / realtime44_P.filt.high.den[0] *
    realtime44_X.Highpassfilterrealderivative_CSTATE[1];
  _rtXdot->Highpassfilterrealderivative_CSTATE[1] =
    realtime44_X.Highpassfilterrealderivative_CSTATE[0];
  _rtXdot->Highpassfilterrealderivative_CSTATE[0] += realtime44_B.thi_ldeg;

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = realtime44_P.TransferFcn_A[0] *
    realtime44_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += realtime44_P.TransferFcn_A[1] *
    realtime44_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[0] += realtime44_P.TransferFcn_A[2] *
    realtime44_X.TransferFcn_CSTATE[2];
  _rtXdot->TransferFcn_CSTATE[1] = realtime44_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[2] = realtime44_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[0] += realtime44_B.Sum1;
}

/* Model initialize function */
void realtime44_initialize(void)
{
  /* Start for S-Function (sldrtao): '<S3>/Analog Output' */

  /* S-Function Block: <S3>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtime44_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtime44_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtime44_P.AnalogOutput_Channels,
                     &realtime44_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<S3>/Encoder Input' */

  /* S-Function Block: <S3>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtime44_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &realtime44_P.EncoderInput_Channels, NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<S1>/High-pass filter (real derivative)' */
  realtime44_X.Highpassfilterrealderivative_CSTATE[0] = 0.0;
  realtime44_X.Highpassfilterrealderivative_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn' */
  realtime44_X.TransferFcn_CSTATE[0] = 0.0;
  realtime44_X.TransferFcn_CSTATE[1] = 0.0;
  realtime44_X.TransferFcn_CSTATE[2] = 0.0;
}

/* Model terminate function */
void realtime44_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S3>/Analog Output' */

  /* S-Function Block: <S3>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtime44_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtime44_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtime44_P.AnalogOutput_Channels,
                     &realtime44_P.AnalogOutput_FinalValue, &parm);
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
  realtime44_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  realtime44_update();
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
  realtime44_initialize();
}

void MdlTerminate(void)
{
  realtime44_terminate();
}

/* Registration function */
RT_MODEL_realtime44_T *realtime44(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)realtime44_M, 0,
                sizeof(RT_MODEL_realtime44_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&realtime44_M->solverInfo,
                          &realtime44_M->Timing.simTimeStep);
    rtsiSetTPtr(&realtime44_M->solverInfo, &rtmGetTPtr(realtime44_M));
    rtsiSetStepSizePtr(&realtime44_M->solverInfo,
                       &realtime44_M->Timing.stepSize0);
    rtsiSetdXPtr(&realtime44_M->solverInfo, &realtime44_M->derivs);
    rtsiSetContStatesPtr(&realtime44_M->solverInfo, (real_T **)
                         &realtime44_M->contStates);
    rtsiSetNumContStatesPtr(&realtime44_M->solverInfo,
      &realtime44_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&realtime44_M->solverInfo,
      &realtime44_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&realtime44_M->solverInfo,
      &realtime44_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&realtime44_M->solverInfo,
      &realtime44_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&realtime44_M->solverInfo, (boolean_T**)
      &realtime44_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&realtime44_M->solverInfo, (&rtmGetErrorStatus
      (realtime44_M)));
    rtsiSetRTModelPtr(&realtime44_M->solverInfo, realtime44_M);
  }

  rtsiSetSimTimeStep(&realtime44_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&realtime44_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&realtime44_M->solverInfo, false);
  realtime44_M->intgData.y = realtime44_M->odeY;
  realtime44_M->intgData.f[0] = realtime44_M->odeF[0];
  realtime44_M->intgData.f[1] = realtime44_M->odeF[1];
  realtime44_M->intgData.f[2] = realtime44_M->odeF[2];
  realtime44_M->intgData.f[3] = realtime44_M->odeF[3];
  realtime44_M->intgData.f[4] = realtime44_M->odeF[4];
  realtime44_M->intgData.f[5] = realtime44_M->odeF[5];
  realtime44_M->contStates = ((real_T *) &realtime44_X);
  realtime44_M->contStateDisabled = ((boolean_T *) &realtime44_XDis);
  realtime44_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&realtime44_M->solverInfo, (void *)&realtime44_M->intgData);
  rtsiSetSolverName(&realtime44_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = realtime44_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    realtime44_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    realtime44_M->Timing.sampleTimes = (&realtime44_M->Timing.sampleTimesArray[0]);
    realtime44_M->Timing.offsetTimes = (&realtime44_M->Timing.offsetTimesArray[0]);

    /* task periods */
    realtime44_M->Timing.sampleTimes[0] = (0.0);
    realtime44_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    realtime44_M->Timing.offsetTimes[0] = (0.0);
    realtime44_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(realtime44_M, &realtime44_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = realtime44_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    realtime44_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(realtime44_M, 5.0);
  realtime44_M->Timing.stepSize0 = 0.001;
  realtime44_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  realtime44_M->Sizes.checksums[0] = (592506650U);
  realtime44_M->Sizes.checksums[1] = (696978732U);
  realtime44_M->Sizes.checksums[2] = (247825238U);
  realtime44_M->Sizes.checksums[3] = (3214187543U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    realtime44_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(realtime44_M->extModeInfo,
      &realtime44_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(realtime44_M->extModeInfo, realtime44_M->Sizes.checksums);
    rteiSetTPtr(realtime44_M->extModeInfo, rtmGetTPtr(realtime44_M));
  }

  realtime44_M->solverInfoPtr = (&realtime44_M->solverInfo);
  realtime44_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&realtime44_M->solverInfo, 0.001);
  rtsiSetSolverMode(&realtime44_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  realtime44_M->blockIO = ((void *) &realtime44_B);
  (void) memset(((void *) &realtime44_B), 0,
                sizeof(B_realtime44_T));

  /* parameters */
  realtime44_M->defaultParam = ((real_T *)&realtime44_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &realtime44_X;
    realtime44_M->contStates = (x);
    (void) memset((void *)&realtime44_X, 0,
                  sizeof(X_realtime44_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &realtime44_XDis;
    realtime44_M->contStateDisabled = (xdis);
    (void) memset((void *)&realtime44_XDis, 0,
                  sizeof(XDis_realtime44_T));
  }

  /* states (dwork) */
  realtime44_M->dwork = ((void *) &realtime44_DW);
  (void) memset((void *)&realtime44_DW, 0,
                sizeof(DW_realtime44_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    realtime44_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 33;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  realtime44_M->Sizes.numContStates = (5);/* Number of continuous states */
  realtime44_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  realtime44_M->Sizes.numY = (0);      /* Number of model outputs */
  realtime44_M->Sizes.numU = (0);      /* Number of model inputs */
  realtime44_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  realtime44_M->Sizes.numSampTimes = (2);/* Number of sample times */
  realtime44_M->Sizes.numBlocks = (21);/* Number of blocks */
  realtime44_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  realtime44_M->Sizes.numBlockPrms = (37);/* Sum of parameter "widths" */
  return realtime44_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

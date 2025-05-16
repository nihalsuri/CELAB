/*
 * realtimemodel.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtimemodel".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri May 16 12:16:01 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "realtimemodel.h"
#include "rtwtypes.h"
#include "realtimemodel_private.h"
#include <string.h>
#include "realtimemodel_dt.h"

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
B_realtimemodel_T realtimemodel_B;

/* Continuous states */
X_realtimemodel_T realtimemodel_X;

/* Disabled State Vector */
XDis_realtimemodel_T realtimemodel_XDis;

/* Block states (default storage) */
DW_realtimemodel_T realtimemodel_DW;

/* Real-time model */
static RT_MODEL_realtimemodel_T realtimemodel_M_;
RT_MODEL_realtimemodel_T *const realtimemodel_M = &realtimemodel_M_;

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  realtimemodel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  realtimemodel_output();
  realtimemodel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  realtimemodel_output();
  realtimemodel_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  realtimemodel_output();
  realtimemodel_derivatives();

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
  realtimemodel_output();
  realtimemodel_derivatives();

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
  realtimemodel_output();
  realtimemodel_derivatives();

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
void realtimemodel_output(void)
{
  real_T rtb_AnalogInput[2];
  real_T rtb_Sum1;
  boolean_T tmp;
  boolean_T tmp_0;
  if (rtmIsMajorTimeStep(realtimemodel_M)) {
    /* set solver stop time */
    if (!(realtimemodel_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&realtimemodel_M->solverInfo,
                            ((realtimemodel_M->Timing.clockTickH0 + 1) *
        realtimemodel_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&realtimemodel_M->solverInfo,
                            ((realtimemodel_M->Timing.clockTick0 + 1) *
        realtimemodel_M->Timing.stepSize0 + realtimemodel_M->Timing.clockTickH0 *
        realtimemodel_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(realtimemodel_M)) {
    realtimemodel_M->Timing.t[0] = rtsiGetT(&realtimemodel_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(realtimemodel_DW.Average_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(realtimemodel_DW.FeedbackControllerNominal1_SubsysRanBC);

  /* S-Function (sldrtei): '<S4>/Encoder Input' */
  /* S-Function Block: <S4>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtimemodel_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &realtimemodel_P.EncoderInput_Channels, &rtb_Sum1, &parm);
  }

  /* S-Function (sldrtai): '<S4>/Analog Input' */
  /* S-Function Block: <S4>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) realtimemodel_P.AnalogInput_RangeMode;
    parm.rangeidx = realtimemodel_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                   realtimemodel_P.AnalogInput_Channels, &rtb_AnalogInput[0],
                   &parm);
  }

  /* Gain: '<Root>/Pulses2Deg' */
  realtimemodel_B.th_hubdeg = realtimemodel_P.sens.enc.pulse2deg * rtb_Sum1;

  /* Sum: '<S1>/Sum' */
  rtb_Sum1 = rtb_AnalogInput[0] - rtb_AnalogInput[1];

  /* Gain: '<S1>/V2Deg1' */
  realtimemodel_B.th_ddeg = realtimemodel_P.sens.pot2.V2deg * rtb_Sum1;

  /* Clock: '<S5>/Clock' */
  rtb_Sum1 = realtimemodel_M->Timing.t[0];

  /* Outputs for Enabled SubSystem: '<Root>/Feedback Controller Nominal1' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S5>/Average' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  tmp = rtsiIsModeUpdateTimeStep(&realtimemodel_M->solverInfo);

  /* End of Outputs for SubSystem: '<Root>/Feedback Controller Nominal1' */
  if (tmp) {
    /* Logic: '<S7>/AND' incorporates:
     *  Constant: '<S7>/Lower Limit'
     *  Constant: '<S7>/Upper Limit'
     *  RelationalOperator: '<S7>/Lower Test'
     *  RelationalOperator: '<S7>/Upper Test'
     */
    realtimemodel_DW.Average_MODE = ((realtimemodel_P.sIn.t0 <= rtb_Sum1) &&
      (rtb_Sum1 <= realtimemodel_P.sIn.t1));
  }

  if (realtimemodel_DW.Average_MODE) {
    if (rtmIsMajorTimeStep(realtimemodel_M)) {
      /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
      realtimemodel_B.DiscreteTimeIntegrator =
        realtimemodel_DW.DiscreteTimeIntegrator_DSTATE;
    }

    if (tmp) {
      srUpdateBC(realtimemodel_DW.Average_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S5>/Average' */

  /* Sum: '<S1>/Sum1' */
  realtimemodel_B.Sum1 = realtimemodel_B.th_ddeg -
    realtimemodel_B.DiscreteTimeIntegrator;

  /* Step: '<Root>/Step1' incorporates:
   *  Step: '<Root>/Step'
   */
  rtb_Sum1 = realtimemodel_M->Timing.t[0];
  if (rtb_Sum1 < realtimemodel_P.sIn.t1) {
    /* Step: '<Root>/Step1' */
    realtimemodel_B.Step1 = realtimemodel_P.Step1_Y0;
  } else {
    /* Step: '<Root>/Step1' */
    realtimemodel_B.Step1 = realtimemodel_P.sIn.position;
  }

  /* End of Step: '<Root>/Step1' */
  tmp_0 = rtmIsMajorTimeStep(realtimemodel_M);
  if (tmp_0) {
  }

  /* Step: '<Root>/Step' */
  if (rtb_Sum1 < realtimemodel_P.sIn.t1) {
    /* Step: '<Root>/Step' */
    realtimemodel_B.Step = realtimemodel_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    realtimemodel_B.Step = realtimemodel_P.Step_YFinal;
  }

  if (tmp_0) {
    /* SignalConversion generated from: '<S2>/Enable' */
    realtimemodel_B.HiddenBuf_InsertedFor_FeedbackControllerNominal1_at_inport_2
      = realtimemodel_B.Step;

    /* Outputs for Enabled SubSystem: '<Root>/Feedback Controller Nominal1' incorporates:
     *  EnablePort: '<S2>/Enable'
     */
    if (tmp) {
      realtimemodel_DW.FeedbackControllerNominal1_MODE =
        (realtimemodel_B.HiddenBuf_InsertedFor_FeedbackControllerNominal1_at_inport_2
         > 0.0);
    }

    /* End of Outputs for SubSystem: '<Root>/Feedback Controller Nominal1' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/Feedback Controller Nominal1' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (realtimemodel_DW.FeedbackControllerNominal1_MODE) {
    /* Gain: '<S2>/deg2rad' */
    rtb_Sum1 = realtimemodel_P.deg2rad * realtimemodel_B.Step1;

    /* Sum: '<S2>/Sum1' incorporates:
     *  Gain: '<S2>/Input feedforward gain (Nu)'
     *  Gain: '<S2>/State feedback gain'
     *  Gain: '<S2>/State feedforward gain(Nx)'
     *  Gain: '<S2>/deg2rad_1'
     *  Sum: '<S2>/Sum'
     *  TransferFcn: '<S3>/Real derivative'
     *  TransferFcn: '<S3>/Real derivative1'
     */
    rtb_Sum1 = (((realtimemodel_P.feedback.Nx[2] * rtb_Sum1 -
                  (realtimemodel_P.Realderivative_C[0] *
                   realtimemodel_X.Realderivative_CSTATE[0] +
                   realtimemodel_P.Realderivative_C[1] *
                   realtimemodel_X.Realderivative_CSTATE[1]) *
                  realtimemodel_P.deg2rad) * realtimemodel_P.feedback.K[2] +
                 ((realtimemodel_P.feedback.Nx[0] * rtb_Sum1 -
                   realtimemodel_P.deg2rad * realtimemodel_B.th_hubdeg) *
                  realtimemodel_P.feedback.K[0] + (realtimemodel_P.feedback.Nx[1]
      * rtb_Sum1 - realtimemodel_P.deg2rad * realtimemodel_B.Sum1) *
                  realtimemodel_P.feedback.K[1])) +
                (realtimemodel_P.feedback.Nx[3] * rtb_Sum1 -
                 (realtimemodel_P.Realderivative1_C[0] *
                  realtimemodel_X.Realderivative1_CSTATE[0] +
                  realtimemodel_P.Realderivative1_C[1] *
                  realtimemodel_X.Realderivative1_CSTATE[1]) *
                 realtimemodel_P.deg2rad) * realtimemodel_P.feedback.K[3]) +
      realtimemodel_P.feedback.Nu * rtb_Sum1;

    /* Saturate: '<S2>/Saturation' */
    if (rtb_Sum1 > realtimemodel_P.Saturation_UpperSat) {
      /* Saturate: '<S2>/Saturation' */
      realtimemodel_B.Saturation = realtimemodel_P.Saturation_UpperSat;
    } else if (rtb_Sum1 < realtimemodel_P.Saturation_LowerSat) {
      /* Saturate: '<S2>/Saturation' */
      realtimemodel_B.Saturation = realtimemodel_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S2>/Saturation' */
      realtimemodel_B.Saturation = rtb_Sum1;
    }

    /* End of Saturate: '<S2>/Saturation' */
    if (tmp) {
      srUpdateBC(realtimemodel_DW.FeedbackControllerNominal1_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Feedback Controller Nominal1' */

  /* S-Function (sldrtao): '<S4>/Analog Output' */
  /* S-Function Block: <S4>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtimemodel_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtimemodel_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtimemodel_P.AnalogOutput_Channels, ((real_T*)
        (&realtimemodel_B.Saturation)), &parm);
    }
  }
}

/* Model update function */
void realtimemodel_update(void)
{
  /* Update for Enabled SubSystem: '<S5>/Average' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (realtimemodel_DW.Average_MODE && rtmIsMajorTimeStep(realtimemodel_M)) {
    /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    realtimemodel_DW.DiscreteTimeIntegrator_DSTATE +=
      realtimemodel_P.DiscreteTimeIntegrator_gainval * realtimemodel_B.th_ddeg;
  }

  /* End of Update for SubSystem: '<S5>/Average' */
  if (rtmIsMajorTimeStep(realtimemodel_M)) {
    rt_ertODEUpdateContinuousStates(&realtimemodel_M->solverInfo);
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
  if (!(++realtimemodel_M->Timing.clockTick0)) {
    ++realtimemodel_M->Timing.clockTickH0;
  }

  realtimemodel_M->Timing.t[0] = rtsiGetSolverStopTime
    (&realtimemodel_M->solverInfo);

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
    if (!(++realtimemodel_M->Timing.clockTick1)) {
      ++realtimemodel_M->Timing.clockTickH1;
    }

    realtimemodel_M->Timing.t[1] = realtimemodel_M->Timing.clockTick1 *
      realtimemodel_M->Timing.stepSize1 + realtimemodel_M->Timing.clockTickH1 *
      realtimemodel_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void realtimemodel_derivatives(void)
{
  XDot_realtimemodel_T *_rtXdot;
  _rtXdot = ((XDot_realtimemodel_T *) realtimemodel_M->derivs);

  /* Derivatives for TransferFcn: '<S3>/Real derivative' */
  _rtXdot->Realderivative_CSTATE[0] = realtimemodel_P.Realderivative_A[0] *
    realtimemodel_X.Realderivative_CSTATE[0];
  _rtXdot->Realderivative_CSTATE[0] += realtimemodel_P.Realderivative_A[1] *
    realtimemodel_X.Realderivative_CSTATE[1];
  _rtXdot->Realderivative_CSTATE[1] = realtimemodel_X.Realderivative_CSTATE[0];
  _rtXdot->Realderivative_CSTATE[0] += realtimemodel_B.th_hubdeg;

  /* Derivatives for TransferFcn: '<S3>/Real derivative1' */
  _rtXdot->Realderivative1_CSTATE[0] = realtimemodel_P.Realderivative1_A[0] *
    realtimemodel_X.Realderivative1_CSTATE[0];
  _rtXdot->Realderivative1_CSTATE[0] += realtimemodel_P.Realderivative1_A[1] *
    realtimemodel_X.Realderivative1_CSTATE[1];
  _rtXdot->Realderivative1_CSTATE[1] = realtimemodel_X.Realderivative1_CSTATE[0];
  _rtXdot->Realderivative1_CSTATE[0] += realtimemodel_B.Sum1;
}

/* Model initialize function */
void realtimemodel_initialize(void)
{
  /* Start for Enabled SubSystem: '<S5>/Average' */
  realtimemodel_DW.Average_MODE = false;

  /* End of Start for SubSystem: '<S5>/Average' */

  /* Start for Enabled SubSystem: '<Root>/Feedback Controller Nominal1' */
  realtimemodel_DW.FeedbackControllerNominal1_MODE = false;

  /* End of Start for SubSystem: '<Root>/Feedback Controller Nominal1' */

  /* Start for S-Function (sldrtao): '<S4>/Analog Output' */

  /* S-Function Block: <S4>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtimemodel_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtimemodel_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtimemodel_P.AnalogOutput_Channels,
                     &realtimemodel_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<S4>/Encoder Input' */

  /* S-Function Block: <S4>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtimemodel_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &realtimemodel_P.EncoderInput_Channels, NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<S3>/Real derivative' */
  realtimemodel_X.Realderivative_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Real derivative1' */
  realtimemodel_X.Realderivative1_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Real derivative' */
  realtimemodel_X.Realderivative_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Real derivative1' */
  realtimemodel_X.Realderivative1_CSTATE[1] = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S5>/Average' */
  /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  realtimemodel_DW.DiscreteTimeIntegrator_DSTATE =
    realtimemodel_P.DiscreteTimeIntegrator_IC;

  /* SystemInitialize for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
   *  Outport: '<S6>/Out'
   */
  realtimemodel_B.DiscreteTimeIntegrator = realtimemodel_P.Out_Y0;

  /* End of SystemInitialize for SubSystem: '<S5>/Average' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Feedback Controller Nominal1' */
  /* SystemInitialize for Saturate: '<S2>/Saturation' incorporates:
   *  Outport: '<S2>/u [V]'
   */
  realtimemodel_B.Saturation = realtimemodel_P.uV_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Feedback Controller Nominal1' */
}

/* Model terminate function */
void realtimemodel_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S4>/Analog Output' */

  /* S-Function Block: <S4>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtimemodel_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtimemodel_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtimemodel_P.AnalogOutput_Channels,
                     &realtimemodel_P.AnalogOutput_FinalValue, &parm);
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
  realtimemodel_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  realtimemodel_update();
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
  realtimemodel_initialize();
}

void MdlTerminate(void)
{
  realtimemodel_terminate();
}

/* Registration function */
RT_MODEL_realtimemodel_T *realtimemodel(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)realtimemodel_M, 0,
                sizeof(RT_MODEL_realtimemodel_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&realtimemodel_M->solverInfo,
                          &realtimemodel_M->Timing.simTimeStep);
    rtsiSetTPtr(&realtimemodel_M->solverInfo, &rtmGetTPtr(realtimemodel_M));
    rtsiSetStepSizePtr(&realtimemodel_M->solverInfo,
                       &realtimemodel_M->Timing.stepSize0);
    rtsiSetdXPtr(&realtimemodel_M->solverInfo, &realtimemodel_M->derivs);
    rtsiSetContStatesPtr(&realtimemodel_M->solverInfo, (real_T **)
                         &realtimemodel_M->contStates);
    rtsiSetNumContStatesPtr(&realtimemodel_M->solverInfo,
      &realtimemodel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&realtimemodel_M->solverInfo,
      &realtimemodel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&realtimemodel_M->solverInfo,
      &realtimemodel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&realtimemodel_M->solverInfo,
      &realtimemodel_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&realtimemodel_M->solverInfo, (boolean_T**)
      &realtimemodel_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&realtimemodel_M->solverInfo, (&rtmGetErrorStatus
      (realtimemodel_M)));
    rtsiSetRTModelPtr(&realtimemodel_M->solverInfo, realtimemodel_M);
  }

  rtsiSetSimTimeStep(&realtimemodel_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&realtimemodel_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&realtimemodel_M->solverInfo, false);
  realtimemodel_M->intgData.y = realtimemodel_M->odeY;
  realtimemodel_M->intgData.f[0] = realtimemodel_M->odeF[0];
  realtimemodel_M->intgData.f[1] = realtimemodel_M->odeF[1];
  realtimemodel_M->intgData.f[2] = realtimemodel_M->odeF[2];
  realtimemodel_M->intgData.f[3] = realtimemodel_M->odeF[3];
  realtimemodel_M->intgData.f[4] = realtimemodel_M->odeF[4];
  realtimemodel_M->intgData.f[5] = realtimemodel_M->odeF[5];
  realtimemodel_M->contStates = ((real_T *) &realtimemodel_X);
  realtimemodel_M->contStateDisabled = ((boolean_T *) &realtimemodel_XDis);
  realtimemodel_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&realtimemodel_M->solverInfo, (void *)
                    &realtimemodel_M->intgData);
  rtsiSetSolverName(&realtimemodel_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = realtimemodel_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    realtimemodel_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    realtimemodel_M->Timing.sampleTimes =
      (&realtimemodel_M->Timing.sampleTimesArray[0]);
    realtimemodel_M->Timing.offsetTimes =
      (&realtimemodel_M->Timing.offsetTimesArray[0]);

    /* task periods */
    realtimemodel_M->Timing.sampleTimes[0] = (0.0);
    realtimemodel_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    realtimemodel_M->Timing.offsetTimes[0] = (0.0);
    realtimemodel_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(realtimemodel_M, &realtimemodel_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = realtimemodel_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    realtimemodel_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(realtimemodel_M, 3.0);
  realtimemodel_M->Timing.stepSize0 = 0.001;
  realtimemodel_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  realtimemodel_M->Sizes.checksums[0] = (143654959U);
  realtimemodel_M->Sizes.checksums[1] = (437644788U);
  realtimemodel_M->Sizes.checksums[2] = (1155593360U);
  realtimemodel_M->Sizes.checksums[3] = (106176072U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    realtimemodel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&realtimemodel_DW.Average_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &realtimemodel_DW.FeedbackControllerNominal1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(realtimemodel_M->extModeInfo,
      &realtimemodel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(realtimemodel_M->extModeInfo,
                        realtimemodel_M->Sizes.checksums);
    rteiSetTPtr(realtimemodel_M->extModeInfo, rtmGetTPtr(realtimemodel_M));
  }

  realtimemodel_M->solverInfoPtr = (&realtimemodel_M->solverInfo);
  realtimemodel_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&realtimemodel_M->solverInfo, 0.001);
  rtsiSetSolverMode(&realtimemodel_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  realtimemodel_M->blockIO = ((void *) &realtimemodel_B);
  (void) memset(((void *) &realtimemodel_B), 0,
                sizeof(B_realtimemodel_T));

  /* parameters */
  realtimemodel_M->defaultParam = ((real_T *)&realtimemodel_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &realtimemodel_X;
    realtimemodel_M->contStates = (x);
    (void) memset((void *)&realtimemodel_X, 0,
                  sizeof(X_realtimemodel_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &realtimemodel_XDis;
    realtimemodel_M->contStateDisabled = (xdis);
    (void) memset((void *)&realtimemodel_XDis, 0,
                  sizeof(XDis_realtimemodel_T));
  }

  /* states (dwork) */
  realtimemodel_M->dwork = ((void *) &realtimemodel_DW);
  (void) memset((void *)&realtimemodel_DW, 0,
                sizeof(DW_realtimemodel_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    realtimemodel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 33;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  realtimemodel_M->Sizes.numContStates = (4);/* Number of continuous states */
  realtimemodel_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  realtimemodel_M->Sizes.numY = (0);   /* Number of model outputs */
  realtimemodel_M->Sizes.numU = (0);   /* Number of model inputs */
  realtimemodel_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  realtimemodel_M->Sizes.numSampTimes = (2);/* Number of sample times */
  realtimemodel_M->Sizes.numBlocks = (30);/* Number of blocks */
  realtimemodel_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  realtimemodel_M->Sizes.numBlockPrms = (38);/* Sum of parameter "widths" */
  return realtimemodel_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

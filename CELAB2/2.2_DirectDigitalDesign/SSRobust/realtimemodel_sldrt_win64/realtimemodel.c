/*
 * realtimemodel.c
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

#include "realtimemodel.h"
#include "rtwtypes.h"
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

/* Block states (default storage) */
DW_realtimemodel_T realtimemodel_DW;

/* Real-time model */
static RT_MODEL_realtimemodel_T realtimemodel_M_;
RT_MODEL_realtimemodel_T *const realtimemodel_M = &realtimemodel_M_;
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
  (realtimemodel_M->Timing.TaskCounters.TID[2])++;
  if ((realtimemodel_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.05s, 0.0s] */
    realtimemodel_M->Timing.TaskCounters.TID[2] = 0;
  }

  realtimemodel_M->Timing.sampleHits[2] =
    (realtimemodel_M->Timing.TaskCounters.TID[2] == 0) ? 1 : 0;
}

/* Model output function */
void realtimemodel_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[2];
  real_T rtb_EncoderInput;
  boolean_T tmp;

  /* Step: '<Root>/Step' */
  if (realtimemodel_M->Timing.t[0] < realtimemodel_P.Step_Time) {
    /* Step: '<Root>/Step' */
    realtimemodel_B.Step = realtimemodel_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    realtimemodel_B.Step = realtimemodel_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* S-Function (sldrtei): '<S3>/Encoder Input' */
  /* S-Function Block: <S3>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtimemodel_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &realtimemodel_P.EncoderInput_Channels, &rtb_EncoderInput,
                   &parm);
  }

  /* S-Function (sldrtai): '<S3>/Analog Input' */
  /* S-Function Block: <S3>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) realtimemodel_P.AnalogInput_RangeMode;
    parm.rangeidx = realtimemodel_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                   realtimemodel_P.AnalogInput_Channels, &rtb_AnalogInput[0],
                   &parm);
  }

  /* Gain: '<S1>/Gain2' */
  realtimemodel_B.Gain2 = realtimemodel_P.sens.enc.pulse2deg * rtb_EncoderInput;

  /* ZeroOrderHold: '<S4>/Zero-Order Hold1' */
  tmp = (realtimemodel_M->Timing.TaskCounters.TID[2] == 0);

  /* Gain: '<S2>/deg2rad' */
  rtb_EncoderInput = realtimemodel_P.deg2rad * realtimemodel_B.Step;
  if (tmp) {
    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    realtimemodel_B.DiscreteTimeIntegrator =
      realtimemodel_DW.DiscreteTimeIntegrator_DSTATE;

    /* ZeroOrderHold: '<S4>/Zero-Order Hold2' */
    realtimemodel_B.ZeroOrderHold2 = realtimemodel_B.Gain2;

    /* Gain: '<S2>/deg2rad2' incorporates:
     *  DiscreteStateSpace: '<S4>/Discrete State-Space'
     *  Gain: '<S4>/2nd Col of J0'
     *  Sum: '<S4>/Sum'
     */
    realtimemodel_B.deg2rad2 = (realtimemodel_P.obs3.H0[0] *
      realtimemodel_DW.DiscreteStateSpace_DSTATE +
      realtimemodel_P.undColofJ0_Gain[0] * realtimemodel_B.ZeroOrderHold2) *
      realtimemodel_P.deg2rad;

    /* Gain: '<S2>/rpm2rads' incorporates:
     *  DiscreteStateSpace: '<S4>/Discrete State-Space'
     *  Gain: '<S4>/2nd Col of J0'
     *  Sum: '<S4>/Sum'
     */
    realtimemodel_B.rpm2rads = (realtimemodel_P.obs3.H0[1] *
      realtimemodel_DW.DiscreteStateSpace_DSTATE +
      realtimemodel_P.undColofJ0_Gain[1] * realtimemodel_B.ZeroOrderHold2) *
      realtimemodel_P.rpm2rads;
  }

  /* Gain: '<S2>/Integral gain' incorporates:
   *  Sum: '<S2>/Sum2'
   */
  realtimemodel_B.Integralgain = (rtb_EncoderInput - realtimemodel_B.deg2rad2) *
    realtimemodel_P.feedback3.Ki;

  /* Sum: '<S2>/Sum1' incorporates:
   *  Gain: '<S2>/Input feedforward gain (Nu)'
   *  Gain: '<S2>/State feedback gain'
   *  Gain: '<S2>/State feedforward gain(Nx)'
   *  Sum: '<S2>/Sum'
   */
  rtb_EncoderInput = (((realtimemodel_P.feedback3.Nx[0] * rtb_EncoderInput -
                        realtimemodel_B.deg2rad2) * realtimemodel_P.feedback3.K
                       [0] + (realtimemodel_P.feedback3.Nx[1] * rtb_EncoderInput
    - realtimemodel_B.rpm2rads) * realtimemodel_P.feedback3.K[1]) +
                      realtimemodel_P.feedback3.Nu * rtb_EncoderInput) +
    realtimemodel_B.DiscreteTimeIntegrator;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_EncoderInput > realtimemodel_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    realtimemodel_B.Saturation = realtimemodel_P.Saturation_UpperSat;
  } else if (rtb_EncoderInput < realtimemodel_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    realtimemodel_B.Saturation = realtimemodel_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    realtimemodel_B.Saturation = rtb_EncoderInput;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* S-Function (sldrtao): '<S3>/Analog Output' */
  /* S-Function Block: <S3>/Analog Output */
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

  /* ZeroOrderHold: '<S4>/Zero-Order Hold1' */
  if (tmp) {
    /* ZeroOrderHold: '<S4>/Zero-Order Hold1' */
    realtimemodel_B.ZeroOrderHold1 = realtimemodel_B.Saturation;

    /* SignalConversion generated from: '<S4>/Discrete State-Space' */
    realtimemodel_B.TmpSignalConversionAtDiscreteStateSpaceInport1[0] =
      realtimemodel_B.ZeroOrderHold1;
    realtimemodel_B.TmpSignalConversionAtDiscreteStateSpaceInport1[1] =
      realtimemodel_B.ZeroOrderHold2;
  }
}

/* Model update function */
void realtimemodel_update(void)
{
  if (realtimemodel_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    realtimemodel_DW.DiscreteTimeIntegrator_DSTATE +=
      realtimemodel_P.DiscreteTimeIntegrator_gainval *
      realtimemodel_B.Integralgain;

    /* Update for DiscreteStateSpace: '<S4>/Discrete State-Space' */
    realtimemodel_DW.DiscreteStateSpace_DSTATE = (realtimemodel_P.obs3.phi0 *
      realtimemodel_DW.DiscreteStateSpace_DSTATE + realtimemodel_P.obs3.gamma0[0]
      * realtimemodel_B.TmpSignalConversionAtDiscreteStateSpaceInport1[0]) +
      realtimemodel_P.obs3.gamma0[1] *
      realtimemodel_B.TmpSignalConversionAtDiscreteStateSpaceInport1[1];
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

  realtimemodel_M->Timing.t[0] = realtimemodel_M->Timing.clockTick0 *
    realtimemodel_M->Timing.stepSize0 + realtimemodel_M->Timing.clockTickH0 *
    realtimemodel_M->Timing.stepSize0 * 4294967296.0;

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

  if (realtimemodel_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++realtimemodel_M->Timing.clockTick2)) {
      ++realtimemodel_M->Timing.clockTickH2;
    }

    realtimemodel_M->Timing.t[2] = realtimemodel_M->Timing.clockTick2 *
      realtimemodel_M->Timing.stepSize2 + realtimemodel_M->Timing.clockTickH2 *
      realtimemodel_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void realtimemodel_initialize(void)
{
  /* Start for S-Function (sldrtao): '<S3>/Analog Output' */

  /* S-Function Block: <S3>/Analog Output */
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

  /* InitializeConditions for S-Function (sldrtei): '<S3>/Encoder Input' */

  /* S-Function Block: <S3>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtimemodel_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &realtimemodel_P.EncoderInput_Channels, NULL, &parm);
  }

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  realtimemodel_DW.DiscreteTimeIntegrator_DSTATE =
    realtimemodel_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteStateSpace: '<S4>/Discrete State-Space' */
  realtimemodel_DW.DiscreteStateSpace_DSTATE =
    realtimemodel_P.DiscreteStateSpace_InitialCondition;
}

/* Model terminate function */
void realtimemodel_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S3>/Analog Output' */

  /* S-Function Block: <S3>/Analog Output */
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
    rtsiSetErrorStatusPtr(&realtimemodel_M->solverInfo, (&rtmGetErrorStatus
      (realtimemodel_M)));
    rtsiSetRTModelPtr(&realtimemodel_M->solverInfo, realtimemodel_M);
  }

  rtsiSetSimTimeStep(&realtimemodel_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&realtimemodel_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&realtimemodel_M->solverInfo, false);
  rtsiSetSolverName(&realtimemodel_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = realtimemodel_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    realtimemodel_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    realtimemodel_M->Timing.sampleTimes =
      (&realtimemodel_M->Timing.sampleTimesArray[0]);
    realtimemodel_M->Timing.offsetTimes =
      (&realtimemodel_M->Timing.offsetTimesArray[0]);

    /* task periods */
    realtimemodel_M->Timing.sampleTimes[0] = (0.0);
    realtimemodel_M->Timing.sampleTimes[1] = (0.001);
    realtimemodel_M->Timing.sampleTimes[2] = (0.05);

    /* task offsets */
    realtimemodel_M->Timing.offsetTimes[0] = (0.0);
    realtimemodel_M->Timing.offsetTimes[1] = (0.0);
    realtimemodel_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(realtimemodel_M, &realtimemodel_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = realtimemodel_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    realtimemodel_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(realtimemodel_M, 5.0);
  realtimemodel_M->Timing.stepSize0 = 0.001;
  realtimemodel_M->Timing.stepSize1 = 0.001;
  realtimemodel_M->Timing.stepSize2 = 0.05;

  /* External mode info */
  realtimemodel_M->Sizes.checksums[0] = (2857081031U);
  realtimemodel_M->Sizes.checksums[1] = (1511829823U);
  realtimemodel_M->Sizes.checksums[2] = (1008337302U);
  realtimemodel_M->Sizes.checksums[3] = (1941819986U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    realtimemodel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
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
    dtInfo.numDataTypes = 31;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  realtimemodel_M->Sizes.numContStates = (0);/* Number of continuous states */
  realtimemodel_M->Sizes.numY = (0);   /* Number of model outputs */
  realtimemodel_M->Sizes.numU = (0);   /* Number of model inputs */
  realtimemodel_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  realtimemodel_M->Sizes.numSampTimes = (3);/* Number of sample times */
  realtimemodel_M->Sizes.numBlocks = (24);/* Number of blocks */
  realtimemodel_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  realtimemodel_M->Sizes.numBlockPrms = (36);/* Sum of parameter "widths" */
  return realtimemodel_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

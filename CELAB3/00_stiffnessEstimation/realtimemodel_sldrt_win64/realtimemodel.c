/*
 * realtimemodel.c
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

#include "realtimemodel.h"
#include "rtwtypes.h"
#include <math.h>
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

/* Model output function */
void realtimemodel_output(void)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput;
  real_T rtb_AnalogInput[2];
  real_T rtb_Clock;

  /* Reset subsysRan breadcrumbs */
  srClearBC(realtimemodel_DW.Average_SubsysRanBC);

  /* S-Function (sldrtai): '<S2>/Analog Input' */
  /* S-Function Block: <S2>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) realtimemodel_P.AnalogInput_RangeMode;
    parm.rangeidx = realtimemodel_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                   realtimemodel_P.AnalogInput_Channels, &rtb_AnalogInput[0],
                   &parm);
  }

  /* S-Function (sldrtei): '<S2>/Encoder Input' */
  /* S-Function Block: <S2>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtimemodel_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &realtimemodel_P.EncoderInput_Channels, &rtb_EncoderInput,
                   &parm);
  }

  /* Gain: '<S1>/V2Deg1' incorporates:
   *  Sum: '<S1>/Sum'
   */
  realtimemodel_B.th_ddeg = (rtb_AnalogInput[0] - rtb_AnalogInput[1]) *
    realtimemodel_P.sens.pot2.V2deg;

  /* Clock: '<S3>/Clock' */
  rtb_Clock = realtimemodel_M->Timing.t[0];

  /* Outputs for Enabled SubSystem: '<S3>/Average' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Logic: '<S5>/AND' incorporates:
   *  Constant: '<S5>/Lower Limit'
   *  Constant: '<S5>/Upper Limit'
   *  RelationalOperator: '<S5>/Lower Test'
   *  RelationalOperator: '<S5>/Upper Test'
   */
  if ((realtimemodel_P.sIn.t0 <= rtb_Clock) && (rtb_Clock <=
       realtimemodel_P.sIn.t1)) {
    realtimemodel_DW.Average_MODE = true;

    /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
    realtimemodel_B.DiscreteTimeIntegrator =
      realtimemodel_DW.DiscreteTimeIntegrator_DSTATE;
    srUpdateBC(realtimemodel_DW.Average_SubsysRanBC);
  } else {
    realtimemodel_DW.Average_MODE = false;
  }

  /* End of Logic: '<S5>/AND' */
  /* End of Outputs for SubSystem: '<S3>/Average' */

  /* Abs: '<Root>/Abs' incorporates:
   *  Sum: '<S1>/Sum1'
   */
  realtimemodel_B.Abs = fabs(realtimemodel_B.th_ddeg -
    realtimemodel_B.DiscreteTimeIntegrator);

  /* S-Function (sldrtao): '<S2>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* S-Function Block: <S2>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtimemodel_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtimemodel_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtimemodel_P.AnalogOutput_Channels, ((real_T*)
        (&realtimemodel_P.Constant_Value)), &parm);
    }
  }
}

/* Model update function */
void realtimemodel_update(void)
{
  /* Update for Enabled SubSystem: '<S3>/Average' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (realtimemodel_DW.Average_MODE) {
    /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
    realtimemodel_DW.DiscreteTimeIntegrator_DSTATE +=
      realtimemodel_P.DiscreteTimeIntegrator_gainval * realtimemodel_B.th_ddeg;
  }

  /* End of Update for SubSystem: '<S3>/Average' */

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
}

/* Model initialize function */
void realtimemodel_initialize(void)
{
  /* Start for Enabled SubSystem: '<S3>/Average' */
  realtimemodel_DW.Average_MODE = false;

  /* End of Start for SubSystem: '<S3>/Average' */

  /* Start for S-Function (sldrtao): '<S2>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: <S2>/Analog Output */
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

  /* InitializeConditions for S-Function (sldrtei): '<S2>/Encoder Input' */

  /* S-Function Block: <S2>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtimemodel_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &realtimemodel_P.EncoderInput_Channels, NULL, &parm);
  }

  /* SystemInitialize for Enabled SubSystem: '<S3>/Average' */
  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  realtimemodel_DW.DiscreteTimeIntegrator_DSTATE =
    realtimemodel_P.DiscreteTimeIntegrator_IC;

  /* SystemInitialize for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Outport: '<S4>/Out'
   */
  realtimemodel_B.DiscreteTimeIntegrator = realtimemodel_P.Out_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Average' */
}

/* Model terminate function */
void realtimemodel_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S2>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: <S2>/Analog Output */
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

  rtmSetTFinal(realtimemodel_M, 20.0);
  realtimemodel_M->Timing.stepSize0 = 0.001;
  realtimemodel_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  realtimemodel_M->Sizes.checksums[0] = (3386330642U);
  realtimemodel_M->Sizes.checksums[1] = (3331922785U);
  realtimemodel_M->Sizes.checksums[2] = (3620695689U);
  realtimemodel_M->Sizes.checksums[3] = (2269240594U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    realtimemodel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&realtimemodel_DW.Average_SubsysRanBC;
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
  realtimemodel_M->Sizes.numSampTimes = (2);/* Number of sample times */
  realtimemodel_M->Sizes.numBlocks = (18);/* Number of blocks */
  realtimemodel_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  realtimemodel_M->Sizes.numBlockPrms = (23);/* Sum of parameter "widths" */
  return realtimemodel_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

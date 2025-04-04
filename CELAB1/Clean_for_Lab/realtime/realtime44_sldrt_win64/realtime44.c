/*
 * realtime44.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtime44".
 *
 * Model version              : 1.3
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Apr  4 10:59:07 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "realtime44.h"
#include "rtwtypes.h"
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

/* Block states (default storage) */
DW_realtime44_T realtime44_DW;

/* Real-time model */
static RT_MODEL_realtime44_T realtime44_M_;
RT_MODEL_realtime44_T *const realtime44_M = &realtime44_M_;

/* Model output function */
void realtime44_output(void)
{
  real_T rtb_AnalogInput[2];

  /* S-Function (sldrtai): '<Root>/Analog Input' */
  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) realtime44_P.AnalogInput_RangeMode;
    parm.rangeidx = realtime44_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2, realtime44_P.AnalogInput_Channels,
                   &rtb_AnalogInput[0], &parm);
  }

  /* S-Function (sldrtei): '<Root>/Encoder Input' */
  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtime44_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &realtime44_P.EncoderInput_Channels,
                   &realtime44_B.EncoderInput, &parm);
  }

  /* Sum: '<Root>/Minus' */
  realtime44_B.Minus = rtb_AnalogInput[0] - rtb_AnalogInput[1];

  /* S-Function (sldrtao): '<Root>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtime44_P.AnalogOutput_RangeMode;
      parm.rangeidx = realtime44_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtime44_P.AnalogOutput_Channels, ((real_T*)
        (&realtime44_P.Constant_Value)), &parm);
    }
  }
}

/* Model update function */
void realtime44_update(void)
{
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

  realtime44_M->Timing.t[0] = realtime44_M->Timing.clockTick0 *
    realtime44_M->Timing.stepSize0 + realtime44_M->Timing.clockTickH0 *
    realtime44_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void realtime44_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: <Root>/Analog Output */
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

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtime44_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &realtime44_P.EncoderInput_Channels, NULL, &parm);
  }
}

/* Model terminate function */
void realtime44_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: <Root>/Analog Output */
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

  /* Initialize timing info */
  {
    int_T *mdlTsMap = realtime44_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    realtime44_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    realtime44_M->Timing.sampleTimes = (&realtime44_M->Timing.sampleTimesArray[0]);
    realtime44_M->Timing.offsetTimes = (&realtime44_M->Timing.offsetTimesArray[0]);

    /* task periods */
    realtime44_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    realtime44_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(realtime44_M, &realtime44_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = realtime44_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    realtime44_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(realtime44_M, 10.0);
  realtime44_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  realtime44_M->Sizes.checksums[0] = (3171028026U);
  realtime44_M->Sizes.checksums[1] = (3537844755U);
  realtime44_M->Sizes.checksums[2] = (4157664929U);
  realtime44_M->Sizes.checksums[3] = (1152440179U);

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
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  realtime44_M->Sizes.numContStates = (0);/* Number of continuous states */
  realtime44_M->Sizes.numY = (0);      /* Number of model outputs */
  realtime44_M->Sizes.numU = (0);      /* Number of model inputs */
  realtime44_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  realtime44_M->Sizes.numSampTimes = (1);/* Number of sample times */
  realtime44_M->Sizes.numBlocks = (7); /* Number of blocks */
  realtime44_M->Sizes.numBlockIO = (2);/* Number of block outputs */
  realtime44_M->Sizes.numBlockPrms = (18);/* Sum of parameter "widths" */
  return realtime44_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

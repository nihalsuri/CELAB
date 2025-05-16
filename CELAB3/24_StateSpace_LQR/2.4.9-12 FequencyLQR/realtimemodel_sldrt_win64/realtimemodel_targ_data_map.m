    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (realtimemodel_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtimemodel_P.LQR
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtimemodel_P.feedback
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtimemodel_P.sens
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtimemodel_P.sIn
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% realtimemodel_P.deg2rad
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_P.AnalogOutput_FinalValue
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% realtimemodel_P.AnalogOutput_InitialValue
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% realtimemodel_P.EncoderInput_InputFilter
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% realtimemodel_P.EncoderInput_MaxMissedTicks
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

                    ;% realtimemodel_P.AnalogInput_MaxMissedTicks
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 5;

                    ;% realtimemodel_P.AnalogOutput_MaxMissedTicks
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 6;

                    ;% realtimemodel_P.EncoderInput_YieldWhenWaiting
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 7;

                    ;% realtimemodel_P.AnalogInput_YieldWhenWaiting
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 8;

                    ;% realtimemodel_P.AnalogOutput_YieldWhenWaiting
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% realtimemodel_P.EncoderInput_Channels
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_P.AnalogInput_Channels
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

                    ;% realtimemodel_P.AnalogOutput_Channels
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 3;

                    ;% realtimemodel_P.AnalogInput_RangeMode
                    section.data(4).logicalSrcIdx = 17;
                    section.data(4).dtTransOffset = 4;

                    ;% realtimemodel_P.AnalogOutput_RangeMode
                    section.data(5).logicalSrcIdx = 18;
                    section.data(5).dtTransOffset = 5;

                    ;% realtimemodel_P.AnalogInput_VoltRange
                    section.data(6).logicalSrcIdx = 19;
                    section.data(6).dtTransOffset = 6;

                    ;% realtimemodel_P.AnalogOutput_VoltRange
                    section.data(7).logicalSrcIdx = 20;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% realtimemodel_P.Out_Y0
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_P.DiscreteTimeIntegrator_gainval
                    section.data(2).logicalSrcIdx = 22;
                    section.data(2).dtTransOffset = 1;

                    ;% realtimemodel_P.DiscreteTimeIntegrator_IC
                    section.data(3).logicalSrcIdx = 23;
                    section.data(3).dtTransOffset = 2;

                    ;% realtimemodel_P.uV_Y0
                    section.data(4).logicalSrcIdx = 24;
                    section.data(4).dtTransOffset = 3;

                    ;% realtimemodel_P.Integrator_IC
                    section.data(5).logicalSrcIdx = 25;
                    section.data(5).dtTransOffset = 4;

                    ;% realtimemodel_P.StateSpace_C
                    section.data(6).logicalSrcIdx = 26;
                    section.data(6).dtTransOffset = 5;

                    ;% realtimemodel_P.StateSpace_InitialCondition
                    section.data(7).logicalSrcIdx = 27;
                    section.data(7).dtTransOffset = 9;

                    ;% realtimemodel_P.Saturation_UpperSat
                    section.data(8).logicalSrcIdx = 28;
                    section.data(8).dtTransOffset = 10;

                    ;% realtimemodel_P.Saturation_LowerSat
                    section.data(9).logicalSrcIdx = 29;
                    section.data(9).dtTransOffset = 11;

                    ;% realtimemodel_P.PulseGenerator_Amp
                    section.data(10).logicalSrcIdx = 30;
                    section.data(10).dtTransOffset = 12;

                    ;% realtimemodel_P.PulseGenerator_Period
                    section.data(11).logicalSrcIdx = 31;
                    section.data(11).dtTransOffset = 13;

                    ;% realtimemodel_P.PulseGenerator_Duty
                    section.data(12).logicalSrcIdx = 32;
                    section.data(12).dtTransOffset = 14;

                    ;% realtimemodel_P.PulseGenerator_PhaseDelay
                    section.data(13).logicalSrcIdx = 33;
                    section.data(13).dtTransOffset = 15;

                    ;% realtimemodel_P.Realderivative_A
                    section.data(14).logicalSrcIdx = 34;
                    section.data(14).dtTransOffset = 16;

                    ;% realtimemodel_P.Realderivative_C
                    section.data(15).logicalSrcIdx = 35;
                    section.data(15).dtTransOffset = 18;

                    ;% realtimemodel_P.Realderivative1_A
                    section.data(16).logicalSrcIdx = 36;
                    section.data(16).dtTransOffset = 20;

                    ;% realtimemodel_P.Realderivative1_C
                    section.data(17).logicalSrcIdx = 37;
                    section.data(17).dtTransOffset = 22;

                    ;% realtimemodel_P.Step2_Y0
                    section.data(18).logicalSrcIdx = 38;
                    section.data(18).dtTransOffset = 24;

                    ;% realtimemodel_P.Step2_YFinal
                    section.data(19).logicalSrcIdx = 39;
                    section.data(19).dtTransOffset = 25;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (realtimemodel_B)
        ;%
            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% realtimemodel_B.th_hubdeg
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_B.th_ddeg
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% realtimemodel_B.Sum1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% realtimemodel_B.PulseGenerator
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% realtimemodel_B.Step2
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% realtimemodel_B.HiddenBuf_InsertedFor_FeedbackControllers_at_inport_2
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% realtimemodel_B.deg2rad
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% realtimemodel_B.InputfeedforwardgainNu
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% realtimemodel_B.x
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% realtimemodel_B.Integralgain
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 12;

                    ;% realtimemodel_B.StatefeedforwardgainNx
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 13;

                    ;% realtimemodel_B.Saturation
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 19;

                    ;% realtimemodel_B.DiscreteTimeIntegrator
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (realtimemodel_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtimemodel_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% realtimemodel_DW.EncoderInput_PWORK
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_DW.AnalogInput_PWORK
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% realtimemodel_DW.varthetadeg_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% realtimemodel_DW.AnalogOutput_PWORK
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtimemodel_DW.clockTickCounter
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% realtimemodel_DW.FeedbackControllers_SubsysRanBC
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_DW.Average_SubsysRanBC
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% realtimemodel_DW.FeedbackControllers_MODE
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_DW.Average_MODE
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3553430151;
    targMap.checksum1 = 286804286;
    targMap.checksum2 = 3797154480;
    targMap.checksum3 = 1016563170;


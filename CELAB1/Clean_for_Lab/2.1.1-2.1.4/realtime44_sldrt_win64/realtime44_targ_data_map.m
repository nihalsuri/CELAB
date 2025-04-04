    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 11;
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
        ;% Auto data (realtime44_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime44_P.feedforward
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime44_P.sens
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime44_P.filt
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime44_P.PID
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime44_P.windup
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime44_P.sIn
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% realtime44_P.degs2rpm
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_P.rpm2degs
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_P.AnalogOutput_FinalValue
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime44_P.AnalogOutput_InitialValue
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime44_P.EncoderInput_InputFilter
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime44_P.EncoderInput_MaxMissedTicks
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 5;

                    ;% realtime44_P.AnalogInput_MaxMissedTicks
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 6;

                    ;% realtime44_P.AnalogOutput_MaxMissedTicks
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 7;

                    ;% realtime44_P.EncoderInput_YieldWhenWaiting
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 8;

                    ;% realtime44_P.AnalogInput_YieldWhenWaiting
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 9;

                    ;% realtime44_P.AnalogOutput_YieldWhenWaiting
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% realtime44_P.EncoderInput_Channels
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_P.AnalogInput_Channels
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_P.AnalogOutput_Channels
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 3;

                    ;% realtime44_P.AnalogInput_RangeMode
                    section.data(4).logicalSrcIdx = 20;
                    section.data(4).dtTransOffset = 4;

                    ;% realtime44_P.AnalogOutput_RangeMode
                    section.data(5).logicalSrcIdx = 21;
                    section.data(5).dtTransOffset = 5;

                    ;% realtime44_P.AnalogInput_VoltRange
                    section.data(6).logicalSrcIdx = 22;
                    section.data(6).dtTransOffset = 6;

                    ;% realtime44_P.AnalogOutput_VoltRange
                    section.data(7).logicalSrcIdx = 23;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% realtime44_P.WrapToZero_Threshold
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_P.WrapToZero_Threshold_g
                    section.data(2).logicalSrcIdx = 25;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_P.WrapToZero_Threshold_m
                    section.data(3).logicalSrcIdx = 26;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime44_P.WrapToZero_Threshold_e
                    section.data(4).logicalSrcIdx = 27;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% realtime44_P.Step_Time
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_P.Step_Y0
                    section.data(2).logicalSrcIdx = 29;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_P.Constant_Value
                    section.data(3).logicalSrcIdx = 30;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime44_P.Integrator1_IC
                    section.data(4).logicalSrcIdx = 31;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime44_P.Step1_Time
                    section.data(5).logicalSrcIdx = 32;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime44_P.Step1_Y0
                    section.data(6).logicalSrcIdx = 33;
                    section.data(6).dtTransOffset = 5;

                    ;% realtime44_P.Constant1_Value
                    section.data(7).logicalSrcIdx = 34;
                    section.data(7).dtTransOffset = 6;

                    ;% realtime44_P.Step_Time_a
                    section.data(8).logicalSrcIdx = 35;
                    section.data(8).dtTransOffset = 7;

                    ;% realtime44_P.Step_Y0_k
                    section.data(9).logicalSrcIdx = 36;
                    section.data(9).dtTransOffset = 8;

                    ;% realtime44_P.Integrator2_IC
                    section.data(10).logicalSrcIdx = 37;
                    section.data(10).dtTransOffset = 9;

                    ;% realtime44_P.Gain1_Gain
                    section.data(11).logicalSrcIdx = 38;
                    section.data(11).dtTransOffset = 10;

                    ;% realtime44_P.Integrator_IC
                    section.data(12).logicalSrcIdx = 39;
                    section.data(12).dtTransOffset = 11;

                    ;% realtime44_P.RealDerivative_A
                    section.data(13).logicalSrcIdx = 40;
                    section.data(13).dtTransOffset = 12;

                    ;% realtime44_P.RealDerivative_C
                    section.data(14).logicalSrcIdx = 41;
                    section.data(14).dtTransOffset = 13;

                    ;% realtime44_P.RealDerivative_D
                    section.data(15).logicalSrcIdx = 42;
                    section.data(15).dtTransOffset = 14;

                    ;% realtime44_P.Saturation_UpperSat
                    section.data(16).logicalSrcIdx = 43;
                    section.data(16).dtTransOffset = 15;

                    ;% realtime44_P.Saturation_LowerSat
                    section.data(17).logicalSrcIdx = 44;
                    section.data(17).dtTransOffset = 16;

                    ;% realtime44_P.Integrator1_IC_i
                    section.data(18).logicalSrcIdx = 45;
                    section.data(18).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% realtime44_P.Constant_Value_l
                    section.data(1).logicalSrcIdx = 46;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_P.Constant_Value_h
                    section.data(2).logicalSrcIdx = 47;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_P.Constant_Value_k
                    section.data(3).logicalSrcIdx = 48;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime44_P.Constant_Value_n
                    section.data(4).logicalSrcIdx = 49;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime44_P.Output_InitialCondition
                    section.data(5).logicalSrcIdx = 50;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime44_P.Output_InitialCondition_g
                    section.data(6).logicalSrcIdx = 51;
                    section.data(6).dtTransOffset = 5;

                    ;% realtime44_P.FixPtConstant_Value
                    section.data(7).logicalSrcIdx = 52;
                    section.data(7).dtTransOffset = 6;

                    ;% realtime44_P.Output_InitialCondition_f
                    section.data(8).logicalSrcIdx = 53;
                    section.data(8).dtTransOffset = 7;

                    ;% realtime44_P.FixPtConstant_Value_a
                    section.data(9).logicalSrcIdx = 54;
                    section.data(9).dtTransOffset = 8;

                    ;% realtime44_P.FixPtConstant_Value_b
                    section.data(10).logicalSrcIdx = 55;
                    section.data(10).dtTransOffset = 9;

                    ;% realtime44_P.FixPtConstant_Value_j
                    section.data(11).logicalSrcIdx = 56;
                    section.data(11).dtTransOffset = 10;

                    ;% realtime44_P.Output_InitialCondition_h
                    section.data(12).logicalSrcIdx = 57;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
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
        nTotSects     = 2;
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
        ;% Auto data (realtime44_B)
        ;%
            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% realtime44_B.omega_lrpm
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_B.Reference
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_B.a_lrpm
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime44_B.a_refdegs
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime44_B.Reference_f
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime44_B.thi_ldeg
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% realtime44_B.Output
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% realtime44_B.MultiportSwitch
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% realtime44_B.degs2
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% realtime44_B.Kd
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% realtime44_B.Sum2
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% realtime44_B.degs
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% realtime44_B.degs2_f
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% realtime44_B.omega_ldegs
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% realtime44_B.FixPtSwitch
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_B.FixPtSwitch_d
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_B.FixPtSwitch_j
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime44_B.FixPtSwitch_n
                    section.data(4).logicalSrcIdx = 17;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
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
        nTotSects     = 2;
        sectIdxOffset = 2;

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
        ;% Auto data (realtime44_DW)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% realtime44_DW.omega_motorrpm_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_DW.omega_motorrpm1_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% realtime44_DW.EncoderInput_PWORK
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% realtime44_DW.AnalogInput_PWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% realtime44_DW.vartheta_loaddeg_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% realtime44_DW.AnalogOutput_PWORK
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% realtime44_DW.Output_DSTATE
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_DW.Output_DSTATE_g
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_DW.Output_DSTATE_e
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime44_DW.Output_DSTATE_i
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
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


    targMap.checksum0 = 3741444855;
    targMap.checksum1 = 1570679977;
    targMap.checksum2 = 4289016263;
    targMap.checksum3 = 3127174135;


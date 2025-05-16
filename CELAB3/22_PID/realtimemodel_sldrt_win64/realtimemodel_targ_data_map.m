    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
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

                    ;% realtimemodel_P.sens
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtimemodel_P.sIn
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtimemodel_P.PID
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% realtimemodel_P.AnalogOutput_FinalValue
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_P.AnalogOutput_InitialValue
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% realtimemodel_P.EncoderInput_InputFilter
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% realtimemodel_P.EncoderInput_MaxMissedTicks
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% realtimemodel_P.AnalogInput_MaxMissedTicks
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% realtimemodel_P.AnalogOutput_MaxMissedTicks
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% realtimemodel_P.EncoderInput_YieldWhenWaiting
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% realtimemodel_P.AnalogInput_YieldWhenWaiting
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% realtimemodel_P.AnalogOutput_YieldWhenWaiting
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% realtimemodel_P.EncoderInput_Channels
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_P.AnalogInput_Channels
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% realtimemodel_P.AnalogOutput_Channels
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 3;

                    ;% realtimemodel_P.AnalogInput_RangeMode
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 4;

                    ;% realtimemodel_P.AnalogOutput_RangeMode
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 5;

                    ;% realtimemodel_P.AnalogInput_VoltRange
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 6;

                    ;% realtimemodel_P.AnalogOutput_VoltRange
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% realtimemodel_P.Saturation_UpperSat
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_P.Saturation_LowerSat
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

                    ;% realtimemodel_P.Step1_Y0
                    section.data(3).logicalSrcIdx = 21;
                    section.data(3).dtTransOffset = 2;

                    ;% realtimemodel_P.Gain1_Gain
                    section.data(4).logicalSrcIdx = 22;
                    section.data(4).dtTransOffset = 3;

                    ;% realtimemodel_P.Integrator_IC
                    section.data(5).logicalSrcIdx = 23;
                    section.data(5).dtTransOffset = 4;

                    ;% realtimemodel_P.TransferFcn_A
                    section.data(6).logicalSrcIdx = 24;
                    section.data(6).dtTransOffset = 5;

                    ;% realtimemodel_P.TransferFcn_C
                    section.data(7).logicalSrcIdx = 25;
                    section.data(7).dtTransOffset = 6;

                    ;% realtimemodel_P.TransferFcn_D
                    section.data(8).logicalSrcIdx = 26;
                    section.data(8).dtTransOffset = 7;

                    ;% realtimemodel_P.Saturation_UpperSat_i
                    section.data(9).logicalSrcIdx = 27;
                    section.data(9).dtTransOffset = 8;

                    ;% realtimemodel_P.Saturation_LowerSat_n
                    section.data(10).logicalSrcIdx = 28;
                    section.data(10).dtTransOffset = 9;

                    ;% realtimemodel_P.Gain1_Gain_n
                    section.data(11).logicalSrcIdx = 29;
                    section.data(11).dtTransOffset = 10;

                    ;% realtimemodel_P.Integrator_IC_c
                    section.data(12).logicalSrcIdx = 30;
                    section.data(12).dtTransOffset = 11;

                    ;% realtimemodel_P.TransferFcn_A_h
                    section.data(13).logicalSrcIdx = 31;
                    section.data(13).dtTransOffset = 12;

                    ;% realtimemodel_P.TransferFcn_C_k
                    section.data(14).logicalSrcIdx = 32;
                    section.data(14).dtTransOffset = 13;

                    ;% realtimemodel_P.TransferFcn_D_k
                    section.data(15).logicalSrcIdx = 33;
                    section.data(15).dtTransOffset = 14;

                    ;% realtimemodel_P.Switch_Threshold
                    section.data(16).logicalSrcIdx = 34;
                    section.data(16).dtTransOffset = 15;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
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
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% realtimemodel_B.th_hubdeg
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_B.Step1
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% realtimemodel_B.Gain
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% realtimemodel_B.Sum2
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% realtimemodel_B.Gain_g
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% realtimemodel_B.Gain2
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

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
        nTotSects     = 1;
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
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% realtimemodel_DW.EncoderInput_PWORK
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% realtimemodel_DW.AnalogInput_PWORK
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% realtimemodel_DW.vartheta_hubdeg_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% realtimemodel_DW.AnalogOutput_PWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
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


    targMap.checksum0 = 521994489;
    targMap.checksum1 = 3499676209;
    targMap.checksum2 = 737465543;
    targMap.checksum3 = 844648364;


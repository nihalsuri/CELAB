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
        ;% Auto data (realtime44_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime44_P.sens
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime44_P.filt
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime44_P.sIn
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% realtime44_P.deg2rad
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_P.degs2rpm
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_P.rpm2rads
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime44_P.AnalogOutput_FinalValue
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime44_P.AnalogOutput_InitialValue
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime44_P.EncoderInput_InputFilter
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% realtime44_P.EncoderInput_MaxMissedTicks
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% realtime44_P.AnalogInput_MaxMissedTicks
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% realtime44_P.AnalogOutput_MaxMissedTicks
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

                    ;% realtime44_P.EncoderInput_YieldWhenWaiting
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 9;

                    ;% realtime44_P.AnalogInput_YieldWhenWaiting
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 10;

                    ;% realtime44_P.AnalogOutput_YieldWhenWaiting
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% realtime44_P.EncoderInput_Channels
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_P.AnalogInput_Channels
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_P.AnalogOutput_Channels
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 3;

                    ;% realtime44_P.AnalogInput_RangeMode
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 4;

                    ;% realtime44_P.AnalogOutput_RangeMode
                    section.data(5).logicalSrcIdx = 19;
                    section.data(5).dtTransOffset = 5;

                    ;% realtime44_P.AnalogInput_VoltRange
                    section.data(6).logicalSrcIdx = 20;
                    section.data(6).dtTransOffset = 6;

                    ;% realtime44_P.AnalogOutput_VoltRange
                    section.data(7).logicalSrcIdx = 21;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% realtime44_P.SineWave_Bias
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_P.SineWave_Phase
                    section.data(2).logicalSrcIdx = 23;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_P.Step_Time
                    section.data(3).logicalSrcIdx = 24;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime44_P.Step_Y0
                    section.data(4).logicalSrcIdx = 25;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime44_P.Gain_Gain
                    section.data(5).logicalSrcIdx = 26;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime44_P.TransferFcn_A
                    section.data(6).logicalSrcIdx = 27;
                    section.data(6).dtTransOffset = 6;

                    ;% realtime44_P.TransferFcn_C
                    section.data(7).logicalSrcIdx = 28;
                    section.data(7).dtTransOffset = 9;

                    ;% realtime44_P.Saturation_UpperSat
                    section.data(8).logicalSrcIdx = 29;
                    section.data(8).dtTransOffset = 12;

                    ;% realtime44_P.Saturation_LowerSat
                    section.data(9).logicalSrcIdx = 30;
                    section.data(9).dtTransOffset = 13;

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
        ;% Auto data (realtime44_B)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% realtime44_B.thi_ldeg
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_B.MultiportSwitch
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_B.Sum1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

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
        ;% Auto data (realtime44_DW)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% realtime44_DW.EncoderInput_PWORK
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime44_DW.AnalogInput_PWORK
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime44_DW.thi_ldeg_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime44_DW.AnalogOutput_PWORK
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


    targMap.checksum0 = 592506650;
    targMap.checksum1 = 696978732;
    targMap.checksum2 = 247825238;
    targMap.checksum3 = 3214187543;


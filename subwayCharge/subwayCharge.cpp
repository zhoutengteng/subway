// subwayCharge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "subwaySocket.h"
#include "subwayline.h"
#include "subwayCard.h"
#include "subwayCommand.h"

#if _SUBWAY_LLT
#include "gtest/gtest.h"
using namespace testing;
#endif

/*
@ ��ʼ�������շ�ϵͳ, ���ø���ģ��ĳ�ʼ������
*/
void InitSubwayCharge()
{
    InitCardManagerInfo();
    InitSubwayLine();
    InitSusbwaySocket(ProcCmdEnter);

    //Ԥ��Ĭ�ϵ�����·
    SetDefaultLine();
}

int _tmain(int argc, _TCHAR* argv[])
{
#if _SUBWAY_LLT
    //LLT�����н���DT
    printf("Running main()------------------ \n");
    testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    getchar();
    return result;
#else
    InitSubwayCharge();

    //�����ͻ��˵���������
    if(-1 == ListenAndAcceptClient())
    {
        return -1;
    }

    //ѭ�����տͻ��˵�������
    ReceiveCmdFlow();
#endif
	return 0;
}


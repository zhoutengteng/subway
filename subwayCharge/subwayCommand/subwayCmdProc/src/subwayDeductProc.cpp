#include "stdafx.h"
#include <iostream>
#include "subwayGlobalDef.h"
#include "subwayMacro.h"
#include "subwayCard.h"
#include "subwayline.h"
#include "subwayPrice.h"
#include "subwayCommon.h"
#include "subwayError.h"
#include "subwayCmdParse\subwayCmdParse.h"
#include "subwayOutput\subwayOutput.h"
using namespace std;

/*
@ ����۷�����
@ ��Σ�stCmdDeduct, ��������
@ ����: returnStr
@ ����ֵ: void
*/
void ProcDeductCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
    //���ݿ��Ż�ȡ����Ϣ  GetCardInfo

    //���ʱ���ʽ  CHECK_TIME

    //����˳�ʱ��  DIFF_TIME

    //���������  GetSubwayStationDis

    //����۷Ѽ۸� GetDeductPrice
     
    //�Գ˳������п۷� DeductCard

    

    //����ַ���
    //GetOutputResultStr(EN_CMD_TYPE_DEDUCT, returnCode, pCmdDeduct->cardNo, enCard, balance, returnStr);
    return;
}
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
@ ��ֵ����
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcFillChargeCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
    //��ȡ����Ϣ GetCardInfo

    //���г�ֵ RechargeCard

    //���ݳ�ֵ��Ŀ���Ϣ  GetCardInfo

    //����ַ���
    //GetOutputResultStr(EN_CMD_TYPE_FILL_CHARGE, returnCode, pCmdCharge->cardNo, enCard, balance, returnStr);

    return;
}
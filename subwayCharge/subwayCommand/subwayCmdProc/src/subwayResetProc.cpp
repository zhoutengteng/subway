#include "stdafx.h"
#include <iostream>
#include "subwayGlobalDef.h"
#include "subwayCard.h"
#include "subwayline.h"
#include "subwayPrice.h"
#include "subwayCommon.h"
#include "subwayError.h"
#include "subwayCmdParse\subwayCmdParse.h"
#include "subwayOutput\subwayOutput.h"
using namespace std;

/*
@ ����ϵͳ����
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcResetCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
    InitCardManagerInfo();
    //����ַ���
    GetOutputResultStr(EN_CMD_TYPE_RESET, EN_RETURN_SUCC, 0, EN_CARD_TYPE_BUTT, 0, returnStr);
    return;
}
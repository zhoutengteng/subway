#include "stdafx.h"
#include <iostream>
#include "subwayGlobalDef.h"
#include "subwayCard.h"
#include "subwayline.h"
#include "subwayCommon.h"
#include "subwayCmdParse\subwayCmdParse.h"
#include "subwayOutput\subwayOutput.h"
using namespace std;

/*
@ ��ѯ������
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcQueryLineCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
    //��ѯ���е����� GetLineInfo
	string tempStr;
	GetLineInfo(tempStr);
	memcpy_s(returnStr,MAX_SEND_BUFFER_LENGTH, tempStr.c_str(), tempStr.length());
	returnStr[tempStr.length()] = 0;
    return;
}
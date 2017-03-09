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
@ ������Ʊ
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcCreateSingleTicketCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
    //��ȡ����վ��������� GetSubwayStationDis
	unsigned int distanceBt = 0;
	EN_RETURN_CODE returnCode;
	int basePrice = -1;
	unsigned int cardNo = (unsigned int)(-1);
	do {
		returnCode = GetSubwayStationDis(unCmd.stCmdSingleTicket.srcStation, unCmd.stCmdSingleTicket.dstStation, distanceBt);
		IF_INVALID_BREAK(returnCode == EN_RETURN_SUCC);
		
		//��ȡ����վ���Ļ���Ʊ��  GetBasePrice
		basePrice = GetBasePrice(distanceBt);

		//�쵥�̿� AssignCard
		returnCode = AssignCard(cardNo, EN_CARD_TYPE_SINGLE, basePrice);
		IF_INVALID_BREAK(returnCode == EN_RETURN_SUCC);
	} while (false);
	//����ַ���
    GetOutputResultStr(EN_CMD_TYPE_SINGLE_TICKET, returnCode, cardNo, EN_CARD_TYPE_SINGLE, basePrice, returnStr);

    return;
}
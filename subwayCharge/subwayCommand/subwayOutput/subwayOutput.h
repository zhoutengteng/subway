#ifndef __SUBWAY_OUTPUT_H__
#define __SUBWAY_OUTPUT_H__
#include <sstream>
#include "subwayError.h"
#include "subwayCard.h"
#include "subwayCmdParse\subwayCmdParse.h"
using namespace std;

/*
@ ��������ַ���
@ ��Σ�
@ ����: oss, �ַ�����
@ ����ֵ: void
*/
void GetOutputResultStr(EN_CMD_TYPE enCmd, EN_RETURN_CODE enResult, unsigned int cardNo, EN_CARD_TYPE enCard, unsigned int balance, char returnStr[MAX_SEND_BUFFER_LENGTH]);

#endif
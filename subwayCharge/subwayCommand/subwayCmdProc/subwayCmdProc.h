#ifndef __SUBWAY_CONTROL_H__
#define __SUBWAY_CONTROL_H__
#include "subwayGlobalDef.h"
/*
@ �����������
@ ��Σ�cmdStr, ��������
@ ����: returnStr, ��������
@ ����ֵ: ��
*/
void ProcCmdEnter(const char cmdStr[MAX_RECEIVE_BUFFER_LENGTH], char returnStr[MAX_SEND_BUFFER_LENGTH]);

#endif
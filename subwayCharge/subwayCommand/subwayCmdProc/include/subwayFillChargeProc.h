#ifndef __CMD_FILL_CHARGE_PROC_H__
#define __CMD_FILL_CHARGE_PROC_H__
#include "subwayGlobalDef.h"
#include "subwayCmdParse/subwayCmdParse.h"

/*
@ ��ֵ����
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcFillChargeCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH]);

#endif
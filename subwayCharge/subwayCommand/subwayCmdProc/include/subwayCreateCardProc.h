#ifndef __CMD_CREATE_CARD_PROC_H__
#define __CMD_CREATE_CARD_PROC_H__
#include "subwayGlobalDef.h"
#include "subwayCmdParse/subwayCmdParse.h"

/*
@ ������ͨ��
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcCreateCardCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH]);
#endif



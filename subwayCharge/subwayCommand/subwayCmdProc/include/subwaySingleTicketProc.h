#ifndef __CMD_SINGLE_TICKET_PROC_H__
#define __CMD_SINGLE_TICKET_PROC_H__
#include "subwayGlobalDef.h"
#include "subwayCmdParse/subwayCmdParse.h"

/*
@ ������Ʊ
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcCreateSingleTicketCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH]);

#endif
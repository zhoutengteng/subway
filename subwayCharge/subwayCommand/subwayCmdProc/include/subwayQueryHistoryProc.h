#ifndef __CMD_QUERY_HISTORY_PROC_H__
#define __CMD_QUERY_HISTORY_PROC_H__
#include "subwayGlobalDef.h"
#include "subwayCmdParse/subwayCmdParse.h"

/*
@ ��ѯ��ʷ���Ѽ�¼
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcQueryHistoryCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH]);

#endif
#ifndef __CMD_QUERY_LINE_PROC_H__
#define __CMD_QUERY_LINE_PROC_H__
#include "subwayGlobalDef.h"
#include "subwayCmdParse/subwayCmdParse.h"

/*
@ ��ѯ������
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcQueryLineCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH]);

#endif
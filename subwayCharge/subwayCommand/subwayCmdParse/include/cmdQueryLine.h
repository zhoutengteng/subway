#ifndef __CMD_QUERY_LINE_H__
#define __CMD_QUERY_LINE_H__
#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//�����е�ÿ����Ԫ
typedef enum
{
    EN_CMD_QUERY_LINE_CMD_CODE = 0,
    EN_CMD_QUERY_LINE_BUTT
}EN_CMD_QUERY_LINE_ELEMENT;

//�����۷�����
int parseCmdQueryLine(string &cmd, void* pStCmd);

//��ӡ�������
void printfCmdQueryLine(ST_CMD_QUERY_LINE &pCmdSingleTicket);

#endif
#ifndef __CMD_RESET_H__
#define __CMD_RESET_H__
#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//�����е�ÿ����Ԫ
typedef enum
{
    EN_CMD_RESET_CMD_CODE = 0,
    EN_CMD_RESET_CMD_BUTT
}EN_CMD_RESET_CMD_ELEMENT;

//�����۷�����
int parseCmdReset(string &cmd, void* pStCmd);

//��ӡ�������
void printfCmdReset(ST_CMD_RESET &pCmdReset);

#endif
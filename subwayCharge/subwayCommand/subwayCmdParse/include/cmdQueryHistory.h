#ifndef __CMD_QUERY_HIS_H__
#define __CMD_QUERY_HIS_H__
#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//�����е�ÿ����Ԫ
typedef enum
{
    EN_CMD_QUERY_HIS_CMD_CODE = 0,
    EN_CMD_QUERY_HIS_CARD_NO,
    EN_CMD_QUERY_HIS_BUTT
}EN_CMD_QUERY_HIS_ELEMENT;

//�����۷�����
int parseCmdQueHistory(string &cmd, void* pStCmd);

//��ӡ�������
void printfCmdQueHistory(ST_CMD_QUERY_HIS &stCmd);

#endif
#ifndef __CMD_EXPENDITURE_DIS_H__
#define __CMD_EXPENDITURE_DIS_H__

#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//�����е�ÿ����Ԫ
typedef enum
{
    EN_CMD_EXPENDITURE_DIS_CMD_CODE = 0,
    EN_CMD_EXPENDITURE_DIS_BUTT
}EN_CMD_EXPENDITURE_DIS_ELEMENT;

//�����۷�����
int parseCmdExpenditureDis(string &cmd, void* pStCmd);

//��ӡ�������
void printfCmdExpenditureDis(ST_CMD_EXPENDITURE_DIS &stExpenditureDis);


#endif
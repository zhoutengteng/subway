#ifndef __CMD_FILL_CHARGE_H__
#define __CMD_FILL_CHARGE_H__
#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//�����е�ÿ����Ԫ
typedef enum
{
    EN_CMD_FILL_CHARGE_CMD_CODE = 0,
    EN_CMD_FILL_CHARGE_CARDNO,
    EN_CMD_FILL_CHARGE_CHARGE,
    EN_CMD_FILL_CHARGE_BUTT
}EN_CMD_FILL_CHARGE_ELEMENT;

//�����۷�����
int parseCmdFillCharge(string &cmd, void* pStCmd);

//��ӡ�������
void printfCmdFillCharge(ST_CMD_FILL_CHARGE &stCmdFillCharge);

//���뺯������
int cmdFillChargeParse(void* outPut, string* str);

#endif
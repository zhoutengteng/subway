#ifndef __CMD_PASSENGER_DIS_H__
#define __CMD_PASSENGER_DIS_H__

#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//�����е�ÿ����Ԫ
typedef enum
{
    EN_CMD_PASSENGER_DIS_CMD_CODE = 0,
    EN_CMD_PASSENGER_DIS_BUTT
}EN_CMD_PASSENGER_DIS_ELEMENT;

//�����۷�����
int parseCmdPassengerDis(string &cmd, void* pStCmd);

//��ӡ�������
void printfCmdPassengerDis(ST_CMD_PASSENGER_DIS &stPassengerDis);

#endif
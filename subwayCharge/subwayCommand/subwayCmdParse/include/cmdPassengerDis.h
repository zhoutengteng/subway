#ifndef __CMD_PASSENGER_DIS_H__
#define __CMD_PASSENGER_DIS_H__

#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//命令中的每个信元
typedef enum
{
    EN_CMD_PASSENGER_DIS_CMD_CODE = 0,
    EN_CMD_PASSENGER_DIS_BUTT
}EN_CMD_PASSENGER_DIS_ELEMENT;

//解析扣费命令
int parseCmdPassengerDis(string &cmd, void* pStCmd);

//打印解析结果
void printfCmdPassengerDis(ST_CMD_PASSENGER_DIS &stPassengerDis);

#endif
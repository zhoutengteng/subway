#ifndef __CMD_EXPENDITURE_DIS_H__
#define __CMD_EXPENDITURE_DIS_H__

#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//命令中的每个信元
typedef enum
{
    EN_CMD_EXPENDITURE_DIS_CMD_CODE = 0,
    EN_CMD_EXPENDITURE_DIS_BUTT
}EN_CMD_EXPENDITURE_DIS_ELEMENT;

//解析扣费命令
int parseCmdExpenditureDis(string &cmd, void* pStCmd);

//打印解析结果
void printfCmdExpenditureDis(ST_CMD_EXPENDITURE_DIS &stExpenditureDis);


#endif
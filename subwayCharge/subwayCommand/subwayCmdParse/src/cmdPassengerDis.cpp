#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdPassengerDis.h"
using namespace std;

//命令的正则表达式，用于检查命令格式是否正确
string g_cmdPassengerDisPattern("^[ ]{0,}[pP]{1}[ ]{0,}$"); 


//解码函数列表
ELEMENT_FUNC g_cmdPassengerFunc[EN_CMD_PASSENGER_DIS_BUTT] = 
{
    cmdCmdParse<ST_CMD_PASSENGER_DIS>
};

//解析扣费命令
int parseCmdPassengerDis(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_EXPENDITURE_DIS>(cmd, pStCmd, g_cmdPassengerDisPattern, g_cmdPassengerFunc);
    
    if(0 == intValue)
    {
        printfCmdPassengerDis(*((ST_CMD_EXPENDITURE_DIS*)pStCmd));
    }
    return intValue;
}

//打印解析结果
void printfCmdPassengerDis(ST_CMD_PASSENGER_DIS &stPassengerDis)
{
    cout<<"CMD:                 "<<stPassengerDis.cmd<<endl;
}
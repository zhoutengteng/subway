#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdExpenditureDis.h"
using namespace std;


//命令的正则表达式，用于检查命令格式是否正确
string g_cmdExpenditureDisPattern("^[ ]{0,}[eE]{1}[ ]{0,}$"); 


//解码函数列表
ELEMENT_FUNC g_cmdExpenditureFunc[EN_CMD_EXPENDITURE_DIS_BUTT] = 
{
    cmdCmdParse<ST_CMD_EXPENDITURE_DIS>
};

//解析命令
int parseCmdExpenditureDis(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_EXPENDITURE_DIS>(cmd, pStCmd, g_cmdExpenditureDisPattern, g_cmdExpenditureFunc);
    
    if(0 == intValue)
    {
        printfCmdExpenditureDis(*((ST_CMD_EXPENDITURE_DIS*)pStCmd));
    }
    return intValue;
}

//打印解析结果
void printfCmdExpenditureDis(ST_CMD_EXPENDITURE_DIS &stExpenditureDis)
{
    cout<<"CMD:                 "<<stExpenditureDis.cmd<<endl;
}
#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdExpenditureDis.h"
using namespace std;


//�����������ʽ�����ڼ�������ʽ�Ƿ���ȷ
string g_cmdExpenditureDisPattern("^[ ]{0,}[eE]{1}[ ]{0,}$"); 


//���뺯���б�
ELEMENT_FUNC g_cmdExpenditureFunc[EN_CMD_EXPENDITURE_DIS_BUTT] = 
{
    cmdCmdParse<ST_CMD_EXPENDITURE_DIS>
};

//��������
int parseCmdExpenditureDis(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_EXPENDITURE_DIS>(cmd, pStCmd, g_cmdExpenditureDisPattern, g_cmdExpenditureFunc);
    
    if(0 == intValue)
    {
        printfCmdExpenditureDis(*((ST_CMD_EXPENDITURE_DIS*)pStCmd));
    }
    return intValue;
}

//��ӡ�������
void printfCmdExpenditureDis(ST_CMD_EXPENDITURE_DIS &stExpenditureDis)
{
    cout<<"CMD:                 "<<stExpenditureDis.cmd<<endl;
}
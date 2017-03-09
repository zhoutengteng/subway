#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdPassengerDis.h"
using namespace std;

//�����������ʽ�����ڼ�������ʽ�Ƿ���ȷ
string g_cmdPassengerDisPattern("^[ ]{0,}[pP]{1}[ ]{0,}$"); 


//���뺯���б�
ELEMENT_FUNC g_cmdPassengerFunc[EN_CMD_PASSENGER_DIS_BUTT] = 
{
    cmdCmdParse<ST_CMD_PASSENGER_DIS>
};

//�����۷�����
int parseCmdPassengerDis(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_EXPENDITURE_DIS>(cmd, pStCmd, g_cmdPassengerDisPattern, g_cmdPassengerFunc);
    
    if(0 == intValue)
    {
        printfCmdPassengerDis(*((ST_CMD_EXPENDITURE_DIS*)pStCmd));
    }
    return intValue;
}

//��ӡ�������
void printfCmdPassengerDis(ST_CMD_PASSENGER_DIS &stPassengerDis)
{
    cout<<"CMD:                 "<<stPassengerDis.cmd<<endl;
}
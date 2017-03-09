#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdReset.h"
using namespace std;

//����ϵͳ��������ʽ�����ڼ�������ʽ�Ƿ���ȷ
string g_cmdResetPattern("^[ ]{0,}[rR]{1}[ ]{0,}$"); 

//�۷��������Ԫ���뺯���б�
ELEMENT_FUNC g_cmdResetFunc[EN_CMD_RESET_CMD_BUTT] = 
{
    cmdCmdParse<ST_CMD_RESET>
};

//��ѯ��·����
int parseCmdReset(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_RESET>(cmd, pStCmd, g_cmdResetPattern, g_cmdResetFunc);
    
    if(0 == intValue)
    {
        printfCmdReset(*((ST_CMD_RESET*)pStCmd));
    }
    return intValue;
}

//��ӡ�������
void printfCmdReset(ST_CMD_RESET &stReset)
{
    cout<<"CMD:                 "<<stReset.cmd<<endl;
}
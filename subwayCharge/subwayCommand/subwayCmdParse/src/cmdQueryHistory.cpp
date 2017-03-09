#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdQueryHistory.h"
using namespace std;


//���򵥳�Ʊ�����������ʽ�����ڼ�������ʽ�Ƿ���ȷ
string g_cmdQueHistoryPattern("^[ ]{0,}[hH]{1}[ ]{1}[0-9]{1,}[ ]{0,}$"); 


//�۷��������Ԫ���뺯���б�
ELEMENT_FUNC g_cmdQueHistoryFunc[EN_CMD_QUERY_HIS_BUTT] = 
{
    cmdCmdParse<ST_CMD_QUERY_HIS>,
    cmdCardNoParse<ST_CMD_QUERY_HIS>,
};

//ʹ��������ʽ��������Ƿ���Ϲ淶
int checkQueHistory(string &cmd)
{
    return checkCmd(cmd, g_cmdQueHistoryPattern);
}

//�����۷�����
int parseCmdQueHistory(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_QUERY_HIS>(cmd, pStCmd, g_cmdQueHistoryPattern, g_cmdQueHistoryFunc);
    
    if(0 == intValue)
    {
        printfCmdQueHistory(*((ST_CMD_QUERY_HIS*)pStCmd));
    }
    return intValue;
}

//��ӡ�������
void printfCmdQueHistory(ST_CMD_QUERY_HIS &stQueHistory)
{
    cout<<"CMD:                 "<<stQueHistory.cmd<<endl;
    cout<<"cardNo:              "<<stQueHistory.cardNo<<endl;
}


#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdQueryLine.h"
using namespace std;

//��ѯ��·��������ʽ�����ڼ�������ʽ�Ƿ���ȷ
string g_cmdQueLinePattern("^[ ]{0,}[lL]{1}[ ]{0,}$"); 


//�۷��������Ԫ���뺯���б�
ELEMENT_FUNC g_cmdQueLineFunc[EN_CMD_QUERY_LINE_BUTT] = 
{
    cmdCmdParse<ST_CMD_QUERY_LINE>
};

//��ѯ��·����
int parseCmdQueryLine(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_QUERY_LINE>(cmd, pStCmd, g_cmdQueLinePattern, g_cmdQueLineFunc);
    
    if(0 == intValue)
    {
        printfCmdQueryLine(*((ST_CMD_QUERY_LINE*)pStCmd));
    }
    return intValue;
}

//��ӡ�������
void printfCmdQueryLine(ST_CMD_QUERY_LINE &stQueLine)
{
    cout<<"CMD:                 "<<stQueLine.cmd<<endl;
}

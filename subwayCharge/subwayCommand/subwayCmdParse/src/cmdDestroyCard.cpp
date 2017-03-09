#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdDestroyCard.h"
using namespace std;


//���򵥳�Ʊ�����������ʽ�����ڼ�������ʽ�Ƿ���ȷ
string g_cmdDesCardPattern("^[ ]{0,}[dD]{1}[ ]{1}[0-9]{1,}[ ]{0,}$"); 


//�۷��������Ԫ���뺯���б�
ELEMENT_FUNC g_cmdDesCardFunc[EN_CMD_DESTROY_CARD_BUTT] = 
{
    cmdCmdParse<ST_CMD_DESTROY_CARD>,
    cmdCardNoParse<ST_CMD_DESTROY_CARD>,
};

//�����۷�����
int parseCmdDesCard(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_DESTROY_CARD>(cmd, pStCmd, g_cmdDesCardPattern, g_cmdDesCardFunc);
    
    if(0 == intValue)
    {
        printfCmdDesCard(*((ST_CMD_DESTROY_CARD*)pStCmd));
    }
    return intValue;
}

//��ӡ�������
void printfCmdDesCard(ST_CMD_DESTROY_CARD &stDesCard)
{
    cout<<"CMD:                 "<<stDesCard.cmd<<endl;
    cout<<"cardNo:              "<<stDesCard.cardNo<<endl;
}


#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdCreateCard.h"
using namespace std;

//����˳��������������ʽ�����ڼ�������ʽ�Ƿ���ȷ
string g_cmdCreateCardPattern("^[ ]{0,}[bB]{1}[ ]{1}[a-zA-Z]{1}[ ]{1}[0-9]{1,}[ ]{0,}$"); 


//�۷��������Ԫ���뺯���б�
ELEMENT_FUNC g_cmdCreateCardFunc[EN_CMD_CREATE_CARD_BUTT] = 
{
    cmdCmdParse<ST_CMD_CREATE_CARD>,
    cmdCardTypeParse<ST_CMD_CREATE_CARD>,
    cmdCreateCardChargeParse
};


//����۷������е�Ԥ��ֵ���
int cmdCreateCardChargeParse(void* outPut, string* str)
{
    CHECK_INPUT_PARA(outPut, str);

    ST_CMD_CREATE_CARD* Cmd = (ST_CMD_CREATE_CARD*)outPut;
    return cmdChargeParse(&(Cmd->cardCharge), str);
}

//����۷�����
int parseCmdCreateCard(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_CREATE_CARD>(cmd, pStCmd, g_cmdCreateCardPattern, g_cmdCreateCardFunc);

    if(0 == intValue)
    {
        printfCmdCreateCard(*((ST_CMD_CREATE_CARD*)pStCmd));
    }
    return intValue;
}

//��ӡ�����Ŀ۷�����
void printfCmdCreateCard(ST_CMD_CREATE_CARD &stCmdCreateCard)
{
    cout<<"CMD:                 "<<stCmdCreateCard.cmd<<endl;
    cout<<"CardType:            "<<stCmdCreateCard.cardType<<endl;
    cout<<"cardCharge:          "<<stCmdCreateCard.cardCharge<<endl;
}
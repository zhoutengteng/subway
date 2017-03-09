#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdSingleTicket.h"
using namespace std;


//���򵥳�Ʊ�����������ʽ�����ڼ�������ʽ�Ƿ���ȷ
string g_cmdSingleTicketPattern("^[ ]{0,}[sS]{1}[ ]{1}[sS]{1}[0-9]{1,}[ ]{1}[sS]{1}[0-9]{1,}[ ]{0,}$"); 


//�۷��������Ԫ���뺯���б�
ELEMENT_FUNC g_cmdSingleTicketFunc[EN_CMD_SINGLE_TICKET_BUTT] = 
{
    cmdCmdParse<ST_CMD_SINGLE_TICKET>,
    cmdSingleTicketSrcStationParse,
    cmdSingleTicketDstStationParse,
};

//�����վվ������
int cmdSingleTicketSrcStationParse(void* outPut, string* str)
{
    CHECK_INPUT_PARA(outPut, str);

    ST_CMD_SINGLE_TICKET* deductCmd = (ST_CMD_SINGLE_TICKET*)outPut;
    return cmdStationParse(deductCmd->srcStation, str);
}

//�����վվ������
int cmdSingleTicketDstStationParse(void* outPut, string* str)
{
    CHECK_INPUT_PARA(outPut, str);

    ST_CMD_SINGLE_TICKET* deductCmd = (ST_CMD_SINGLE_TICKET*)outPut;
    return cmdStationParse(deductCmd->dstStation, str);
}

//����۷�����
int parseCmdSingleTicket(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_SINGLE_TICKET>(cmd, pStCmd, g_cmdSingleTicketPattern, g_cmdSingleTicketFunc);
    
    if(0 == intValue)
    {
        printfCmdSingleTicket(*((ST_CMD_SINGLE_TICKET*)pStCmd));
    }
    return intValue;
}


//��ӡ�����Ŀ۷�����
void printfCmdSingleTicket(ST_CMD_SINGLE_TICKET &stCmdSingleTicket)
{
    cout<<"CMD:                 "<<stCmdSingleTicket.cmd<<endl;
    cout<<"srcStation:          "<<stCmdSingleTicket.srcStation<<endl;
    cout<<"dstStation:          "<<stCmdSingleTicket.dstStation<<endl;
}
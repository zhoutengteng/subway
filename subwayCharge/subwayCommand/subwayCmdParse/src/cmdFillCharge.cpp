#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdFillCharge.h"
using namespace std;


//���򵥳�Ʊ�����������ʽ�����ڼ�������ʽ�Ƿ���ȷ
string g_cmdFillChargePattern("^[ ]{0,}[fF]{1}[ ]{1}[0-9]{1,}[ ]{1}[0-9]{1,}[ ]{0,}$"); 


//�۷��������Ԫ���뺯���б�
ELEMENT_FUNC g_cmdFillChargeFunc[EN_CMD_FILL_CHARGE_BUTT] = 
{
    cmdCmdParse<ST_CMD_FILL_CHARGE>,
    cmdCardNoParse<ST_CMD_FILL_CHARGE>,
    cmdFillChargeParse
};

//���뺯��
int cmdFillChargeParse(void* outPut, string* str)
{
    CHECK_INPUT_PARA(outPut, str);

    ST_CMD_FILL_CHARGE* Cmd = (ST_CMD_FILL_CHARGE*)outPut;
    return cmdChargeParse(&(Cmd->cardCharge), str);
}

//�����۷�����
int parseCmdFillCharge(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_FILL_CHARGE>(cmd, pStCmd, g_cmdFillChargePattern, g_cmdFillChargeFunc);
    
    if(0 == intValue)
    {
        printfCmdFillCharge(*((ST_CMD_FILL_CHARGE*)pStCmd));
    }
    return intValue;
}

//��ӡ�������
void printfCmdFillCharge(ST_CMD_FILL_CHARGE &stCmdFillCharge)
{
    cout<<"CMD:                 "<<stCmdFillCharge.cmd<<endl;
    cout<<"cardNo:              "<<stCmdFillCharge.cardNo<<endl;
    cout<<"cardCharge:          "<<stCmdFillCharge.cardCharge<<endl;
}


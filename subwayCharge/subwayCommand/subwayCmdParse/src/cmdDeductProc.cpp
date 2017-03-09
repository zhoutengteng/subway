#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdDeductProc.h"
using namespace std;

//�۷��������Ԫ���뺯���б�
ELEMENT_FUNC g_cmdDeductFunc[EN_CMD_DEDUCT_BUTT] = 
{
    cmdCmdParse<ST_CMD_DEDUCT>,
    cmdCardNoParse<ST_CMD_DEDUCT>,
    cmdDeductEnterTimeParse,
    cmdDeductEnterStationParse,
    cmdDeductExitTimeParse,
    cmdDeductExitStationParse
};

//�۷������������ʽ�����ڼ�������ʽ�Ƿ���ȷ
string g_cmdDeductPattern("^[ ]{0,}[cC]{1}[ ]{1}[0-9]{1,}[ ]{1}[0-9]{1,2}[:]{1}[0-9]{1,2}[ ]{1}[sS]{1}[0-9]{1,}[ ]{1}[0-9]{1,2}[:]{1}[0-9]{1,2}[ ]{1}[sS]{1}[0-9]{1,}[ ]{0,}$"); 

//�����վʱ��
int cmdDeductEnterTimeParse(void* outPut, string* str)
{
    CHECK_INPUT_PARA(outPut, str);

    ST_CMD_DEDUCT* deductCmd = (ST_CMD_DEDUCT*)outPut;
    return cmdTimeParse(&(deductCmd->enterTime), str);
}

//�����վվ��
int cmdDeductEnterStationParse(void* outPut, string* str)
{
    CHECK_INPUT_PARA(outPut, str);

    ST_CMD_DEDUCT* deductCmd = (ST_CMD_DEDUCT*)outPut;
    return cmdStationParse(deductCmd->enterStation, str);
}

//�����վʱ��
int cmdDeductExitTimeParse(void* outPut, string* str)
{
    CHECK_INPUT_PARA(outPut, str);

    ST_CMD_DEDUCT* deductCmd = (ST_CMD_DEDUCT*)outPut;
    return cmdTimeParse(&(deductCmd->exitTime), str);
}

//�����վվ��
int cmdDeductExitStationParse(void* outPut, string* str)
{
    CHECK_INPUT_PARA(outPut, str);

    ST_CMD_DEDUCT* deductCmd = (ST_CMD_DEDUCT*)outPut;
    return cmdStationParse(deductCmd->exitStation, str);
}

//����۷�����
int parseCmdDeduct(string &cmd, void* pStCmd)
{
    /*lint --e(1036)*/int intValue = parseCmd<ST_CMD_DEDUCT>(cmd, pStCmd, g_cmdDeductPattern, g_cmdDeductFunc);
    if(0 == intValue)
    {
        printfCmdDeduct(*((ST_CMD_DEDUCT*)pStCmd));
    }
    return intValue;
}

//��ӡ�����Ŀ۷�����
void printfCmdDeduct(ST_CMD_DEDUCT &stCmdDeduct)
{
    cout<<"CMD:                 "<<stCmdDeduct.cmd<<endl;
    cout<<"cardNo:              "<<stCmdDeduct.cardNo<<endl;
    cout<<"enterTime:           "<<stCmdDeduct.enterTime.hour<<":"<<stCmdDeduct.enterTime.minutes<<endl;
    cout<<"enterStation:        "<<stCmdDeduct.enterStation<<endl;
    cout<<"exitTime:            "<<stCmdDeduct.exitTime.hour<<":"<<stCmdDeduct.exitTime.minutes<<endl;
    cout<<"exitStation:         "<<stCmdDeduct.exitStation<<endl;
}
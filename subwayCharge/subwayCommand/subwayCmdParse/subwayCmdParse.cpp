#include "stdafx.h"
#include <iostream>
#include "subwayCmdParse/include/cmdGlobal.h"
#include "subwayCmdParse/include/cmdDeductProc.h"
#include "subwayCmdParse/include/cmdSingleTicket.h"
#include "subwayCmdParse/include/cmdCreateCard.h"
#include "subwayCmdParse/include/cmdFillCharge.h"
#include "subwayCmdParse/include/cmdQueryHistory.h"
#include "subwayCmdParse/include/cmdDestroyCard.h"
#include "subwayCmdParse/include/cmdQueryLine.h"
#include "subwayCmdParse/include/cmdReset.h"
#include "subwayCmdParse/include/cmdExpenditureDis.h"
#include "subwayCmdParse/include/cmdPassengerDis.h"
using namespace std;

CMD_DECODE_FUNC g_cmdDecodeFunc[EN_CMD_TYPE_BUTT] = 
{
    parseCmdDeduct,
    parseCmdSingleTicket,
    parseCmdCreateCard,
    parseCmdFillCharge,
    parseCmdQueHistory,
    parseCmdDesCard,
    parseCmdQueryLine,
    NULL,
    parseCmdReset,
    parseCmdExpenditureDis,
    parseCmdPassengerDis
};

//��������
char g_CmdReturn[EN_CMD_TYPE_BUTT][64] = 
{
    "�˳����۷�",
    "���򵥳�Ʊ",
    "����˳���",
    "�˳�����ֵ",
    "��ѯ���Ѽ�¼",
    "ע���˳���",
    "��ѯ������·",
    "�Ƿ�����",
    "����ϵͳ",
    "��ѯ���Ѷ�ȷֲ�",
    "��ѯ�˳������ֲ�"
};

//��������
int cmdParse(ST_COMM_CMD &stCommCmd, const char* cmdStr)
{
    if(NULL == cmdStr)
    {
        return -1;
    }

    string strCmd(cmdStr);

    for(int i = 0; i < EN_CMD_TYPE_BUTT; i++)
    {
        if(NULL == g_cmdDecodeFunc[i])
        {
            continue;
        }

        if(0 == g_cmdDecodeFunc[i](strCmd, (void*)&(stCommCmd.unCmd)))
        {
            stCommCmd.enCmdType = (EN_CMD_TYPE)i;
            return 0;
        }
    }

    cout<<"The Command parse err! cmd="<<cmdStr<<endl;
    return -1;
}

//��ȡ���������ַ���
char* GetCmdNameStr(EN_CMD_TYPE enCmd)
{
    return g_CmdReturn[enCmd];
}
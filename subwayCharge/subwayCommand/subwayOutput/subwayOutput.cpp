#include "stdafx.h"
#include <sstream>
#include "subwayOutput.h"
using namespace std;

//��ѡ������ֶ�
enum
{
    EN_OUTPUT_CARD_NO = 0,
    EN_OUTPUT_CARD_TYPE,
    EN_OUTPUT_BALANCE,
    EN_OUTPUT_BUTT
};

//��ѡ����ֶ�����
char g_outputElement[EN_OUTPUT_BUTT][64] = 
{
    "����",
    "������",
    "���"
};

//ÿ������Ŀ�ѡ����ֶε�bitMap
typedef enum
{
    EN_BITMAP_TYPE_SUCC = 0,
    EN_BITMAP_TYPE_FAIL,
    EN_BITMAP_TYPE_BUTT
}EN_BITMAP_TYPE;

typedef struct
{
    unsigned int bitMap[EN_BITMAP_TYPE_BUTT];
}ST_OUTPUT_BIT;

/*
    ÿ������Ŀ�ѡ����ֶε�bitMap
    bit32~bit0: 
    bit0: ����;     bit2: ������;      bit3�� ���;   bit3�� ���Ѽ�¼
    other��Ŀǰ��δ�õ�

    EN_CMD_TYPE_DEDUCT = 0,
    EN_CMD_TYPE_SINGLE_TICKET,
    EN_CMD_TYPE_CREATE_CARD,
    EN_CMD_TYPE_FILL_CHARGE,
    EN_CMD_TYPE_QUERY_HIS,
    EN_CMD_TYPE_DESTROY_CARD,
    EN_CMD_TYPE_QUERY_LINE,
    EN_CMD_TYPE_INVALID_CMD,
    EN_CMD_TYPE_BUTT
*/
ST_OUTPUT_BIT g_CmdOutputBitmap[EN_CMD_TYPE_BUTT] = 
{
    /*lint --e(651)*/{0x7, 0x7}, {0x7, 0x0}, {0x7, 0x0}, {0x7, 0x3}, {0xB, 0x1}, {0x3,0x1}, {0x0, 0x0}, {0x0, 0x0}, {0x0, 0x0}
};

#define CHECK_BITMAP(cmd, type, bitType) ((0x1 << (type)) & (g_CmdOutputBitmap[(cmd)].bitMap[(bitType)]))

#define SET_OUTSTR(cmd, type, bitType, oss, str)\
    if(0 != CHECK_BITMAP(cmd, type, bitType))\
    {\
        oss<<"<"<<g_outputElement[(type)]<<"="<<str<<">";\
    }


/*
@ ��������ַ���
@ ��Σ�
@       enCmd:      �����
@       enResult:   �������
@       cardNo:     ����
@       balance:    ���
@ ����: returnStr:  ����ַ���
@ ����ֵ: void
*/
void GetOutputResultStr(EN_CMD_TYPE enCmd, EN_RETURN_CODE enResult, unsigned int cardNo, EN_CARD_TYPE enCard, unsigned int balance, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
    EN_BITMAP_TYPE bitType = EN_BITMAP_TYPE_SUCC;
    ostringstream oss;

    oss<<GetCmdNameStr(enCmd);
    string errStr;

    switch(enResult)
    {
        case EN_RETURN_SUCC:
            oss<<"<�ɹ�>";
            errStr = "";
            bitType = EN_BITMAP_TYPE_SUCC;
            break;
        case EN_RETURN_BALANCE_TOO_LOW:
            oss<<"<�ɹ�>";
            /*lint --e(1023)*//*lint --e(1703)*/errStr = "<����=" + string(GetErrStr(enResult)) + ">";
            bitType = EN_BITMAP_TYPE_SUCC;
            break;
        default:
            oss<<"<ʧ��>";
            /*lint --e(1023)*//*lint --e(1703)*/errStr = "<ʧ��ԭ��=" + string(GetErrStr(enResult)) + ">";
            bitType = EN_BITMAP_TYPE_FAIL;
            break;
    }

    SET_OUTSTR(enCmd, EN_OUTPUT_CARD_NO, bitType, oss, cardNo)
    SET_OUTSTR(enCmd, EN_OUTPUT_CARD_TYPE, bitType, oss, GetCardTypeStr(enCard))
    SET_OUTSTR(enCmd, EN_OUTPUT_BALANCE, bitType, oss, balance)

    if(EN_RETURN_SUCC != enResult)
    {
        oss<<errStr.c_str();
    }

    string resultStr = oss.str();
    memcpy_s(returnStr, MAX_SEND_BUFFER_LENGTH, resultStr.c_str(), resultStr.length());
    returnStr[resultStr.length()] = 0;
}
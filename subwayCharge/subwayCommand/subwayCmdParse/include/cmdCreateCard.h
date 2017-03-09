#ifndef __CMD_CREATE_CARD_H__
#define __CMD_CREATE_CARD_H__
#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//�����е�ÿ����Ԫ
typedef enum
{
    EN_CMD_CREATE_CARD_CMD_CODE = 0,
    EN_CMD_CREATE_CARD_TYPE,
    EN_CMD_CREATE_CARD_CHARGE,
    EN_CMD_CREATE_CARD_BUTT
}EN_CMD_CREATE_CARD_ELEMENT;

//�����۷�����
int parseCmdCreateCard(string &cmd, void* pStCmd);

//��ӡ�������
void printfCmdCreateCard(ST_CMD_CREATE_CARD &stCmdCreateCard);

//���뺯������
int cmdCreateCardChargeParse(void* outPut, string* str);

#endif
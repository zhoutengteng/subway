#ifndef __CMD_DESTROY_CARD_H__
#define __CMD_DESTROY_CARD_H__
#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//�����е�ÿ����Ԫ
typedef enum
{
    EN_CMD_DESTROY_CARD_CMD_CODE = 0,
    EN_CMD_DESTROY_CARD_CARD_NO,
    EN_CMD_DESTROY_CARD_BUTT
}EN_CMD_DESTROY_CARD_ELEMENT;

//�����۷�����
int parseCmdDesCard(string &cmd, void* pStCmd);

//��ӡ�������
void printfCmdDesCard(ST_CMD_DESTROY_CARD &stDesCard);


#endif
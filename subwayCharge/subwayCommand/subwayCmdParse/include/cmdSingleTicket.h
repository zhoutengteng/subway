#ifndef __CMD_SINGLE_TICKET_H__
#define __CMD_SINGLE_TICKET_H__
#include <string>
#include "subwayCmdParse/include/cmdGlobal.h"

//�����е�ÿ����Ԫ
typedef enum
{
    EN_CMD_SINGLE_TICKET_CMD_CODE = 0,
    EN_CMD_SINGLE_TICKET_SRC_STATION,
    EN_CMD_SINGLE_TICKET_DST_STATION,
    EN_CMD_SINGLE_TICKET_BUTT
}EN_CMD_SINGLE_TICKET_ELEMENT;

//�����۷�����
int parseCmdSingleTicket(string &cmd, void* pStCmd);

//��ӡ�������
void printfCmdSingleTicket(ST_CMD_SINGLE_TICKET &pCmdSingleTicket);

//���뺯������
int cmdSingleTicketDstStationParse(void* outPut, string* str);
int cmdSingleTicketSrcStationParse(void* outPut, string* str);
#endif
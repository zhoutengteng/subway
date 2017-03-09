#ifndef __SUBWAY_SOCKET_H__
#define __SUBWAY_SOCKET_H__
#include "subwayGlobalDef.h"
#include "subwayMacro.h"

typedef void (*CMD_PROC_ENTER_FUNC)(const char cmdStr[MAX_RECEIVE_BUFFER_LENGTH], char returnStr[MAX_SEND_BUFFER_LENGTH]);

/*
@ ��ʼ��Socketͨ�Ż���
*/
void InitSusbwaySocket(CMD_PROC_ENTER_FUNC func);

/*
@ ��ʼ������socket����������
@ ����ֵ: 0, �ɹ�; -1, ʧ�ܣ�
*/
int ListenAndAcceptClient();

/*
@ ���տͻ��˵�����, ��������Ϣ����ӿڽ��д���
@ ����ֵ: void
*/
void ReceiveCmdFlow();

#endif
#ifndef __SUBWAY_CMD_PARSE_H__
#define __SUBWAY_CMD_PARSE_H__
#include "subwayGlobalDef.h"

#define MAX_CMD_LENGTH 4
#define MAX_CARD_TYPE_LENGTH 4
#define MAX_STATION_NAME_LENGTH 32

/*******************************ͨ������************************************************************/
//��������ö��
typedef enum
{
    EN_CMD_TYPE_DEDUCT = 0,
    EN_CMD_TYPE_SINGLE_TICKET,
    EN_CMD_TYPE_CREATE_CARD,
    EN_CMD_TYPE_FILL_CHARGE,
    EN_CMD_TYPE_QUERY_HIS,
    EN_CMD_TYPE_DESTROY_CARD,
    EN_CMD_TYPE_QUERY_LINE,
    EN_CMD_TYPE_INVALID_CMD,
    EN_CMD_TYPE_RESET,
    EN_CMD_TYPE_EXPENDITURE_DIS,
    EN_CMD_TYPE_PASSENGER_DIS,
    EN_CMD_TYPE_BUTT
}EN_CMD_TYPE;

/*******************************������ṹ************************************************************/
//�۷�����
typedef struct
{
    char cmd[MAX_CMD_LENGTH];
    int cardNo;
    ST_SUBWAY_TIME enterTime;
    char enterStation[MAX_STATION_NAME_LENGTH];
    ST_SUBWAY_TIME exitTime;
    char exitStation[MAX_STATION_NAME_LENGTH];
}ST_CMD_DEDUCT;

//�����̿�����
typedef struct
{
    char cmd[MAX_CMD_LENGTH];
    char srcStation[MAX_STATION_NAME_LENGTH];
    char dstStation[MAX_STATION_NAME_LENGTH];
}ST_CMD_SINGLE_TICKET;

//������ͨ�������꿨����
typedef struct
{
    char cmd[MAX_CMD_LENGTH];
    //EN_CARD_TYPE enCard;
    char cardType[MAX_CARD_TYPE_LENGTH];
    int cardCharge;
}ST_CMD_CREATE_CARD;

//��ֵ����
typedef struct
{
    char cmd[MAX_CMD_LENGTH];
    int cardNo;
    int cardCharge;
}ST_CMD_FILL_CHARGE;

//��ѯ��ʷ��������
typedef struct
{
    char cmd[MAX_CMD_LENGTH];
    int cardNo;
}ST_CMD_QUERY_HIS;

//���ٿ�
typedef struct
{
    char cmd[MAX_CMD_LENGTH];
    int cardNo;
}ST_CMD_DESTROY_CARD;

//ֻ����һ��������Ĺ�������ṹ
typedef struct
{
    char cmd[MAX_CMD_LENGTH];
}ST_COMMON_CMD;

//��ѯ��·
typedef ST_COMMON_CMD ST_CMD_QUERY_LINE;

//���Ѷ�ȷֲ�
typedef ST_COMMON_CMD ST_CMD_EXPENDITURE_DIS;

//�˿ͳ˳�ʱ��ֲ�
typedef ST_COMMON_CMD ST_CMD_PASSENGER_DIS;

//����ϵͳ
typedef ST_COMMON_CMD ST_CMD_RESET;

/*******************************�����������ṹ******************************************************/
//��������
typedef union
{
    ST_CMD_DEDUCT stCmdDeduct;
    ST_CMD_SINGLE_TICKET stCmdSingleTicket;
    ST_CMD_CREATE_CARD stCmdCreateCard;
    ST_CMD_FILL_CHARGE stCmdFillCharge;
    ST_CMD_QUERY_LINE stCmdQueryLine;
    ST_CMD_DESTROY_CARD stCmdDesCard;
    ST_CMD_QUERY_HIS stCmdQueryHis;
    ST_CMD_RESET stCmdReset;
    ST_CMD_EXPENDITURE_DIS stExpenditureDis;
    ST_CMD_PASSENGER_DIS stPassengerDis;
}UN_CMD;

//ͨ������ṹ
typedef struct
{
    EN_CMD_TYPE enCmdType;
    UN_CMD unCmd;
}ST_COMM_CMD;


/*******************************������뺯�����******************************************************/
//���������
int cmdParse(ST_COMM_CMD &stCommCmd, const char* cmdStr);

//��ȡ���������ַ���
char* GetCmdNameStr(EN_CMD_TYPE enCmd);
#endif
#include  <sstream>
#include "list.h"
#include "subwayLine.h"
#include "subwayMacro.h"

using namespace std;

//�Ƿ�վ���
//#define INVALID_STATION_NO (unsigned int)(-1)

//������·����
typedef enum
{
    EN_DERECT_NEXT = 0,
    EN_DERECT_PREV,
    EN_DERECT_BUTT
}EN_DERECT;

//����վ
typedef struct
{
    unsigned int no;
    bool usrFlag;
    TListHead list;
    unsigned int dis[EN_DERECT_BUTT];
}ST_STATION;

//������·
typedef struct
{
    TListHead subwayLine;
}ST_LINE;

//����վ�͵������б�
ST_STATION g_stasionList[MAX_STATION_NUM];
ST_LINE g_line;


/*
@ ��ʼ������վ��Ϣ
@ ����ֵ:void
*/
void InitStation(unsigned int stationNo)
{
    g_stasionList[stationNo].list.next = NULL;
    g_stasionList[stationNo].list.prev = NULL;
    g_stasionList[stationNo].dis[EN_DERECT_NEXT] = 0;
    g_stasionList[stationNo].dis[EN_DERECT_PREV] = 0;
    g_stasionList[stationNo].usrFlag = false;
    g_stasionList[stationNo].no = stationNo;
}

/*
@ ��ʼ��������·��Ϣ
@ ����ֵ:void
*/
void InitSubwayLine()
{
    for(int i = 0; i < MAX_STATION_NUM; i++)
    {
        InitStation(i);
    }

    InitListHead(&(g_line.subwayLine));
}

/*
@ ����һ������վ
@ ����ֵ: -1, ʧ��;  0, �ɹ�
*/
EN_RETURN_CODE AddSubwayStation(const char* stationName, unsigned int dis)
{
    unsigned int stationNo = atoi(&(stationName[1]));

    IF_INVALID_RETURN(stationNo < MAX_STATION_NUM, EN_RETURN_INVALID_STATION)
    IF_INVALID_RETURN(!(g_stasionList[stationNo].usrFlag), EN_RETURN_ADD_STATION_REPEAT)
    IF_INVALID_RETURN(dis <= MAX_DIS_BETWEEN_STATION, EN_RETURN_INVALID_DIS)

    if(ListEmpty(&(g_line.subwayLine)))
    {
        dis = 0;
    }
    else
    {
        IF_INVALID_RETURN(dis != 0, EN_RETURN_INVALID_DIS)

        //�ѷ�����ľ�����д�ɹ�
        TListHead* prevNode = g_line.subwayLine.prev;
        ST_STATION* prevStation = /*lint --e(413)*/CONTAINER_OF(prevNode, ST_STATION, list);
        prevStation->dis[EN_DERECT_PREV] = dis;
    }

    //��д��ǰվ��
    g_stasionList[stationNo].usrFlag = true;
    g_stasionList[stationNo].dis[EN_DERECT_PREV] = 0;
    g_stasionList[stationNo].dis[EN_DERECT_NEXT] = dis;  

    ListAddTail(&(g_stasionList[stationNo].list), &(g_line.subwayLine));
    return EN_RETURN_SUCC;
}

/*
@ ���ݷ����ȡ��һ�ڵ�
@ ����ֵ: TListHead* tmpNode
*/
TListHead* GetNextNode(TListHead* srcNode, EN_DERECT enDerect)
{
    TListHead* tmpNode = NULL;

    if(EN_DERECT_NEXT == enDerect)
    {
        tmpNode = srcNode->next;
    }
    else
    {
        tmpNode = srcNode->prev;
    }
    return tmpNode;
}

/*
@ ���̶��������Ŀ��վ��
@ ����ֵ: 0: �ɹ�, -1: ʧ��
*/
int GetOneDerectDis(TListHead* srcNode, EN_DERECT enDerect, unsigned int stationNo2, unsigned int &dis)
{
    TListHead* tmpNode = NULL;
    ST_STATION* tmpStation = NULL;
    tmpNode = GetNextNode(srcNode, enDerect);
    while((NULL != tmpNode) && ((&(g_line.subwayLine)) != tmpNode))
    {
        tmpStation = /*lint --e(413)*/CONTAINER_OF(tmpNode, ST_STATION, list);
        dis += tmpStation->dis[enDerect];
        if(tmpStation->no == stationNo2)
        {
            return 0;
        }

        tmpNode = GetNextNode(tmpNode, enDerect);
    }
    return -1;
}

/*
@ ��ȡ��������վ�����С����
@ ����ֵ: EN_RETURN_SUCC: �ɹ�, ����: ʧ��
*/
EN_RETURN_CODE GetSubwayStationDis(char* stationName1, char* stationName2, unsigned int &dis)
{
    unsigned int stationNo1 = atoi(&(stationName1[1]));
    unsigned int stationNo2 = atoi(&(stationName2[1]));

    IF_INVALID_RETURN(stationNo1 < MAX_STATION_NUM, EN_RETURN_INVALID_STATION)
    IF_INVALID_RETURN(stationNo2 < MAX_STATION_NUM, EN_RETURN_INVALID_STATION)
    IF_INVALID_RETURN(g_stasionList[stationNo1].usrFlag, EN_RETURN_STATION_UNUSED)
    IF_INVALID_RETURN(g_stasionList[stationNo2].usrFlag, EN_RETURN_STATION_UNUSED)

    if(stationNo1 == stationNo2)
    {
        dis = 0;
        return EN_RETURN_SUCC;
    }

    dis = 0;
    if(0 == GetOneDerectDis(&(g_stasionList[stationNo1].list), EN_DERECT_NEXT, stationNo2, dis))
    {
        return EN_RETURN_SUCC;
    }

    dis = 0;
    if(0 == GetOneDerectDis(&(g_stasionList[stationNo1].list), EN_DERECT_PREV, stationNo2, dis))
    {
        return EN_RETURN_SUCC;
    }

    return EN_RETURN_INNER_ERR;
}

/*
@ ɾ��������
@ ����ֵ: void
*/
void DelSubwayLine()
{
    InitSubwayLine();
    return;
}

/*
@ ��ӡ���е�����
*/
void GetLineInfo(string &outStr)
{
    ostringstream oss;

    oss<<"������·��";

    TListHead* pos = NULL;
    ST_STATION* tmpStation = NULL;
    ListForEach(pos, &(g_line.subwayLine))
    {
        tmpStation = /*lint --e(413)*/CONTAINER_OF(pos, ST_STATION, list);
        oss<<"S"<<tmpStation->no;
        if(!ListIsLast(pos, &(g_line.subwayLine)))
        {
            oss<<"<->";
        }
    }
    /*lint --e(1023)*//*lint --e(1703)*/outStr = oss.str();
}

/*
@ ����Ĭ�ϵ�����·
@ ����ֵ: NULL
*/
void SetDefaultLine()
{
    (void)AddSubwayStation("S0", 0);
    (void)AddSubwayStation("S1", 800);
    (void)AddSubwayStation("S2", 2168);
    (void)AddSubwayStation("S3", 2098);
    (void)AddSubwayStation("S4", 2165);
    (void)AddSubwayStation("S5", 1500);
    (void)AddSubwayStation("S6", 1345);
    (void)AddSubwayStation("S7", 1567);
    (void)AddSubwayStation("S8", 1897);
    (void)AddSubwayStation("S9", 1000);
    (void)AddSubwayStation("S10", 900);
    (void)AddSubwayStation("S11", 1168);
    (void)AddSubwayStation("S12", 2000);
    (void)AddSubwayStation("S13", 1600);
    (void)AddSubwayStation("S14", 1485);
    (void)AddSubwayStation("S15", 1600);
    (void)AddSubwayStation("S16", 1888);
}
#ifndef __SUBWAY_LINE_H__
#define __SUBWAY_LINE_H__
#include <iostream>
#include "subwayError.h"
using namespace std;

#define MAX_STATION_NUM 100
#define MAX_DIS_BETWEEN_STATION 50000

/*
@ ����һ������վ
@ ����ֵ: EN_RETURN_SUCC, �ɹ�; ������ʧ��
*/
EN_RETURN_CODE AddSubwayStation(const char* stationName, unsigned int dis);

/*
@ ��ȡ��������վ�����С����
@ ����ֵ: EN_RETURN_SUCC: �ɹ�, EN_RETURN_INVALID_LINE: ʧ��
*/
EN_RETURN_CODE GetSubwayStationDis(char* stationName1, char* stationName2, unsigned int &dis);

/*
@ ��ʼ��������·������ϵͳ
*/
void InitSubwayLine();

/*
@ ɾ��������
@ ����ֵ: void
*/
void DelSubwayLine();


/*
@ ����Ĭ�ϵ�����·
@ ����ֵ: NULL
*/
void SetDefaultLine();

/*
@ ��ӡ���е�����
*/
void GetLineInfo(string &outStr);

#endif
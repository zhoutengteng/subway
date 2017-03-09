#ifndef __SUBWAY_PRICE_H__
#define __SUBWAY_PRICE_H__
#include "subwayCard.h"
#include "subwayError.h"

/*
@ ��ȡ����Ʊ��, ������վ�����վ��֮��������̷ּ�����
*/
int GetBasePrice(unsigned int meters);

/*
@ ��ȡ�۷�Ʊ�ۣ��������;
@   1. �����Ϊ0����ʱ���շ�;
@   2. �������Ϊ0;
@ ����ֵ: 
*/
EN_RETURN_CODE GetDeductPrice(EN_CARD_TYPE enCardType, unsigned int balance, unsigned int meters, ST_SUBWAY_TIME &enterTime, ST_SUBWAY_TIME &exitTime, unsigned int &deductPrice);

#endif
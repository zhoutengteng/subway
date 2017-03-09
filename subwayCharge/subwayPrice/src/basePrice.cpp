#include "stdafx.h"
#include <iostream>
#include  <sstream>
#include "subwayMacro.h"
#include "include/basePrice.h"
using namespace std;

/*
@ ��ȡ����Ʊ��, ������վ�����վ��֮��������̷ּ�����
@ -1, ��ѯ����Ʊ��ʧ��; ����, ����Ʊ��
*/
int GetBasePrice(unsigned int meters)
{
	if (meters > 0 && meters <= 3000) return 2;
	if (meters > 3000&& meters <= 5000) return 3;
	if (meters > 5000 && meters <= 10000) return 4;
	if (meters > 10000) return 5;
    return -1;
}
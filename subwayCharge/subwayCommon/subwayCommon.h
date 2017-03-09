#ifndef __COMM_SPLIT_H__
#define __COMM_SPLIT_H__
#include <vector>
#include "list.h"
using namespace std;

/*
@ ����ַ���
@ ��Σ�  splitStr, ������ַ���; intervalStr, ��ּ����;
@ ���Σ�  splitArray, ��ֺ���ַ�������; 
@ ����ֵ: true, ��ֳɹ�; false, ���ʧ��;
*/
bool strSplit(vector<string> &splitArray, const string &splitStr, const char* intervalStr);


#endif
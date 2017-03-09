#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include "subwayCommon.h"

/*
@ ����ַ���
@ ��Σ�  splitStr, ������ַ���; intervalStr, ��ּ����;
@ ���Σ�  splitArray, ��ֺ���ַ�������; 
@ ����ֵ: true, ��ֳɹ�; false, ���ʧ��;
*/
bool strSplit(vector<string> &splitArray, const string &splitStr, const char* intervalStr)
{
    unsigned int strLength = splitStr.length();

    char* splitTmp = NULL;
    splitTmp = new char[strLength + 1];
    if(NULL == splitTmp)
    {
        return false;
    }

    memset(splitTmp, 0, strLength + 1);
    memcpy_s(splitTmp, strLength + 1, splitStr.c_str(), strLength);

    char *result = NULL; 
    char *pNext = NULL;  
    result = strtok_s(splitTmp, intervalStr, &pNext);
    while(result != NULL)    
    {         
        /*lint --e(1023)*//*lint --e(1703)*/splitArray.push_back(result);
        result = strtok_s(NULL, intervalStr, &pNext);    
    }

    delete []splitTmp;
    return true;
}
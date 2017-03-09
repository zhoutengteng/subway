#include "stdafx.h"
#include <iostream>
#include "subwayGlobalDef.h"
#include "subwayCard.h"
#include "subwayline.h"
#include "subwayCommon.h"
#include "subwayCmdParse\subwayCmdParse.h"
#include "subwayOutput\subwayOutput.h"
using namespace std;

/*
@ 查询地铁线
@ 入参：unCmd, 命令内容
@ 出参: returnStr
@ 返回值: 无
*/
void ProcQueryLineCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
    //查询所有地铁线 GetLineInfo
	string tempStr;
	GetLineInfo(tempStr);
	memcpy_s(returnStr,MAX_SEND_BUFFER_LENGTH, tempStr.c_str(), tempStr.length());
	returnStr[tempStr.length()] = 0;
    return;
}
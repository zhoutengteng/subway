#if _SUBWAY_LLT
#include "subwayGlobalDef.h"
#include "gtest\gtest.h"
#include "subwayline.h"
#include "subwayCmdProc\include\subwayQueryLineProc.h"

using namespace testing;

class subwayQueryLineProc : public testing::Test {

public:	
	static void SetUpTestCase() {
		InitSubwayLine();
		//预置默认地铁线路
		SetDefaultLine();
	}

	static void TearDownTestCase() {

	
	}

	void SetUp() {
		ST_COMMON_CMD order;
		strcpy_s(order.cmd, MAX_CMD_LENGTH, "L");
		un_cmd.stCmdQueryLine = order;
	}

	void TearDown() {

	}

	UN_CMD un_cmd;
};

TEST_F(subwayQueryLineProc, ProcQueryLineCmd_method_test) {
	char returnStr[MAX_SEND_BUFFER_LENGTH];
	ProcQueryLineCmd(un_cmd, returnStr);
	EXPECT_STREQ("地铁线路：S0<->S1<->S2<->S3<->S4<->S5<->S6<->S7<->S8<->S9<->S10<->S11<->S12<->S13<->S14<->S15<->S16", returnStr);
}

#endif

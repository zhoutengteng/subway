#if _SUBWAY_LLT
#include "gtest\gtest.h"
#include "subwayline.h"
#include "subwayCmdProc\include\subwaySingleTicketProc.h"
#include "subwayCmdProc\include\subwayResetProc.h"
using namespace testing;

class subwaysingticket : public testing::Test {

public:
	static void SetUpTestCase() {
		InitSubwayLine();
		//Ԥ��Ĭ�ϵ�����·
		SetDefaultLine();
	}

	static void TearDownTestCase() {}
	
	void SetUp() {
		ST_COMMON_CMD order;
		char returnStr[MAX_SEND_BUFFER_LENGTH];
		strcpy_s(order.cmd, MAX_CMD_LENGTH, "R");
		UN_CMD unCmdR;
		unCmdR.stCmdReset = order;
		ProcResetCmd(unCmd, returnStr);
	}
	void TearDown() {

	}
	UN_CMD unCmd;

	void cmd2unCmd(char* cmd, char* option1, char* option2) {
		ST_CMD_SINGLE_TICKET order;
		strcpy_s(order.cmd, MAX_CMD_LENGTH, cmd);
		strcpy_s(order.srcStation, MAX_STATION_NAME_LENGTH, option1);
		strcpy_s(order.dstStation, MAX_STATION_NAME_LENGTH, option2);
		unCmd.stCmdSingleTicket = order;
	}

	
};


TEST_F(subwaysingticket, ProcCreateSingleTicketCmd_test1) {
	char returnStr[MAX_SEND_BUFFER_LENGTH];
	cmd2unCmd("S", "S24", "S8");
	ProcCreateSingleTicketCmd(unCmd, returnStr);
	EXPECT_STREQ("���򵥳�Ʊ<ʧ��><ʧ��ԭ��=����վδ����>", returnStr);
}

TEST_F(subwaysingticket, ProcCreateSingleTicketCmd_test2) {
	char returnStr[MAX_SEND_BUFFER_LENGTH];
	cmd2unCmd("S", "S100", "S8");
	ProcCreateSingleTicketCmd(unCmd, returnStr);
	EXPECT_STREQ("���򵥳�Ʊ<ʧ��><ʧ��ԭ��=��Ч�ĵ���վ>", returnStr);
}


TEST_F(subwaysingticket, ProcCreateSingleTicketCmd_test3) {
	char returnStr[MAX_SEND_BUFFER_LENGTH];
	cmd2unCmd("S", "S0", "S99");
	ProcCreateSingleTicketCmd(unCmd, returnStr);
	EXPECT_STREQ("���򵥳�Ʊ<ʧ��><ʧ��ԭ��=����վδ����>", returnStr);
}


TEST_F(subwaysingticket, ProcCreateSingleTicketCmd_test4) {
	char returnStr[MAX_SEND_BUFFER_LENGTH];
	cmd2unCmd("S", "S0", "S200");
	ProcCreateSingleTicketCmd(unCmd, returnStr);
	EXPECT_STREQ("���򵥳�Ʊ<ʧ��><ʧ��ԭ��=��Ч�ĵ���վ>", returnStr);
}

TEST_F(subwaysingticket, ProcCreateSingleTicketCmd_test6) {
	char returnStr[MAX_SEND_BUFFER_LENGTH];
	cmd2unCmd("S", "S0", "S16");
	ProcCreateSingleTicketCmd(unCmd, returnStr);
	EXPECT_STREQ("���򵥳�Ʊ<�ɹ�><����=0><������=���̿�><���=5>", returnStr);
}


TEST_F(subwaysingticket, ProcCreateSingleTicketCmd_test7) {
	char returnStr[MAX_SEND_BUFFER_LENGTH];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 16; j++) {
			if (i == 6 && j == 5) break;
			char sourceStationNum[4] = "S0";
			char destStationNum[4] = "S0";
			cmd2unCmd("S", sourceStationNum, destStationNum);
			ProcCreateSingleTicketCmd(unCmd, returnStr);
		}
	}
	EXPECT_STREQ("���򵥳�Ʊ<ʧ��><ʧ��ԭ��=����Ŀ�����ϵͳ����>", returnStr);
}



#endif
#include "StdAfx.h"
#include "TestAGuiOperator.h"
#include "AGuiLOG/IAGuiLOG.h"

void TestAguiOperatorMain()
{
	CAGuiOperator op;
	//string strOpFlag="00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011101010";
	string strOpFlag="11001100";
	op.SetOpDetail(strOpFlag);

	for (int i=0;i<8;i++)
	{
		CString strDebug="";
		strDebug.Format("AGuiOperator_%d=%s",i,op.CheckOpDetail(i)?"true":"false");
		AGuiObj::AGuiLog()->AppendMsg(strDebug);
	}
	op.AddOpDetail(OPERATE_TYPE_ZERO);
	op.AddOpDetail(OPERATE_TYPE_ONE);

	op.RemoveOpDetail(OPERATE_TYPE_THREE);
	op.RemoveOpDetail(OPERATE_TYPE_TWO);

	for (int i=0;i<8;i++)
	{
		CString strDebug="";
		strDebug.Format("AGuiOperator_%d=%s",i,op.CheckOpDetail(i)?"true":"false");
		AGuiObj::AGuiLog()->AppendMsg(strDebug);
	}
}
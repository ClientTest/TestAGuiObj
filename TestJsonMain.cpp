#include "StdAfx.h"
#include "TestJsonMain.h"
#include "AGuiLOG/IAGuiLOG.h"

void TestJsonRead(CString data)
{
	AGuiObj::AGuiLog()->AppendMsg("JsonReadData="+data);
	CString strResult="";
	try
	{
		Json::Value pkt;
		Json::Reader reader;
		std::string pktData(data.GetBuffer(),data.GetLength());
		reader.parse(pktData,pkt);

		std::string pktCmd = pkt["cmd"].asString();
		int pktX = pkt["x"].asInt();
		int pktY = pkt["y"].asInt();

		if(pktCmd == "on_marquee_start")
		{
			Json::Value msg = pkt["msg"];

			std::string msgCmd = msg["cmd"].asString();
			int msgX = msg["x"].asInt();
			int msgY = msg["y"].asInt();

			strResult.Format("JsonReadResult:pktCmd=%s,pktX=%d,pktY=%d,msgCmd=%s,msgX=%d,msgY=%d",pktCmd.c_str(),pktX,pktY,msgCmd.c_str(),msgX,msgY);
			AGuiObj::AGuiLog()->AppendMsg(strResult);
		}
	}catch(...)
	{
		return ;
	}
}
void TestJsonWrite(CString data)
{
	try
	{
		Json::FastWriter writer;
		Json::Value parameters;
		int resTime = 1314;
		parameters["Tag"] = (Json::Value)"GetRoomPath";
		parameters["roomId"] = (Json::Value)10000;
		parameters["roomName"] = (Json::Value)"ÇÙÆåÊé»­";
		parameters["operatorId"] = (Json::Value)"3000000002";
		parameters["operatorKey"] = (Json::Value)"401FAA4FE0FFDF5C534094B5AC213AF1";

		Json::Reader reader;
		Json::Value msg;
		reader.parse(data.GetString(),msg);
		parameters["msg"]=msg;

		std::string result = writer.write(parameters);
		CString strResult = result.c_str();
		AGuiObj::AGuiLog()->AppendMsg("JsonWriteResult="+strResult);
	}
	catch(...)
	{
	}
}
void TestJsonMain()
{
	CString strJson = "{\"cmd\":\"on_marquee_start\",\"msg\":{\"cmd\":\"on_marquee_start\",\"x\":100,\"y\":100},\"x\":99,\"y\":99}";
	TestJsonRead(strJson);
	TestJsonWrite(strJson);
}
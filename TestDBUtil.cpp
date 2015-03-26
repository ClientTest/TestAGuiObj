#include "StdAfx.h"
#include "TestDBUtil.h"
#include "MfcLib/AGuiFun/AGuiPath.h"
#include "AGuiLOG/IAGuiLOG.h"

CTestDBUtil::CTestDBUtil(void)
{
	m_pDBUtil = NULL;
}


CTestDBUtil::~CTestDBUtil(void)
{
	if (m_pDBUtil)
	{
		delete m_pDBUtil;
		m_pDBUtil=NULL;
	}
}

void CTestDBUtil::OnGetDBResultCB(int nRow,int nColumn,char **azResult,char *zErrMsg)
{
	CString strDebug="";
	strDebug.Format("row=:%d column=%d \n ", nRow, nColumn);
	AGuiObj::AGuiLog()->AppendMsg(strDebug);
	AGuiObj::AGuiLog()->AppendMsg("The result of querying is : \n");
	/*for(int i=0;i<(nRow+1)*nColumn;i++)
	{
		strDebug.Format("azResult[%d] = %s \n",i,azResult[i]);
		AGuiObj::AGuiLog()->AppendMsg(strDebug);
	}*/
	for(int i=0;i<(nRow+1);i++)
	{
		CString strMsg="";
		strMsg.Format("  %d  ",i);
		for(int j=0;j<nColumn;j++)
		{
			CString strTemp="";
			strTemp.Format("  %s  ",azResult[i*nColumn+j]);
			strMsg+=strTemp;
		}
		strMsg+="\n";
		AGuiObj::AGuiLog()->AppendMsg(strMsg);
	}
}

void CTestDBUtil::TestDBMain()
{
	if (!m_pDBUtil)
	{
		m_pDBUtil = AGuiObj::GetDBUtilInstance();
	}
	CString strFilePath;
	strFilePath.Format("%sdb\\test.db",AGuiFun::GetConfigPath());

	CString sql = "CREATE TABLE province(ID INTEGER PRIMARY KEY, COUNTRYID INTEGER,NAME VARCHAR(12),STATUS INTEGER);";
	m_pDBUtil->ExcuteSQL(strFilePath,sql);

	/*vector<CString> vecStr;
	vecStr.push_back("INSERT INTO 'province' VALUES(18,5,'�㽭',1);");
	vecStr.push_back("INSERT INTO 'province' VALUES(19,3,'����',1);");
	vecStr.push_back("INSERT INTO 'province' VALUES(20,5,'���',1);");
	m_pDBUtil->ExcuteSQL(strFilePath,vecStr);*/

	//��ѯ���ݿ�
	sql = "SELECT id ,name FROM province order by name asc";
	m_pDBUtil->ExcuteSQL(strFilePath,sql,this);

	 //�������ݿ�
	sql = "INSERT INTO 'province' (COUNTRYID,NAME,STATUS) VALUES(5,'����',1);";
	m_pDBUtil->ExcuteSQL(strFilePath,sql);

	//�޸����ݿ�
	sql = "UPDATE 'province' SET NAME='����' WHERE COUNTRYID=3";
	m_pDBUtil->ExcuteSQL(strFilePath,sql);

	sql = "SELECT id ,name FROM province order by name asc";
	m_pDBUtil->ExcuteSQL(strFilePath,sql,this);

	//ɾ�����ݿ�
	sql = "DELETE FROM 'province' WHERE ID>3;";
	m_pDBUtil->ExcuteSQL(strFilePath,sql);

	sql = "SELECT id ,name FROM province order by name asc";
	m_pDBUtil->ExcuteSQL(strFilePath,sql,this);

}

#pragma once
#include "AGuiObject/db/IDBUtil.h"
using namespace AGuiObj;

class CTestDBUtil : public IDBUtilListen
{
public:
	CTestDBUtil(void);
	~CTestDBUtil(void);

private:
	IDBUtil*   m_pDBUtil;

public:
	virtual void OnGetDBResultCB(int nRow,int nColumn,char **azResult,char *zErrMsg);

public:
	void TestDBMain();
};


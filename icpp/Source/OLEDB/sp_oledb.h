// ������������ ������ aka spock.
// #163860836
// e-mail: spock@km.ru
//
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <oledb.h>
#include <msdasc.h>

#include "..\\ODBC\\MetaNameParser.h"
#include "..\\SQL\\MetaDataWork.h"

#include "..\\mycontextbase.h"

class COLEDBCommand;

//trad
//_____________________________________________________________________________
//
class CIBSetOLEDB : public CIBSet
{
public:
    CDate GetDateTimeTA(CEventTime &TimeTA);
    int GetDataSourceType();
    enum PeriodType GetRestsSnapShotPeriod();
};
//

//_____________________________________________________________________________
//
class COLEDBData : public CMyContextBase
{
	DECLARE_DYNCREATE(COLEDBData);

public:
	COLEDBData();
	virtual ~COLEDBData();

	BOOL funcConnect(CValue& RetVal, CValue** ppValue);
	BOOL defsConnect(int nParam, CValue* param) const;
	
	DLLEXPORT COLEDBCommand * CreateCommand ();
	BOOL funcCreateCommand(CValue& RetVal, CValue** ppValue);
	BOOL procClose(CValue** ppValue);

	BOOL funcAttachIB(CValue& RetVal, CValue** ppValue);
	BOOL defsAttachIB(int nParam, CValue* param) const;

private:
	CComPtr<IDBInitialize> m_pInit;
	CComPtr<IDBCreateCommand> m_pIDBCreateCommand;
	
	//trad
	//
	CMetaDataCont* m_pMetaDataCont;
	CIBSetOLEDB m_OLEDBIBSet;
	//

	void GetErrorDescription(CString& strError) const;
	
	bool m_bConnected;

	DECLARE_MY_CONTEXT();
};
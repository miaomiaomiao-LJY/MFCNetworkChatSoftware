#pragma once
#include <afxsock.h>

class CClientSocket :
	public CAsyncSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	VOID SetListBox(CListBox * ListBox) { m_ListBox = ListBox; }
	CListBox * m_ListBox;
};


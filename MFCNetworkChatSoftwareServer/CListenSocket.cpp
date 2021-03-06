#include "pch.h"
#include "CListenSocket.h"


// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	TRACE("Current position : %s \n", &__FUNCTION__);
	if (nErrorCode == 0)//如果成功
	{
		CClientSocket* pNewClientSocket = new CClientSocket(); //保存一个已经连接的客户端
		BOOL bAccept = Accept(*pNewClientSocket);
		if (bAccept)
		{
			m_ClientSocketList.push_back(pNewClientSocket);
			pNewClientSocket->SetListBox(m_ListBoxMsg);
			pNewClientSocket->m_sql_operator = m_sql_operator;
			pNewClientSocket->m_ClientSocketList = &m_ClientSocketList;
			//pNewClientSocket->m_ClientSocketList.assign(m_ClientSocketList.begin(), m_ClientSocketList.end());

			CString SocketName;
			UINT len = 100;
			pNewClientSocket->GetSockName(SocketName, len);
			TRACE("Client  : %s request connect.\n", (LPCTSTR)SocketName);

			char addString[100] = "Client ";
			strcat_s(addString, SocketName.GetBuffer(0));
			strcat_s(addString, " : ");
			strcat_s(addString, " request connecttion. ");

			m_ListBoxMsg->AddString(addString);
			//m_ListBox->AddString(SocketName);           //客户端列表里显示这个已经连接的客户端ip
		}
		else
		{
			DWORD dwErr = GetLastError();
			CString strErr;
			strErr.Format(_T("accept 错误码=%d"), dwErr);
			delete pNewClientSocket;
			AfxMessageBox(strErr);
		}
	}

	CAsyncSocket::OnAccept(nErrorCode);
}


void CListenSocket::OnClose(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CAsyncSocket::OnClose(nErrorCode);
}

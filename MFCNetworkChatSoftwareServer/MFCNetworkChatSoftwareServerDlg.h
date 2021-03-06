﻿
// MFCNetworkChatSoftwareServerDlg.h: 头文件
//

#pragma once
#include "CListenSocket.h"
#include "MySQLModule.h"

// CMFCNetworkChatSoftwareServerDlg 对话框
class CMFCNetworkChatSoftwareServerDlg : public CDialogEx
{
// 构造
public:
	CMFCNetworkChatSoftwareServerDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCNETWORKCHATSOFTWARESERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	// 该Socket为服务器监听器（监听来自客户端的连接）
	CListenSocket * m_ListenSocket;
	// 该控件为服务器消息显示器（显示服务器状态、客户端连接信息等）
	CListBox m_list_message_logging;
	afx_msg void OnClickedButtonStart();

	MySQLModule* m_sql_operator;
};

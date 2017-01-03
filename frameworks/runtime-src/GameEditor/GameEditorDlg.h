
// GameEditorDlg.h : 头文件
//

#pragma once

#include "Cocos2dxWin.h"
#include "afxwin.h"

// CGameEditorDlg 对话框
class CGameEditorDlg : public CDialogEx
{
// 构造
public:
	CGameEditorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAMEEDITOR_DIALOG };
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
	CCocos2dxWin m_nPicCocos2dx;
	bool isPointInPictureWin(CPoint& pt);
	CPoint getPicturePoint(CPoint& pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

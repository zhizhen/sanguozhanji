
// GameEditorDlg.h : ͷ�ļ�
//

#pragma once

#include "Cocos2dxWin.h"
#include "afxwin.h"

// CGameEditorDlg �Ի���
class CGameEditorDlg : public CDialogEx
{
// ����
public:
	CGameEditorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAMEEDITOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

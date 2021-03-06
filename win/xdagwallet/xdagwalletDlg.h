// cheatcoinwalletDlg.h : header file
//

#pragma once

#include "afxwin.h"
#include "CEditWalletAddr.h"

#define WM_UPDATE_STATE (WM_USER+1)
#define ID_TIMER_HASHRATE 100

// CXDagWalletDlg dialog
class CXDagWalletDlg : public CDialog {
	// Construction
public:
	CXDagWalletDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XDAGWALLET_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	BOOL OnInitDialog() override;
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CButton _applyButton;
	CString _poolAddress;
	int _miningThreadsCount;
	CEdit _hashRateEdit;
	CString _balance;
	CEdit _balanceEdit;
	CString _accountAddress;
	CEditWalletAddr _accountAddressEdit;
	CString _transferAmount;
	CString _transferAddress;
	CString _state;
	CStatic _stateControl;
	CEdit _transferAmountEdit;
	CEdit _transferAddressEdit;
	CButton _xferButton;

	afx_msg void OnClickedButtonConnect();
	afx_msg void OnClickedButtonXfer();
	afx_msg void OnBnClickedButtonApply();
	afx_msg LRESULT OnUpdateState(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTimer(WPARAM wParam);

	static int InputPassword(const char *prompt, char *buf, unsigned size);
	static int ShowState(const char *state, const char *balance, const char *address);

public:
	void SetBalance(const char *balance) { _balance = balance; }
	void SetAccountAddress(const char *address) { _accountAddress = address; }
	void SetState(const char *state) { _state = state; }
};

extern CXDagWalletDlg *g_dlg;




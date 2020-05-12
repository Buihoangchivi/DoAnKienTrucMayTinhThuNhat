#pragma once


// CQfloat dialog

class CQfloat : public CDialogEx
{
	DECLARE_DYNAMIC(CQfloat)

public:
	CQfloat(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CQfloat();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CButton Dec;
	CButton Bin;
	CEdit num;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedReset();
};
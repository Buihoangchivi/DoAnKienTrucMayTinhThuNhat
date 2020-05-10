#pragma once


// CQInt dialog

class CQInt : public CDialogEx
{
	DECLARE_DYNAMIC(CQInt)

public:
	CQInt(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CQInt();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChuyendoi1();
	afx_msg void OnBnClickedChuyendoi2();
	afx_msg void OnBnClickedTinhtoan();
	afx_msg void OnBnClickedSosanh();
	afx_msg void OnBnClickedCong();
	afx_msg void OnBnClickedXor();
	afx_msg void OnBnClickedNot();
	afx_msg void OnBnClickedDichphai();
	afx_msg void OnBnClickedXoaytrai();
	afx_msg void OnBnClickedBe();
	afx_msg void OnBnClickedBang();
	afx_msg void OnBnClickedBebang();
	afx_msg void OnBnClickedCancel();
};

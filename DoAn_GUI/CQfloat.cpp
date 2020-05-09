// CQfloat.cpp : implementation file
//

#include "pch.h"
#include "DoAn_GUI.h"
#include "CQfloat.h"
#include "afxdialogex.h"
#include "ClassQfloat.h"

// CQfloat dialog

IMPLEMENT_DYNAMIC(CQfloat, CDialogEx)

CQfloat::CQfloat(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CQfloat::~CQfloat()
{
}

void CQfloat::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, Dec);
	DDX_Control(pDX, IDC_RADIO2, Bin);
	DDX_Control(pDX, IDC_EDIT1, num);
}


BEGIN_MESSAGE_MAP(CQfloat, CDialogEx)
	ON_BN_CLICKED(IDOK, &CQfloat::OnBnClickedOk)
END_MESSAGE_MAP()


// CQfloat message handlers

void CQfloat::OnBnClickedOk()
{
	CEdit* editbox = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString Cnum;
	editbox->GetWindowText(Cnum);
	string num = CStringA(Cnum);
	int check_radio = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO2);
	ClassQfloat temp;
	if (check_radio == IDC_RADIO1)
		check_radio = 10;
	else if(check_radio == IDC_RADIO2)
		check_radio = 2;
	else {
		MessageBox(_T("Ban chua chon he bieu dien"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	temp.ScanQfloat(num, check_radio);
	CString result_dec1 = _T("");
	CString result_dec2 = _T("");
	string dec = temp.BinToDec();
	
	if(dec.length()<=64) {
		result_dec1 = dec.c_str();
		CWnd* label_dec1 = GetDlgItem(IDC_STATIC_DEC1);
		label_dec1->SetWindowText(result_dec1);
		CWnd* label_dec2 = GetDlgItem(IDC_STATIC_DEC2);
		label_dec2->SetWindowText(L"");
	}
	else {
		result_dec1 = dec.substr(0,64).c_str();
		CWnd* label_dec1 = GetDlgItem(IDC_STATIC_DEC1);
		label_dec1->SetWindowText(result_dec1);
		result_dec2 = dec.substr(64).c_str();
		CWnd* label_dec2 = GetDlgItem(IDC_STATIC_DEC2);
		label_dec2->SetWindowText(result_dec2);
	}
	//
	CString result_bin1 = _T("");
	CString result_bin2 = _T("");
	string bin = temp.DectoBin();
	result_bin1 = bin.substr(0,64).c_str();
	result_bin2 = bin.substr(64).c_str();
	//
	CWnd* label_bin1 = GetDlgItem(IDC_STATIC_BIN1);
	label_bin1->SetWindowText(result_bin1);
	CWnd* label_bin2 = GetDlgItem(IDC_STATIC_BIN2);
	label_bin2->SetWindowText(result_bin2);
}
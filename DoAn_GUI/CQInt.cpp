// CQInt.cpp : implementation file
//

#include "pch.h"
#include "DoAn_GUI.h"
#include "CQInt.h"
#include "ClassQint_GUI.h"
#include "afxdialogex.h"
#include <string>
using namespace std;
// CQInt dialog

IMPLEMENT_DYNAMIC(CQInt, CDialogEx)

CQInt::CQInt(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CQInt::~CQInt()
{
}

void CQInt::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CQInt, CDialogEx)
	ON_BN_CLICKED(ID_ChuyenDoi1, &CQInt::OnBnClickedChuyendoi1)
	ON_BN_CLICKED(ID_ChuyenDoi2, &CQInt::OnBnClickedChuyendoi2)
END_MESSAGE_MAP()


// CQInt message handlers


void CQInt::OnBnClickedChuyendoi1()
{
	CEdit* editbox = (CEdit*)GetDlgItem(IDC_SoThu1);
	CString Cnum;
	editbox->GetWindowText(Cnum);
	string num = CStringA(Cnum);
	int check_radio = GetCheckedRadioButton(IDC_Dec, IDC_Hex);
	if (check_radio == IDC_Dec) {
		check_radio = 10;
	}
	else if (check_radio == IDC_Bin)
	{
		check_radio = 2;
	}
	else if(check_radio==IDC_Hex){
		check_radio = 16;
	}
	else {
		MessageBox(_T("Ban chua chon he bieu dien"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Nhap du lieu
	QInt temp;
	temp.Scan(num, check_radio);
	CString result_dec1 = _T("");
	CString result_dec2 = _T("");
	string dec = temp.getDec();
	if (dec.length() <= 64) {
		result_dec1 = dec.c_str();
		CWnd* label_dec1 = GetDlgItem(IDC_KQDec1);
		label_dec1->SetWindowText(result_dec1);
		CWnd* label_dec2 = GetDlgItem(IDC_KQDec2);
		label_dec2->SetWindowText(L"");
	}
	else {
		result_dec1 = dec.substr(0, 64).c_str();
		CWnd* label_dec1 = GetDlgItem(IDC_KQDec1);
		label_dec1->SetWindowText(result_dec1);
		result_dec2 = dec.substr(64).c_str();
		CWnd* label_dec2 = GetDlgItem(IDC_KQDec2);
		label_dec2->SetWindowText(result_dec2);
	}
	//Bin
	CString result_bin1 = _T("");
	CString result_bin2 = _T("");
	string bin = temp.getBin();
	result_bin1 = bin.substr(0, 64).c_str();
	result_bin2 = bin.substr(64).c_str();
	//
	CWnd* label_bin1 = GetDlgItem(IDC_KQBin1);
	label_bin1->SetWindowText(result_bin1);
	CWnd* label_bin2 = GetDlgItem(IDC_KQBin2);
	label_bin2->SetWindowText(result_bin2);

	//Hex
	CString result_hex1 = _T("");
	string hex = temp.getHex();
	result_hex1 = hex.substr(0, 64).c_str();
	//
	CWnd* label_hex1 = GetDlgItem(IDC_KQHex);
	label_hex1->SetWindowText(result_hex1);
}


void CQInt::OnBnClickedChuyendoi2()
{
	CEdit* editbox = (CEdit*)GetDlgItem(IDC_SoThu2);
	CString Cnum;
	editbox->GetWindowText(Cnum);
	string num = CStringA(Cnum);
	int check_radio = GetCheckedRadioButton(IDC_Dec, IDC_Hex);
	if (check_radio == IDC_Dec) {
		check_radio = 10;
	}
	else if (check_radio == IDC_Bin)
	{
		check_radio = 2;
	}
	else if (check_radio == IDC_Hex) {
		check_radio = 16;
	}
	else {
		MessageBox(_T("Ban chua chon he bieu dien"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Nhap du lieu
	QInt temp;
	temp.Scan(num, check_radio);
	CString result_dec1 = _T("");
	CString result_dec2 = _T("");
	string dec = temp.getDec();
	if (dec.length() <= 64) {
		result_dec1 = dec.c_str();
		CWnd* label_dec1 = GetDlgItem(IDC_KQDec1);
		label_dec1->SetWindowText(result_dec1);
		CWnd* label_dec2 = GetDlgItem(IDC_KQDec2);
		label_dec2->SetWindowText(L"");
	}
	else {
		result_dec1 = dec.substr(0, 64).c_str();
		CWnd* label_dec1 = GetDlgItem(IDC_KQDec1);
		label_dec1->SetWindowText(result_dec1);
		result_dec2 = dec.substr(64).c_str();
		CWnd* label_dec2 = GetDlgItem(IDC_KQDec2);
		label_dec2->SetWindowText(result_dec2);
	}
	//Bin
	CString result_bin1 = _T("");
	CString result_bin2 = _T("");
	string bin = temp.getBin();
	result_bin1 = bin.substr(0, 64).c_str();
	result_bin2 = bin.substr(64).c_str();
	//
	CWnd* label_bin1 = GetDlgItem(IDC_KQBin1);
	label_bin1->SetWindowText(result_bin1);
	CWnd* label_bin2 = GetDlgItem(IDC_KQBin2);
	label_bin2->SetWindowText(result_bin2);

	//Hex
	CString result_hex1 = _T("");
	string hex = temp.getHex();
	result_hex1 = hex.substr(0, 64).c_str();
	//
	CWnd* label_hex1 = GetDlgItem(IDC_KQHex);
	label_hex1->SetWindowText(result_hex1);
}

// CQfloat.cpp : implementation file
//

#include "pch.h"
#include "DoAn_GUI.h"
#include "CQfloat.h"
#include "afxdialogex.h"
#include "ClassQfloat_GUI.h"

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
	ON_BN_CLICKED(IDC_RESET, &CQfloat::OnBnClickedReset)
END_MESSAGE_MAP()


// CQfloat message handlers

bool CheckDataBin1(string Bin)
{
	if (Bin.size() != QFLOAT_SIZE) //128
	{
		//cout << "Du lieu sai!";
		return false;
	}
	for (int i = 0; i < Bin.size(); i++)
	{
		if (Bin[i] != '0' && Bin[i] != '1')
		{
			//cout << "Du lieu sai!";
			return false;
		}
	}
	return true;
}
//Kiểm tra dữ liệu hợp lệ không
bool CheckData1(string Dec)
{
	int DemDauCham = 0;
	int DemDau = 0;
	if (Dec.size() == 0 || (Dec[0] != '-' && (Dec[0] < '0' || Dec[0]>'9')))
	{
		//cout << "Du lieu sai!";
		return false;
	}
	if (Dec[0] == '-')
		DemDau = 1;
	for (int i = 1; i < Dec.size(); i++)
	{
		if (Dec[i] == '.')
		{
			DemDauCham++;
			if (DemDauCham == 2)
			{
				//cout << "Du lieu sai!";
				return false;
			}
		}
		else if (Dec[i] == '-')
		{
			DemDau++;
			if (DemDau == 2)
			{
				//cout << "Du lieu sai!";
				return false;
			}
		}
		else if (Dec[i] < '0' || Dec[i]>'9')
		{
			//cout << "Du lieu sai!";
			return false;
		}
	}
	return true;
}
//Hàm xử lí sự kiện khi nhấn nút OK
void CQfloat::OnBnClickedOk()
{
	//Lấy giá trị nhập
	CEdit* editbox = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString Cnum;
	editbox->GetWindowText(Cnum);
	string num = CStringA(Cnum);
	if(num.length()==0) {
		MessageBox(_T("Ban chua nhap du lieu"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Kiểm tra hệ biểu diễn
	int check_radio = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO2);
	if (check_radio == IDC_RADIO1) {
		bool check_dec = true;
		check_dec = CheckData1(num);
		if(!check_dec)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Dec"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 10;
	}
	else if(check_radio == IDC_RADIO2)
	{
		bool check_bin = true;
		check_bin = CheckDataBin1(num);
		if (!check_bin)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Bin"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 2;
	}
	else {
		MessageBox(_T("Ban chua chon he bieu dien"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Đưa giá trị vào và kiểm tra trường hợp đặc biệt
	int check;
	ClassQfloat temp;
	temp.ScanQfloat(num, check_radio,check);
	if (check > 1) {
		switch (check) {
		case 2:
			MessageBox(_T("So khong the chuan hoa!!!"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		case 3:
			MessageBox(_T("So vo cung!!!"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		case 4:
			MessageBox(_T("So bao loi!!!"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
	}
	//Xuat ket qua
	//Dec
	CString result_dec1 = _T("");
	CString result_dec2 = _T("");
	string dec = temp.getDec();	
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
	//Bin
	CString result_bin1 = _T("");
	CString result_bin2 = _T("");
	string bin = temp.getBin();
	result_bin1 = bin.substr(0,64).c_str();
	result_bin2 = bin.substr(64).c_str();
	//
	CWnd* label_bin1 = GetDlgItem(IDC_STATIC_BIN1);
	label_bin1->SetWindowText(result_bin1);
	CWnd* label_bin2 = GetDlgItem(IDC_STATIC_BIN2);
	label_bin2->SetWindowText(result_bin2);
}

//Xử lí sự kiện khi nhấn nút RESET
void CQfloat::OnBnClickedReset()
{
	CWnd* label_bin1 = GetDlgItem(IDC_STATIC_BIN1);
	CWnd* label_bin2 = GetDlgItem(IDC_STATIC_BIN2);
	CWnd* label_dec1 = GetDlgItem(IDC_STATIC_DEC1);
	CWnd* label_dec2 = GetDlgItem(IDC_STATIC_DEC2);
	label_bin1->SetWindowText(L"0");
	label_bin2->SetWindowText(L"0");
	label_dec1->SetWindowText(L"0");
	label_dec2->SetWindowText(L"");
	CEdit* editbox1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	editbox1->SetWindowText(L"");
}
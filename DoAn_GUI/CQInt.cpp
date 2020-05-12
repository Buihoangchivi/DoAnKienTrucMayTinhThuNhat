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
	ON_BN_CLICKED(ID_TinhToan, &CQInt::OnBnClickedTinhtoan)
	ON_BN_CLICKED(IDC_SoSanh, &CQInt::OnBnClickedSosanh)
	ON_BN_CLICKED(IDRESET, &CQInt::OnBnClickedReset)
END_MESSAGE_MAP()


// CQInt message handlers

// Hàm kiểm tra dãy nhị phân có hợp lệ không
bool checkBin(string num)
{
	int index = 0;
	while (num[index] != '\0')
	{
		if (num[index] != '0' && num[index] != '1')
			return false;
		index++;
	}
	return true;
}

// Hàm kiểm tra dãy thập phân có hợp lệ không
bool checkDec(string num)
{
	int index = 0;
	if (num[index] == '-')
		index++;
	while (num[index] != '\0')
	{
		if (num[index] < 48 || num[index]>57)
			return false;
		index++;
	}
	return true;
}

// Hàm kiểm tra dãy thập lục phân có hợp lệ không
bool checkHex(string num)
{
	int index = 0;
	if (num[index] == '-')
		index++;
	while (num[index] != '\0')
	{
		if ((num[index] < 48 || num[index]>57) && (num[index] < 65 || num[index]>70))
			return false;
		index++;
	}
	return true;
}

//Hàm xử lý khi click chuột vào nút chuyển đổi 1
void CQInt::OnBnClickedChuyendoi1()
{
	//Lấy giá trị được nhập
	CEdit* editbox = (CEdit*)GetDlgItem(IDC_SoThu1);
	CString Cnum;
	editbox->GetWindowText(Cnum);
	string num = CStringA(Cnum);
	//Kiểm tra đã nhập dữ liệu chưa
	if (num.length() == 0) {
		MessageBox(_T("Ban chua nhap du lieu"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	//Kiểm tra hệ biểu diễn giá trị nhập
	int check_radio = GetCheckedRadioButton(IDC_Dec, IDC_Hex);
	if (check_radio == IDC_Dec) {
		bool check_dec = true;
		check_dec = checkDec(num);
		if (!check_dec)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Dec"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 10;
	}
	else if (check_radio == IDC_Bin)
	{
		bool check_bin = true;
		check_bin = checkBin(num);
		if (!check_bin)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Bin"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 2;
	}
	else if (check_radio == IDC_Hex) {
		bool check_hex = true;
		check_hex = checkHex(num);
		if (!check_hex)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Hex"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 16;
	}
	else {
		MessageBox(_T("Ban chua chon he bieu dien"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Đưa giá trị vừa nhập vào QInt
	QInt temp;
	if (!temp.Scan(num, check_radio)) {
		MessageBox(_T("Ban nhap so thu nhat vuot qua kieu du lieu"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Xuất kết quả hệ Dec
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
	//Xuất kết quả hệ Bin
	CString result_bin1 = _T("");
	CString result_bin2 = _T("");
	string bin = temp.getBin();
	result_bin1 = bin.substr(0, 64).c_str();
	result_bin2 = bin.substr(64).c_str();

	CWnd* label_bin1 = GetDlgItem(IDC_KQBin1);
	label_bin1->SetWindowText(result_bin1);
	CWnd* label_bin2 = GetDlgItem(IDC_KQBin2);
	label_bin2->SetWindowText(result_bin2);

	//Xuất kết quả hệ Hex
	CString result_hex1 = _T("");
	string hex = temp.getHex();
	result_hex1 = hex.substr(0, 64).c_str();
	//
	CWnd* label_hex1 = GetDlgItem(IDC_KQHex);
	label_hex1->SetWindowText(result_hex1);
}

//Hàm xử lý khi click chuột vào nút chuyển đổi 2
void CQInt::OnBnClickedChuyendoi2()
{
	//Lấy giá trị được nhập
	CEdit* editbox = (CEdit*)GetDlgItem(IDC_SoThu2);
	CString Cnum;
	editbox->GetWindowText(Cnum);
	string num = CStringA(Cnum);
	//Kiểm tra đã nhập dữ liệu chưa
	if (num.length() == 0) {
		MessageBox(_T("Ban chua nhap du lieu"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	//Kiểm tra hệ biểu diễn giá trị nhập
	int check_radio = GetCheckedRadioButton(IDC_Dec, IDC_Hex);
	if (check_radio == IDC_Dec) {
		bool check_dec = true;
		check_dec = checkDec(num);
		if (!check_dec)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Dec"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 10;
	}
	else if (check_radio == IDC_Bin)
	{
		bool check_bin = true;
		check_bin = checkBin(num);
		if (!check_bin)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Bin"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 2;
	}
	else if (check_radio == IDC_Hex) {
		bool check_hex = true;
		check_hex = checkHex(num);
		if (!check_hex)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Hex"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 16;
	}
	else {
		MessageBox(_T("Ban chua chon he bieu dien"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Đưa giá trị vừa nhập vào QInt
	QInt temp;
	if (!temp.Scan(num, check_radio)) {
		MessageBox(_T("Ban nhap so thu hai vuot qua kieu du lieu"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Xuất kết quả hệ Dec
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
	//Xuất kết quả hệ Bin
	CString result_bin1 = _T("");
	CString result_bin2 = _T("");
	string bin = temp.getBin();
	result_bin1 = bin.substr(0, 64).c_str();
	result_bin2 = bin.substr(64).c_str();

	CWnd* label_bin1 = GetDlgItem(IDC_KQBin1);
	label_bin1->SetWindowText(result_bin1);
	CWnd* label_bin2 = GetDlgItem(IDC_KQBin2);
	label_bin2->SetWindowText(result_bin2);

	//Xuất kết quả hệ Hex
	CString result_hex1 = _T("");
	string hex = temp.getHex();
	result_hex1 = hex.substr(0, 64).c_str();
	//
	CWnd* label_hex1 = GetDlgItem(IDC_KQHex);
	label_hex1->SetWindowText(result_hex1);
}

//Hàm xử lí sự kiện khi nhấn nút tính toán
void CQInt::OnBnClickedTinhtoan()
{
	//Lấy dữ liệu số thứ nhất
	CEdit* editbox1 = (CEdit*)GetDlgItem(IDC_SoThu1);
	CString Cnum1;
	editbox1->GetWindowText(Cnum1);
	string num1 = CStringA(Cnum1);
	if (num1.length() == 0) {
		MessageBox(_T("Ban chua nhap du lieu so thu nhat"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Lấy dữ liệu số thứ hai
	CEdit* editbox2 = (CEdit*)GetDlgItem(IDC_SoThu2);
	CString Cnum2;
	editbox2->GetWindowText(Cnum2);
	string num2 = CStringA(Cnum2);
	if (num2.length() == 0) {
		MessageBox(_T("Ban chua nhap du lieu so thu hai"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Kiểm tra hệ biểu diễn
	int check_radio = GetCheckedRadioButton(IDC_Dec, IDC_Hex);
	if (check_radio == IDC_Dec) {
		bool check_dec1 = true;
		bool check_dec2 = true;
		check_dec1 = checkDec(num1);
		check_dec2 = checkDec(num2);
		if (!check_dec1 || !check_dec2)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Dec"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 10;
	}
	else if (check_radio == IDC_Bin)
	{
		bool check_bin1 = true;
		bool check_bin2 = true;
		check_bin1 = checkBin(num1);
		check_bin2 = checkBin(num2);
		if (!check_bin1 || !check_bin2)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Bin"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 2;
	}
	else if (check_radio == IDC_Hex) {
		bool check_hex1 = true;
		bool check_hex2 = true;
		check_hex1 = checkHex(num1);
		check_hex2 = checkHex(num2);
		if (!check_hex1 || !check_hex2)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Hex"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 16;
	}
	else {
		MessageBox(_T("Ban chua chon he bieu dien"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Đưa dữ liệu vào QInt
	QInt a;
	if( !a.Scan(num1, check_radio)) {
		MessageBox(_T("Ban nhap so thu nhat vuot qua kieu du lieu"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	QInt b;
	if (!b.Scan(num2, check_radio)) {
		MessageBox(_T("Ban nhap so thu hai vuot qua kieu du lieu"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	
	//Thực hiện tính toán dựa vào lựa chọn tính toán
	QInt result;
	int temp;
	int check_tinhtoan = GetCheckedRadioButton(IDC_Cong, IDC_XoayPhai);
	switch(check_tinhtoan)
	{
	case IDC_Cong:
		result = a + b;
		break;
	case IDC_Tru:
		result = a - b;
		break;
	case IDC_Nhan:
		result = a * b;
		break;
	case IDC_Chia:
		result = a / b;
		break;
	case IDC_DU:
		result = a % b;
		break;
	case IDC_And:
		result = a & b;
		break;
	case IDC_Or:
		result = a | b;
		break;
	case IDC_Xor:
		result = a ^ b;
		break;
	case IDC_Not:
		result = ~a;
		break;
	case IDC_DichTrai:
		temp = atoi(num2.c_str());
		result = a <<temp ;
		break;
	case IDC_DichPhai:
		temp = atoi(num2.c_str());
		result = a >> temp;
		break;
	case IDC_XoayTrai:
		temp = atoi(num2.c_str());
		result = a.rol(temp);
		break;
	case IDC_XoayPhai:
		temp = atoi(num2.c_str());
		result = a.ror(temp);
		break;
	default:
		MessageBox(_T("Ban chua chon phep tinh toan"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}

	//Xuất kết quả
	CString result_dec1 = _T("");
	CString result_dec2 = _T("");
	string dec = result.getDec();
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
	string bin = result.getBin();
	result_bin1 = bin.substr(0, 64).c_str();
	result_bin2 = bin.substr(64).c_str();
	//
	CWnd* label_bin1 = GetDlgItem(IDC_KQBin1);
	label_bin1->SetWindowText(result_bin1);
	CWnd* label_bin2 = GetDlgItem(IDC_KQBin2);
	label_bin2->SetWindowText(result_bin2);

	//Hex
	CString result_hex1 = _T("");
	string hex = result.getHex();
	result_hex1 = hex.substr(0, 64).c_str();
	//
	CWnd* label_hex1 = GetDlgItem(IDC_KQHex);
	label_hex1->SetWindowText(result_hex1);
	//
	CWnd* label_sosanh = GetDlgItem(IDC_KQSoSanh);
	label_sosanh->SetWindowText(L"");
}

//Hàm xử lí sự kiện khi nhấn nút so sánh
void CQInt::OnBnClickedSosanh()
{
	//Lấy dữ liệu số thứ nhất
	CEdit* editbox1 = (CEdit*)GetDlgItem(IDC_SoThu1);
	CString Cnum1;
	editbox1->GetWindowText(Cnum1);
	string num1 = CStringA(Cnum1);
	if (num1.length() == 0) {
		MessageBox(_T("Ban chua nhap du lieu so thu nhat"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Lấy dữ liệu số thứ hai
	CEdit* editbox2 = (CEdit*)GetDlgItem(IDC_SoThu2);
	CString Cnum2;
	editbox2->GetWindowText(Cnum2);
	string num2 = CStringA(Cnum2);
	if (num2.length() == 0) {
		MessageBox(_T("Ban chua nhap du lieu so thu hai"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Kiểm tra hệ biểu diễn
	int check_radio = GetCheckedRadioButton(IDC_Dec, IDC_Hex);
	if (check_radio == IDC_Dec) {
		bool check_dec1 = true;
		bool check_dec2 = true;
		check_dec1 = checkDec(num1);
		check_dec2 = checkDec(num2);
		if (!check_dec1 || !check_dec2)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Dec"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 10;
	}
	else if (check_radio == IDC_Bin)
	{
		bool check_bin1 = true;
		bool check_bin2 = true;
		check_bin1 = checkBin(num1);
		check_bin2 = checkBin(num2);
		if (!check_bin1 || !check_bin2)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Bin"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 2;
	}
	else if (check_radio == IDC_Hex) {
		bool check_hex1 = true;
		bool check_hex2 = true;
		check_hex1 = checkHex(num1);
		check_hex2 = checkHex(num2);
		if (!check_hex1 || !check_hex2)
		{
			MessageBox(_T("Ban da nhap sai du lieu he Hex"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		check_radio = 16;
	}
	else {
		MessageBox(_T("Ban chua chon he bieu dien"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Đưa dữ liệu vào QInt
	QInt a;
	if (!a.Scan(num1, check_radio)) {
		MessageBox(_T("Ban nhap so thu nhat vuot qua kieu du lieu"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	QInt b;
	if (!b.Scan(num2, check_radio)) {
		MessageBox(_T("Ban nhap so thu hai vuot qua kieu du lieu"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Thực hiện so sánh
	int check_tinhtoan = GetCheckedRadioButton(IDC_Lon,IDC_BeBang);
	bool check= false;
	switch(check_tinhtoan) {
	case IDC_Lon:
		if(a>b)
			check = true;
		break;
	case IDC_Be:
		if (a < b)
			check = true;
		break;
	case IDC_Bang:
		if (a == b)
			check = true;
		break;
	case IDC_LonBang:
		if (a >= b)
			check = true;
		break;
	case IDC_BeBang:
		if (a <= b)
			check = true;
		break;
	default:
		MessageBox(_T("Ban chua chon phep so sanh"), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	//Xuất kết quả
	CWnd* label_sosanh = GetDlgItem(IDC_KQSoSanh);
	if(check)
		label_sosanh->SetWindowText(L"TRUE");
	else
		label_sosanh->SetWindowText(L"FALSE");
	//
	CWnd* label_dec1 = GetDlgItem(IDC_KQDec1);
	CWnd* label_dec2 = GetDlgItem(IDC_KQDec2);
	CWnd* label_bin1 = GetDlgItem(IDC_KQBin1);
	CWnd* label_bin2 = GetDlgItem(IDC_KQBin2);
	CWnd* label_hex = GetDlgItem(IDC_KQHex);
	label_dec1->SetWindowText(L"0");
	label_dec2->SetWindowText(L"0");
	label_bin1->SetWindowText(L"0");
	label_bin2->SetWindowText(L"0");
	label_hex->SetWindowText(L"0");
}

//Hàm xử lí sự kiện khi nhấn nút reset giá trị về 0 và rỗng
void CQInt::OnBnClickedReset()
{
	CWnd* label_dec1 = GetDlgItem(IDC_KQDec1);
	CWnd* label_dec2 = GetDlgItem(IDC_KQDec2);
	CWnd* label_bin1 = GetDlgItem(IDC_KQBin1);
	CWnd* label_bin2 = GetDlgItem(IDC_KQBin2);
	CWnd* label_hex = GetDlgItem(IDC_KQHex);
	CWnd* label_sosanh = GetDlgItem(IDC_KQSoSanh);
	label_dec1->SetWindowText(L"0");
	label_dec2->SetWindowText(L"0");
	label_bin1->SetWindowText(L"0");
	label_bin2->SetWindowText(L"0");
	label_hex->SetWindowText(L"0");
	label_sosanh->SetWindowText(L"");
	CEdit* editbox1 = (CEdit*)GetDlgItem(IDC_SoThu1);
	editbox1->SetWindowText(L"");
	CEdit* editbox2 = (CEdit*)GetDlgItem(IDC_SoThu2);
	editbox2->SetWindowText(L"");
}
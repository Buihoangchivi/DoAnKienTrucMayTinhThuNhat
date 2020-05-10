#include "XuLySoLon.h"
//Đảo chuỗi
string reverse(string s) {
	string result;
	for (int i = s.length() - 1; i >= 0; i--) {
		result += s[i];
	}
	return result;
}
//hàm nhân 2
string nhan2(string so) {
	int temp = 0;
	string s;
	for (int i = so.length() - 1; i >= 0; i--) {
		if (so[i] != '.') {
			int num = so[i] - '0';
			s += (num * 2 + temp) % 10 + '0';
			temp = (temp + num * 2);
			if (temp >= 10) {
				temp = temp / 10;
			}
			else {
				temp = 0;
			}
		}
		else {
			s += '.';
		}
	}
	if (temp > 0) {
		s += (temp + '0');
	}
	s = reverse(s);

	//Kiem tra phai so thap phan khong
	int check = s.find('.');
	if (check > 0) {
		//Xoa so 0
		int index = -1;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] != '0') {
				index = i;
				break;
			}
		}
		if (index != -1)
		{
			if (s[index] == '.')
				s = s.substr(0, index);
			else
				s = s.substr(0, index + 1);
		}
	}
	return s;
}
//Hàm chia 2 phần nguyên
string chia2(string nguyen) {
	string s;
	int temp = 0;
	if ((nguyen[0] == '1' || nguyen[0] == '0') && nguyen.length() == 1)
		return "0";
	for (int i = 0; i < nguyen.length(); i++) {
		int num = nguyen[i] - '0';
		temp = num + temp * 10;
		if (temp >= 2) {
			s += temp / 2 + '0';
			temp = temp - temp / 2 * 2;
		}
		else
			s += '0';
	}
	int index = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '0') {
			index = i;
			break;
		}
	}
	return s.substr(index);
}
//Hàm chia 2 phần thập phân
string chia2_FracDec(string so) {
	string s;
	int temp = 0;
	bool check = false;
	for (int i = 0; i < so.length(); i++) {
		if (so[i] != '.')
		{
			int num = so[i] - '0';
			temp = num + temp * 10;
			if (temp >= 2) {
				s += temp / 2 + '0';
				temp = temp - temp / 2 * 2;
			}
			else
			{
				if (i < so.length()) {
					s += '0';
				}
			}
		}
		else
		{
			check = true;
			if (s.length() == 0) {
				s = "0.";
			}
			else
				s += '.';
		}
	}
	if (temp > 0) {
		if (check) {
			s += '5';
		}
		else
			s += ".5";
	}
	return s;
}
//Hàm cộng 2 phần nguyên
string Cong(string a, string b)
{
	int i = a.size() - 1;
	int j = b.size() - 1;
	string KetQua = "";
	int temp = 0;
	while (i >= 0 || j >= 0)
	{
		int x = (i >= 0) ? a[i] - '0' : 0;
		int y = (j >= 0) ? b[j] - '0' : 0;
		int Tong = x + y + temp;
		temp = Tong / 10;
		KetQua = (char)(Tong % 10 + '0') + KetQua;
		if (i >= 0)
			i--;
		if (j >= 0)
			j--;
	}
	if (temp > 0)
		KetQua = (char)(temp + '0') + KetQua;
	return KetQua;
}
//Chuẩn hóa phần nhị phân về cùng độ dài
string CongTP(string a, string b)
{
	string KetQua = "";
	ChuanHoaTP(a, b);
	int temp = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] == '.')
		{
			KetQua = '.' + KetQua;
		}
		else
		{
			temp = a[i] - '0' + b[i] - '0' + temp;
			KetQua.insert(0, 1, (char)(temp % 10 + 48));
			temp /= 10;
		}
	}
	if (temp > 0)
	{
		KetQua.insert(0, 1, (char)(temp + 48));
	}
	return KetQua;
}
void ChuanHoaTP(string& a, string& b)
{
	int dodai1 = a.size();
	int dodai2 = b.size();
	if (dodai1 >= dodai2)
	{
		while (dodai1 > dodai2)
		{
			b += '0';
			dodai2++;
		}
	}
	else
	{
		while (dodai2 > dodai1)
		{
			a += '0';
			dodai1++;
		}
	}
}

void ChuanHoaSo0(string& a)
{
	int i = 0;
	if (a[i] == '0')
	{
		if (a == "0") return;
		while (a[i] == '0')
		{
			a.erase(a.begin() + i);
		}
	}
	else
		return;
}
//Chuẩn hóa bit có dấu cách
void ChuanHoaBit(string& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == ' ')
		{
			a.erase(a.begin() + i);
		}
	}
}
//Cộng 2 phần thập phân
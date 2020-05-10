#include "pch.h"
#include "XuLySoNguyenLon.h"

int SoSanh(vector<int> a, vector<int> b)
{
	if (a.size() > b.size())
		return -1;
	if (a.size() < b.size())
		return 1;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] > b[i])
			return -1;
		if (a[i] < b[i])
			return 1;
	}
	return 0;
}

void LoaiBoSo_0(vector<int>& x)
{
	while (x[x.size() - 1] == 0 && x.size() > 1)
	{
		x.pop_back();
	}
}

void Cong(string a, string b, string& ketqua)
{
	ketqua = "";
	ChuanHoa(a, b);
	int temp = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		temp = a[i] - '0' + b[i] - '0' + temp;
		ketqua.insert(0, 1, (char)(temp % 10 + 48));
		temp /= 10;
	}
	if (temp > 0)
	{
		ketqua.insert(0, 1, (char)(temp + 48));
	}
	ChuanHoaSo_0(ketqua);
}

void Tru(string sotru, string sobitru, string& ketqua)
{
	ketqua = "";
	int length = sotru.size();
	while (sobitru.size() < length)
	{
		sobitru.insert(0, 1, '0');
	}

	int sodu = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		if (sotru[i] < sobitru[i] + sodu)
		{
			ketqua.push_back((char)(sotru[i] - sobitru[i] - sodu + 10 + 48));
			sodu = 1;
		}
		else
		{
			ketqua.push_back((char)(sotru[i] - sobitru[i] - sodu + 48));
			sodu = 0;
		}
	}
	reverse(ketqua.begin(), ketqua.end());

	ChuanHoaSo_0(ketqua);
}

void Nhan(string a, int b, string& ketqua)
{

	ketqua = "";
	int temp = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{

		temp = b * (a[i] - '0') + temp;
		ketqua.insert(0, 1, (char)(temp % 10 + 48));
		temp /= 10;

	}
	while (temp > 0)
	{

		ketqua.insert(0, 1, (char)(temp % 10 + 48));
		temp /= 10;

	}
	ChuanHoaSo_0(ketqua);
}

// https://www.geeksforgeeks.org/divide-large-number-represented-string/ (ý tưởng phép chia)
void Chia(string sochia, int sobichia, string& ketqua)
{
	ketqua = "";
	int i = 0;
	int temp = sochia[i] - '0';
	while (temp < sobichia)
	{
		temp = temp * 10 + (sochia[++i] - '0');
	}
	while (i < sochia.size())
	{
		ketqua += (temp / sobichia) + '0';
		temp = (temp % sobichia) * 10 + sochia[++i] - '0';
	}
	if (ketqua.length() == 0)
	{
		ketqua = "0";
	}
	ChuanHoaSo_0(ketqua);
}

string LuyThua(int coso, int somu)
{

	string ketqua = "1";
	for (int i = 0; i < somu; i++)
		Nhan(ketqua, coso, ketqua);
	return ketqua;

}

// sobichia nhỏ
void ChuanHoa(string& a, string& b)
{
	int dodai1 = a.length();
	int dodai2 = b.length();
	if (dodai1 >= dodai2)
	{
		b.insert(0, dodai1 - dodai2, '0');
	}
	else
	{
		a.insert(0, dodai2 - dodai1, '0');
	}
}

// Bỏ các số 0 ở đầu
void ChuanHoaSo_0(string& a)
{
	if (a.length() == 1)
		return;
	int i = 0;
	if (a[i] == '0')
	{
		while (a[i] == '0')
		{
			a.erase(a.begin() + i);

		}
	}
	else
		return;


}
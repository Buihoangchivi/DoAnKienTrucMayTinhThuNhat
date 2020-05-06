#include "Xyuly.h"
void ChuanHoa(string &a, string &b)
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
void ChuanHoaSo0(string &a)
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

void Cong(string a, string b, string &ketqua)
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
	ChuanHoaSo0(ketqua);
}

void Tru(string sotru, string sobitru, string &ketqua)
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

	ChuanHoaSo0(ketqua);
}

void Nhan(string a, int b, string &ketqua)
{
	ketqua = "";
	int temp = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		temp = b * (a[i] - '0') + temp;
		ketqua.insert(0, 1, (char)(temp % 10 + 48));
		temp /= 10;
	}
	if (temp > 0)
	{
		ketqua.insert(0, 1, (char)(temp + 48));
	}
	ChuanHoaSo0(ketqua);
}


// https://www.geeksforgeeks.org/divide-large-number-represented-string/ (ý tưởng phép chia)
void Chia(string sochia, int sobichia, string &ketqua)
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
		temp = (temp%sobichia) * 10 + sochia[++i] - '0';
	}
	if (ketqua.length() == 0)
	{
		ketqua = "0";
	}
	ChuanHoaSo0(ketqua);
}

void LuyThuaCua2(int somu, string &ketqua)
{
	ketqua = "2";
	for (int i = 0; i < somu - 1; i++)
	{
		Nhan(ketqua, 2, ketqua);
	}
	if (somu == 0)
		ketqua = "1";
	ChuanHoaSo0(ketqua);
}
QInt::QInt()
{

	data[0] = data[1] = data[2] = data[3] = 0;

}

bool QInt::getBit(int i)
{

	return (data[i / 32] >> (31 - i % 32)) & 1;

}

void QInt::setBit(int i, bool bit)
{

	if (bit == 0)
		data[i / 32] = (~(1 << (31 - i))) & data[i / 32];
	else
		data[i / 32] = (1 << (31 - i)) | data[i / 32];

}

QInt::QInt(string s)
{

	string temp = s;
	bool dau = 0;
	bool ok = 0;
	if (temp[0] == '-')
	{
		dau = 1;
		temp.erase(temp.begin());
	}
	int cuoi = temp[temp.size() - 1] - '0';
	int dem = 0;
	setBit(dem, cuoi % 2);
	if (dau == 1 && cuoi % 2 == 1)
	{
		ok = 1;
	}

	//Xoa so 0 du thua o dau chuoi
	while (temp.length() > 1 && temp[0] == '0')
		temp.erase(temp.begin());
	//Kiem tra chuoi nhap vao co phai la so 0 hay khong
	if (temp[0] == '0')
	{

		data[0] = data[1] = data[2] = data[3] = 0;
		return;

	}
	dem++;
	while (temp != "1")
	{
		Chia(temp, 2, temp);
		cuoi = temp[temp.size() - 1] - '0';
		if (ok == 1)
			setBit(dem, (cuoi + 1) % 2);
		else
			setBit(dem, (cuoi) % 2);
		if (dau == 1 && cuoi % 2 == 1)
			ok = 1;
		dem++;
	}

	while (dem < 128)
	{
		if (dau == 1 && ok == 1)
		{
			setBit(dem, 1);
		}
		else
		{
			setBit(dem, 0);
		}

		dem++;
	}

}

// sobichia nhỏ

void QInt::ScanQInt()
{

	string qint;
	getline(cin, qint);
	QInt a(qint);
	*this = a;

}

void QInt::PrintQInt()
{

	string ketqua = "0";
	vector<int> c;
	for (int i = 0; i < 127; i++)
	{
		bool bit = getBit(i);
		string b;
		LuyThuaCua2(i, b);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}
	if (getBit(127) == 1)
	{
		string temp;
		LuyThuaCua2(127, temp);
		Tru(temp, ketqua, ketqua);
		ketqua.insert(0, 1, '-');
	}
	else
	{
		bool bit = getBit(127);
		string b;
		LuyThuaCua2(127, b);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}


	cout << ketqua << endl;
}










QInt QInt::operator&(QInt x)
{
	QInt temp;
	char s;
	for (int i = 0; i < 128; i++)
	{
		s = this->getBit(i) + x.getBit(i);
		if (s == 2)
		{
			temp.setBit(i, 1);
		}
		else
			temp.setBit(i, 0);
	}
	return temp;
}

QInt QInt::operator|(QInt x)   /// OR
{
	QInt temp;
	char s;
	for (int i = 0; i < 128; i++)
	{
		s = this->getBit(i) + x.getBit(i);
		if (s == 0)
		{
			temp.setBit(i, 0);
		}
		else
			temp.setBit(i, 1);
	}
	return temp;
}

QInt QInt::operator^(QInt x)		//XOR
{
	QInt temp;
	char s;
	for (int i = 0; i < 128; i++)
	{
		s = this->getBit(i) + x.getBit(i);
		if (s == 1)
		{
			temp.setBit(i, 1);
		}
		else
			temp.setBit(i, 0);
	}
	return temp;
}


QInt QInt::operator~()
{
	QInt temp;
	for (int i = 0; i < 128; i++)
	{
		if (this->getBit(i) == 0)
			temp.setBit(i, 1);
		else
			temp.setBit(i, 0);
	}
	return temp;
}

int QInt:: Vitribitdau()
{
	for (int i = 127; i >= 0; i--)
	{
		if (this->getBit(i) != this->getBit(i - 1))
			return i - 1;
	}
}
QInt QInt::operator<<(int k)
{
	int tmp;
	QInt temp;
	for (int i = 0; i < k; i++)
	{
		temp.setBit(i, 0);
	}
	for (int i = 0; i < 128-k; i++)
	{
		tmp = this->getBit(i);
		temp.setBit(i + k, tmp);
	}
	return temp;
}

QInt QInt::operator>>(int k)
{
	int tmp, pos = this->Vitribitdau();
	QInt temp;
	for (int i = k; i <= pos; i++)
	{
		tmp = this->getBit(i);
		temp.setBit(i-k, tmp);
	}
	for (int i = pos - k + 1; i < 128; i++)
	{
		temp.setBit(i, 0);
	}
	return temp;
}
QInt QInt::ror()
{
	int temp;
	temp = this->getBit(0);
	for (int i = 0; i < 127; i++)
		this->setBit(i, this->getBit(i + 1));
	this->setBit(127, temp);
	return *this;
}
QInt QInt::rol()
{
	int temp;
	temp = this->getBit(127);
	for (int i = 127; i > 0; i--)
		this->setBit(i, this->getBit(i - 1));
	this->setBit(0, temp);
	return *this;
}

QInt QInt::operator=(QInt x)
{
	for (int i = 0; i < 4; i++)
		this->data[i] = x.data[i];
	return *this;
}
bool QInt::operator==(QInt x)
{
	for (int i = 0; i < 128; i++)
	{
		if (this->getBit(i) != x.getBit(i))
			return false;
	}
	return true;
}

bool QInt::operator<(QInt x)
{
	int pos1, pos2;
	pos1 = this->Vitribitdau();
	pos2 = x.Vitribitdau();
	if (pos1 < pos2)
		return true;
	if (pos1 > pos2)
		return false;
	if(pos1==pos2)
	{
		for (int i = pos1; i >= 0; i--)
		{
			if (this->getBit(i) > x.getBit(i))
				return false;
			if (this->getBit(i) < x.getBit(i))
				return true;
		}
		return false;
	}
}

bool QInt::operator>(QInt x)
{
	int pos1, pos2;
	pos1 = this->Vitribitdau();
	pos2 = x.Vitribitdau();
	if (pos1 > pos2)
		return true;
	if (pos1 < pos2)
		return false;
	if (pos1 == pos2)
	{
		for (int i = pos1; i >= 0; i--)
		{
			if (this->getBit(i) < x.getBit(i))
				return false;
			if (this->getBit(i) > x.getBit(i))
				return true;
		}
		return false;
	}
}

bool QInt::operator<=(QInt x)
{
	int pos1, pos2;
	pos1 = this->Vitribitdau();
	pos2 = x.Vitribitdau();
	if (pos1 < pos2)
		return true;
	if (pos1 > pos2)
		return false;
	if (pos1 == pos2)
	{
		for (int i = pos1; i >= 0; i--)
		{
			if (this->getBit(i) > x.getBit(i))
				return false;
			if (this->getBit(i) < x.getBit(i))
				return true;
		}
		return false;
	}
}

bool QInt::operator>=(QInt x)
{
	int pos1, pos2;
	pos1 = this->Vitribitdau();
	pos2 = x.Vitribitdau();
	if (pos1 > pos2)
		return true;
	if (pos1 < pos2)
		return false;
	if (pos1 == pos2)
	{
		for (int i = pos1; i >= 0; i--)
		{
			if (this->getBit(i) < x.getBit(i))
				return false;
			if (this->getBit(i) > x.getBit(i))
				return true;
		}
		return true;
	}
}


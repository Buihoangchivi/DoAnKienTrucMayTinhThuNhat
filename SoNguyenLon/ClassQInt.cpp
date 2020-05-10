#include "ClassQInt.h"
#include "XuLySoLon.h"

QInt::QInt()
{

	data[0] = data[1] = data[2] = data[3] = 0;

}

QInt::~QInt()
{

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

string QInt::convertQIntToDec()
{

	string ketqua = "0", b;
	vector<int> c;
	for (int i = 0; i < 127; i++)
	{
		bool bit = getBit(i);
		b = LuyThua(2, i);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}
	if (getBit(127) == 1)
	{
		b = LuyThua(2, 127);
		Tru(b, ketqua, ketqua);
		ketqua.insert(0, 1, '-');
	}
	else
	{
		bool bit = getBit(127);
		b = LuyThua(2, 127);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}
	return ketqua;

}

vector<bool> QInt::convertDecToBin()
{

	vector<bool> rs;
	for (int i = 127; i >= 0; i--)
		rs.push_back(this->getBit(i));
	return rs;

}

string QInt::convertBinToDec(vector<bool> vbit)
{

	string ketqua = "0", b;
	vector<int> c;
	//reverse(vbit.begin(), vbit.end());
	while (vbit.size() < 128)
	{
		vbit.push_back(0);
	}
	for (int i = 0; i < 128; i++)
	{
		bool bit = vbit[i];
		b = LuyThua(2, i);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}
	if (vbit[127] == 1)
	{
		b = LuyThua(2, 127);
		Tru(b, ketqua, ketqua);
		ketqua.insert(0, 1, '-');
	}
	else
	{
		bool bit = vbit[127];
		b = LuyThua(2, 127);
		Nhan(b, bit, b);
		Cong(ketqua, b, ketqua);
	}
	return ketqua;

}

string QInt::convertBinToHex(vector<bool> bit)
{

	QInt a(QInt::convertBinToDec(bit));
	return a.convertDecToHex();

}

string QInt::convertDecToHex()
{

	string ans = "", s1;
	pair<QInt, QInt> temp;
	QInt a = *this, b("16");
	while (a.data[0] != 0 && a.data[1] != 0 && a.data[2] != 0 && a.data[3] != 0)
	{

		temp = a / b;
		s1 = temp.second.convertQIntToDec(); //So du
		if (s1.length() == 1) //So du tu 0 den 9 (tuong ung tu 0 den 9 trong he hex)
			ans = s1 + ans;
		else //So du tu 10 den 15 (tuong ung tu A den F trong he hex)
			ans = (char)(s1[1] + 'A' - '0') + ans;
		a = temp.first; //Thuong

	}
	return ans;

}

string QInt::convertHexToDec(string s)
{
	
	string ketqua = "0", b;
	vector<int> c;
	int ch = 0;
	bool ok = true;
	if (s[s.length() - 1] == '-') //Kiem tra xem s co am hay khong
	{

		ok = false; //Neu am thi danh dau false
		s.erase(s.end() - 1); //Va xoa dau am, xu ly s nhu 1 so duong

	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9') //So du tu 0 den 9 (tuong ung tu 0 den 9 trong he hex)
			ch = (int)(s[i] - '0');
		else if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'F') //So du tu 10 den 15 (tuong ung tu A den F trong he hex)
			ch = (int)(toupper(s[i]) - 'A') + 10;
		b = LuyThua(16, i); //b = 16 ^ i
		Nhan(b, ch, b); // b = b * ch
		Cong(ketqua, b, ketqua); //ketqua = ketqua * b
	}
	if (!ok) //Neu s la so am thi them dau am vao dau ketqua
		ketqua.insert(ketqua.begin(), '-');
	return ketqua;

}

QInt QInt::operator+(QInt x)
{

	QInt temp;
	char nho = 0, s;
	for (int i = 0; i < 128; i++)
	{

		s = this->getBit(i) + x.getBit(i) + nho;
		if (s == 2)
		{

			temp.setBit(i, 0);
			nho = 1;

		}
		else if (s == 3)
		{

			temp.setBit(i, 1);
			nho = 1;

		}
		else
		{

			temp.setBit(i, s);
			nho = 0;

		}

	}
	return temp;

}

QInt QInt::oppositeNumber()
{
	QInt a("1");
	//So doi la so bu 2 (lay so bu 1 cong voi 1)
	return ~*this + a;
}

QInt QInt::operator-(QInt x)
{

	//Tru x tuong duong voi cong so doi cua x
	return *this + x.oppositeNumber();

}

QInt QInt::operator*(QInt x)
{

	//Q la so bi chia
	//X la so chia
	//A ban dau khoi tao gom 128 bit 0
	QInt a("0"), q = *this;
	//Q1 duoc hieu nhu la bit -1 cua Q
	//Q0 chinh la bit 0 cua Q
	bool q1 = 0, q0;
	for (int i = 0; i < 128; i++)
	{

		//Lay bit 0 cua Q dua vao Q0
		q0 = q.getBit(0);
		//Neu Q0 Q-1 la 10 thi A = A - X
		if (q0 == 1 && q1 == 0)
			a = a - x;
		//Neu Q0 Q-1 la 01 thi A = A + X
		else if (q0 == 0 && q1 == 1)
			a = a + x;
		//Dich phai [A, Q, Q1] 1 don vi
		q1 = q0;
		q = q << 1;
		q.setBit(127, a.getBit(0));
		a = a << 1;

	}
	return q;

}

pair<QInt, QInt> QInt::operator/(QInt x)
{

	QInt a, b, q = *this;
	//Neu So bi chia Q > 0 thi A = 128 bit 0
	//Nguoc lai neu Q < 0 thi A = 128 bit 1
	if (q.getBit(127) == 1)
		for (int i = 0; i < 128; i++)
			a.setBit(i, 1);
	vector<bool> boo;
	for (int i = 0; i < 128; i++)
	{

		//Dich trai [A, Q] 1 bit
		a = a >> 1;
		a.setBit(0, q.getBit(127));
		q = q >> 1;
		//Gan B = A
		b = a;
		//Voi X la so chia
		//Neu A, X trai dau ==> A = A + X 
		//Nguoc lai A, X cung dau ==> A = A - X
		if (a.getBit(127) != x.getBit(127))
			a = a + x;
		else
			a = a - x;
		//Neu A, B cung dau ==> Q0 = 1
		//Nguoc lai A, B trai dau ==> Q0 = 0, A = B
		if (a.getBit(127) == b.getBit(127))
			q.setBit(0, 1);
		else
		{

			q.setBit(0, 0);
			a = b;

		}

	}
	//A la so du
	//Q la thuong neu Q va X cung dau
	//Nguoc lai Q la bu 2 cua thuong neu Q va X trai dau
	if (this->getBit(127) == x.getBit(127))
		return pair<QInt, QInt>(q, a);
	else
		return pair<QInt, QInt>(q.oppositeNumber(), a);

}

bool QInt::operator<(QInt x)
{

	if (this->getBit(127) > x.getBit(127))
		return true;
	else if (this->getBit(127) < x.getBit(127))
		return false;
	else
	{
		for (int i = 126; i >= 0; i--)
		{
			if (this->getBit(i) < x.getBit(i))
				return true;
			if (this->getBit(i) > x.getBit(i))
				return false;
		}
		return false;
	}

}

bool QInt::operator>(QInt x)
{

	if (this->getBit(127) < x.getBit(127))
		return true;
	if (this->getBit(127) > x.getBit(127))
		return false;
	for (int i = 126; i >= 0; i--)
	{
		if (this->getBit(i) > x.getBit(i))
			return true;
		if (this->getBit(i) < x.getBit(i))
			return false;
	}
	return false;

}

bool QInt::operator==(QInt x)
{

	for (int i = 0; i < 128; i++)
		if (this->getBit(i) != x.getBit(i))
			return false;
	return true;

}

bool QInt::operator<=(QInt x)
{

	if (this->getBit(127) > x.getBit(127))
		return true;
	else if (this->getBit(127) < x.getBit(127))
		return false;
	else
	{
		for (int i = 126; i >= 0; i--)
		{
			if (this->getBit(i) < x.getBit(i))
				return true;
			if (this->getBit(i) > x.getBit(i))
				return false;
		}
		return true;
	}

}

bool QInt::operator>=(QInt x)
{

	if (this->getBit(127) < x.getBit(127))
		return true;
	if (this->getBit(127) > x.getBit(127))
		return false;
	for (int i = 126; i >= 0; i--)
	{
		if (this->getBit(i) > x.getBit(i))
			return true;
		if (this->getBit(i) < x.getBit(i))
			return false;
	}
	return true;

}

QInt QInt::operator=(QInt x)
{

	for (int i = 0; i < 4; i++)
		this->data[i] = x.data[i];
	return *this;

}

QInt QInt::operator&(QInt x)
{

	QInt temp;
	char s;
	for (int i = 0; i < 128; i++)
	{
		s = this->getBit(i) + x.getBit(i);
		if (s == 2)
			temp.setBit(i, 1);
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
			temp.setBit(i, 0);
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
			temp.setBit(i, 1);
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

QInt QInt::operator<<(int k)
{

	QInt temp;
	for (int i = 0; i < 128-k; i++)
		temp.setBit(i + k, this->getBit(i));
	return temp;

}

QInt QInt::operator>>(int k)
{

	QInt temp;
	for (int i = 0; i < 128 - k; i++)
		temp.setBit(i, this->getBit(i + k));
	return temp;

}
QInt QInt::ror(int k)
{

	QInt temp;
	for (int i = 0; i < 128 - k; i++)
		temp.setBit(i, this->getBit(i + k));
	int i = 0;
	while (k > 0)
	{
		temp.setBit(128-k, i);
		i++;
		k--;
	}
	return temp;

}
QInt QInt::rol(int k)
{

	QInt temp;
	for (int i = 0; i < 128 - k; i++)
		temp.setBit(i + k, this->getBit(i));
	int i = 0;
	while (k > 0)
	{
		temp.setBit(i, this->getBit(128 - k));
		i++;
		k--;
	}
	return temp;

}

void QInt::ScanQInt()
{
	
	string qint;
	getline(cin, qint);
	QInt a(qint);
	*this = a;

}

void QInt::PrintQInt()
{

	cout << this->convertQIntToDec() << endl;

}

void QInt::Scan(string num, int base)
{
	if (base == 10)
	{
		QInt a(num);
		*this = a;
	}
	else if (base == 2)
	{
		vector<bool> temp;
		int count = 0;
		while (num[count] != '\0')
		{
			temp.push_back(num[count]);
			count++;
		}
		QInt a(convertBinToDec(temp));
	}
	else if (base == 16)
	{
		// convertHexToDec();
	}
}

string QInt::getBin()
{
	vector<bool> temp = this->convertDecToBin();
	string rs;
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		rs += temp[i];
	}
	return rs;
}

string QInt::getDec()
{
	return this->convertQIntToDec();
}

string QInt::getHex()
{
	string rs;
	return rs;
}
#include "Qfloat.h"
//Kiểm tra dãy bit toàn bit 1 và 0
bool KTraBitGiongNhau(string s, char c)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] != c)
			return false;
	return true;
}
bool KiemTraDuLieuHopLe(string Dec)
{
	int DemDauCham = 0;
	int DemDau = 0;
	if (Dec.size() == 0 || (Dec[0] != '-' && (Dec[0]<'0' || Dec[0]>'9')))
	{
		cout << "Du lieu sai!";
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
				cout << "Du lieu sai!";
				return false;
			}
		}
		else if (Dec[i] == '-')
		{
			DemDau++;
			if (DemDau == 2)
			{
				cout << "Du lieu sai!";
				return false;
			}
		}
		else if (Dec[i] < '0' || Dec[i]>'9')
		{
			cout << "Du lieu sai!";
			return false;
		}
	}
	return true;
}
//Ktra trường hợp đặc biệt khi chuyển từ nhị phân sang số chấm động
int KTTHdacbiet (string np) {
	string strExp = np.substr(SIGN_SIZE, EXP_SIZE);
	string strSignif = np.substr(SIGN_SIZE + EXP_SIZE,SIGNIF_SIZE);
	if (KTraBitGiongNhau(strExp, '0'))
	{
		if (KTraBitGiongNhau(strSignif, '0'))
		{
			return 1; // So 0
		}
		else
		{
			return 2; //So khong the chuan hoa
		}
	}
	if (KTraBitGiongNhau(strExp, '1'))
	{
		if (KTraBitGiongNhau(strSignif, '0'))
		{
			return 3; // So vo cung
		}
		else
		{
			return 4; //So bao loi
		}
	}
	return 0; //Khong phai truong hop dac biet
}
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
//Xóa các số 0 dư ở đầu phần nguyên
void ChuanHoaSo0(string &a)
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
void ChuanHoaBit(string &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == ' ')
		{
			a.erase(a.begin() + i);
		}
	}
}
//Chuẩn hóa phần nhị phân về cùng độ dài
void ChuanHoaTP(string &a, string &b)
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
//Cộng 2 phần thập phân
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

Qfloat::Qfloat() {
	data[0] = data[1] = data[2] = data[3] = data[4] = 0;
}
bool Qfloat::getBit(int index)
{
	return (data[index / 32] >> (31 - index % 32)) & 1;
}
void Qfloat::setBit(int index, bool bit)
{
	if (bit == 0)
		data[index / 32] = (~(1 << (31 - index))) & data[index / 32];
	else
		data[index / 32] = (1 << (31 - index)) | data[index / 32];

}
void Qfloat::ScanQfloat()
{
	string result;
	int check = 1;
	do
	{
		cout << "Nhap Qfloat = ";
		string num;
		cin >> num;
		//Dua bit vao data
		result = DecToBin(num);
		if(result != "")
		{
			check = KTTHdacbiet(result);
			if (check > 1) {
				switch (check) {
				case 2:
					cout << "So khong the chuan hoa!!!";
					break;
				case 3:
					cout << "So vo cung!!!";
					break;
				case 4:
					cout << "So bao loi!!!";
					break;
				}
			}
		}
		//Kiem tra truong hop dac biet
		//string result = "01111111111111101111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
		//string result = "000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	/*	int check = KTTHdacbiet(result);
		if (check > 1) {
			switch (check) {
			case 2:
				cout << "So khong the chuan hoa!!!";
				break;
			case 3:
				cout << "So vo cung!!!";
				break;
			case 4:
				cout << "So bao loi!!!";
				break;
			}
		}*/
	} while (check != 0 || result == "");
	for (int i = 0; i < QFLOAT_SIZE; i++) {
		if (result[i] - '0' == 0) {
			setBit(i, 0);
		}
		else {
			setBit(i, 1);
		}
	}
}
string Qfloat::DecToBin(string num)
{
	bool KTra = KiemTraDuLieuHopLe(num);
	if (KTra == false)
	{
		return "";
	}
	//Kiem tra so nhap vao phai 0 khong?
	bool check = true;
	for(int i=0;i<num.length();i++){
		if(num[i]!='.') {
			if (num[i] != '0'){
				check = false;
				break;
			}	
		}
	}
	if (check) {
		string s;
		for (int i = 0; i < QFLOAT_SIZE; i++) {
			s += '0';
		}
		return s;
	}
	//Vi tri so 1 dau tien
	int pos_1 = -1;
	//Chuyen phan nguyen qua nhi phan
	//Vi tri dau "." trong chuoi num
	int index = num.find('.');
	if (index < 0) {
		num += ".0";
	}
	index = num.find('.');
	string IntDec;
	if (num[0] == '-')
		IntDec = num.substr(1, index - 1);
	else
		IntDec = num.substr(0, index);
	string IntBin = "";
	while (IntDec != "0") {
		if ((IntDec[IntDec.length() - 1] - '0') % 2 == 0) {
			IntBin = '0' + IntBin;
		}
		else {
			IntBin = '1' + IntBin;
		}
		IntDec = chia2(IntDec);
	}
	if (IntBin.length() == 0)
		IntBin += '0';
	else
		pos_1 = 0;
	string FracBin = "";
	string FracDec = "0" + num.substr(index);
	int Exp;
	int sophantri;
	if(pos_1==-1) {
		while (1) {
			FracDec = nhan2(FracDec);
			if (FracDec[0] == '0') {
				FracBin += '0';
				if (FracDec == "0") {
					break;
				}
			}
			else {
				FracBin += '1';
				pos_1 = IntBin.length() + FracBin.length();
				FracDec[0] = '0';
				break;
				if (FracDec == "1") {
					break;
				}
			}
		}
		Exp = IntBin.length() - pos_1;
		sophantri = SIGNIF_SIZE - Exp;
		Exp += K;
		int dem_phantri = 0;
		//Chuyen phan thap phan qua nhi phan
		while (1) {
			FracDec = nhan2(FracDec);
			if (FracDec[0] == '0') {
				FracBin += '0';
				if (FracDec == "0") {
					break;
				}
			}
			else {

				FracBin += '1';
				if (FracDec == "1") {
					break;
				}
				FracDec[0] = '0';
			}
			dem_phantri++;
			if (dem_phantri > 112)
				break;
		}
	}
	else {
		Exp = IntBin.length() - 1;
		sophantri = SIGNIF_SIZE - Exp;
		Exp += K;
		int dem_phantri = 0;
		//Chuyen phan thap phan qua nhi phan
		while (1) {
			FracDec = nhan2(FracDec);
			if (FracDec[0] == '0') {
				FracBin += '0';
				if (FracDec == "0") {
					break;
				}
			}
			else {

				FracBin += '1';
				if (FracDec == "1") {
					break;
				}
				FracDec[0] = '0';
			}
			dem_phantri++;
			if(dem_phantri>sophantri) 
				break;
		}
	}

	//Luu vo bien np
	string np = IntBin +"."+ FracBin;
	/*if(num[0]=='-')
	{
		np = '-' + IntBin + '.' + FracBin;
	}
	else
	  np = IntBin + "." + FracBin;
	*/

	//
	string s = "";
	string e = "";
	string m = "";
	if (num[0] == '-')
		s += '1';
	else
		s += '0';

	//vi tri dau "." trong chuoi nhi phan
	//Chuyen e ra nhi phan
	string _e = "";
	//Dung bien temp de tinh phan tri
	int temp = Exp-K;
	//Chuyen so mu qua nhi phan roi dua vao chuoi e
	while (Exp != 0) {
		char x = Exp % 10 + '0';
		_e = x + _e;
		Exp = Exp / 10;
	}

	//Kich co cua exp
	int size_e = 0;
	while (_e != "0") {
		if ((_e[_e.length() - 1] - '0') % 2 == 0) {
			e = '0' + e;
		}
		else {
			e = '1' + e;
		}
		size_e++;
		if(size_e==EXP_SIZE) {
			break;
		}
		_e = chia2(_e);
	}

	//Chua du 15 bit thi them 0 vao de du 15 bit
	if (e.length() < EXP_SIZE) {
		int n = e.length();
		for (int i = 0; i < EXP_SIZE - n; i++) {
			e = '0' + e;
		}
	}

	//Luu phan tri m
	int temp2 = IntBin.length() - temp;
	if (temp < 0)
		temp2++;
	//Kich co cua m
	int size_m = 0;
	for (int i = temp2; i < np.length(); i++) {
		if (np[i] != '.')
		{
			m += np[i];
			size_m++;
			if (size_m == SIGNIF_SIZE)
				break;
		}
	}
	//Neu khong du 112 bit thi them '0' vao cho du 
	if (m.length() < SIGNIF_SIZE) {
		int n = m.length();
		for (int i = 0; i < SIGNIF_SIZE - n; i++) {
			m += '0';
		}
	}
	return s + e + m;
}
string Qfloat::BinToDec(string s)
{
	ChuanHoaBit(s);
	//Kiem tra du lieu dua vao
	if (s.size() != QFLOAT_SIZE) //128
	{
		cout << "Du lieu sai!";
		return "";
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '0' && s[i] != '1')
		{
			cout << "Du lieu sai!";
			return "";
		}
	}
	//Kiem tra truong hop dac biet
	int check = KTTHdacbiet(s);
	if(check >0) {
		switch(check) {
		case 1:
			return "0";
		case 2:
			cout << "So khong the chuan hoa!!!";
			break;
		case 3:
			cout << "So vo cung!!!";
			break;
		case 4:
			cout << "So bao loi!!!";
			break;
		}
		return "";
	}
	string strSign = s.substr(0, SIGN_SIZE);
	string strExp = s.substr(SIGN_SIZE, EXP_SIZE); //1, 15
	string strSignif = s.substr(SIGN_SIZE + EXP_SIZE, SIGNIF_SIZE);// 16,112
	string Sign = "";
	if (strSign == "1")
		Sign = "-";
	
	//Tính giá trị Exp;
	string ExpDec = "0";
	string temp = "1";
	if (strExp[strExp.size() - 1] == '1')
		ExpDec = "1";
	for (int i = strExp.size() - 2; i >= 0; i--)
	{
		temp = nhan2(temp);
		if (strExp[i] == '1')
		{
			ExpDec = Cong(ExpDec, temp);
		}
	}
	//CHuyển giá trị sang int 
	int _Exp = 0;
	for (int i = 0; i < ExpDec.size(); i++)
	{
		_Exp = _Exp * 10 + ExpDec[i] - '0';
	}
	int Exp = _Exp - 16383;//K

	//Tìm phần nguyên và phần thập phân ở hệ 2
	string IntBin = "1";
	string FracBin = strSignif;
	while (Exp != 0)
	{
		if (Exp > 0)
		{
			IntBin += FracBin[0];
			FracBin.erase(0, 1);
			FracBin += '0';
			Exp--;
		}
		else
		{
			FracBin = IntBin[IntBin.size() - 1] + FracBin;
			IntBin.erase(IntBin.size() - 1, 1);
			IntBin = '0' + IntBin;
			Exp++;
		}
	}
	//Xóa số 0 dư trước phần nguyên và số 0 dư sau phần thập phân
	ChuanHoaSo0(IntBin);
	while (FracBin.size() > 1 && FracBin[FracBin.size() - 1] == '0')
		FracBin.erase(FracBin.size() - 1, 1);

	//Chuyển phần nguyên sang hệ 10
	string IntDec = "0";
	temp = "1";
	if (IntBin[IntBin.size() - 1] == '1')
		IntDec = "1";
	if (IntBin.size() > 1)
	{
		for (int i = IntBin.size() - 2; i >= 0; i--)
		{
			temp = nhan2(temp);
			if (IntBin[i] == '1')
			{
				IntDec = Cong(IntDec, temp);
			}
		}
	}
	//Chuyển phần thập phân sang hệ 10
	string FracDec = "0.0";
	temp = "1";
	for (int i = 0; i < FracBin.size(); i++)
	{
		temp = chia2_FracDec(temp);
		if (FracBin[i] == '1')
		{
			FracDec = CongTP(FracDec, temp);
		}
	}
	FracDec = FracDec.substr(2, FracDec.size() - 2);
	string KetQua = "";
	if (FracDec == "0")
		KetQua = Sign + IntDec;
	else
		KetQua = Sign + IntDec + '.' + FracDec;
	return KetQua;
}
void Qfloat::PrintQfloat()
{
	string s = "";
	for (int i = 0; i < QFLOAT_SIZE; i++)
	{
		if (getBit(i))
		{
			s += '1';
		}
		else
			s += '0';
	}
	string KetQua = BinToDec(s);
	cout << KetQua << endl;
}
Qfloat Qfloat::operator=(Qfloat x)
{
	for (int i = 0; i < 4; i++)
		this->data[i] = x.data[i];
	return *this;
}

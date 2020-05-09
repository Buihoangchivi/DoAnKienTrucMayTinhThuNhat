#include "ClassQfloat.h"
//Kiểm tra dãy bit toàn bit 1 và 0
bool KTraBitGiongNhau(string s, char c)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] != c)
			return false;
	return true;
}
bool CheckDataBin(string Bin)
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
bool CheckData(string Dec)
{
	int DemDauCham = 0;
	int DemDau = 0;
	if (Dec.size() == 0 || (Dec[0] != '-' && (Dec[0]<'0' || Dec[0]>'9')))
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

ClassQfloat::ClassQfloat() {
	data[0] = data[1] = data[2] = data[3] = data[4] = 0;
}

ClassQfloat::ClassQfloat(string num)
{
	data[0] = data[1] = data[2] = data[3] = data[4] = 0;
	//Dua bit vao data
	string result = ConvertDecToBin(num);
	int check;
	if (result != "")
	{
		check = KTTHdacbiet(result);
		if (check > 1) {
			switch (check) {
			case 2:
				cout << "So khong the chuan hoa!!!" << endl;
				break;
			case 3:
				cout << "So vo cung!!!" << endl;
				break;
			case 4:
				cout << "So bao loi!!!" << endl;
				break;
			}
		}
		else {
			for (int i = 0; i < QFLOAT_SIZE; i++) {
				if (result[i] - '0' == 0) {
					setBit(i, 0);
				}
				else {
					setBit(i, 1);
				}
			}
		}
	}
	else {
		cout << "So nhap vuot qua kieu du lieu co the bieu dien" << endl;
	}
}

bool ClassQfloat::getBit(int index)
{
	return (data[index / 32] >> (31 - index % 32)) & 1;
}

void ClassQfloat::setBit(int index, bool bit)
{
	if (bit == 0)
		data[index / 32] = (~(1 << (31 - index))) & data[index / 32];
	else
		data[index / 32] = (1 << (31 - index)) | data[index / 32];

}
void ClassQfloat::ScanQfloat(int base)
{
	string result;
	string Num;
	if (base == 10)
	{
		int check = 1;
		do
		{
			cout << "Nhap Qfloat = ";
			cin >> Num;
			//Dua bit vao data
			result = ConvertDecToBin(Num);
			if (result != "")
			{
				check = KTTHdacbiet(result);
				if (check > 1) {
					switch (check) {
					case 2:
						cout << "So khong the chuan hoa!!!" << endl;
						break;
					case 3:
						cout << "So vo cung!!!" << endl;
						break;
					case 4:
						cout << "So bao loi!!!" << endl;
						break;
					}
				}
			}
			else {
				cout << "So nhap vuot qua kieu du lieu co the bieu dien" << endl;
			}
		} while ((check > 1) || (result == ""));
	}
	else if (base == 2)
	{
		bool check_bin;
		do
		{
			cout << "Nhap Qfloat (day bin day du 128 bit) = ";
			cin >> Num;
			check_bin = CheckDataBin(Num);
			if (check_bin == false)
			{
				cout << "Du lieu sai!!!" << endl;
			}
		} while (check_bin == false);
		result = Num;
	}
	for (int i = 0; i < QFLOAT_SIZE; i++) {
		if (result[i] - '0' == 0) {
			setBit(i, 0);
		}
		else {
			setBit(i, 1);
		}
	}
}
void ClassQfloat::ScanQfloat(string Num, int base)
{
	string result;
	bool check_bin = true;
	int check = 0;
	if (base == 10)
	{
		//Dua bit vao data
		result = ConvertDecToBin(Num);
		if (result != "")
		{
			check = KTTHdacbiet(result);
			if (check > 1) {
				switch (check) {
				case 2:
					cout << "So khong the chuan hoa!!!" << endl;
					break;
				case 3:
					cout << "So vo cung!!!" << endl;
					break;
				case 4:
					cout << "So bao loi!!!" << endl;
					break;
				}
			}
		}
		else {
			cout << "So nhap vuot qua kieu du lieu co the bieu dien" << endl;
		}
	}
	else if (base == 2)
	{
		check_bin = CheckDataBin(Num);
		if (check_bin == false)
		{
			cout << "Du lieu sai!!!" << endl;
		}
		result = Num;
	}
	if (check_bin == true || check == 0)
	{
		for (int i = 0; i < QFLOAT_SIZE; i++) {
			if (result[i] - '0' == 0) {
				setBit(i, 0);
			}
			else {
				setBit(i, 1);
			}
		}
	}
}
string ClassQfloat::BinToDec()
{
	string bin = "";
	for (int i = 0; i < QFLOAT_SIZE; i++)
	{
		if (getBit(i))
		{
			bin += '1';
		}
		else
			bin += '0';
	}
	return ConvertBinToDec(bin);
}
string ClassQfloat::DectoBin()
{
	string bin = "";
	for (int i = 0; i < QFLOAT_SIZE; i++)
	{
		if (getBit(i))
		{
			bin += '1';
		}
		else
			bin += '0';
	}
	return bin;
}
string ClassQfloat::ConvertBinToDec(string s)
{
	ChuanHoaBit(s);
	//Kiem tra du lieu dua vao
	bool check_data = CheckDataBin(s);
	if (check_data == false)
	{
		cout << "Du lieu sai!!!" << endl;
		return "";
	}
	//Kiem tra truong hop dac biet
	int check = KTTHdacbiet(s);
	if(check >0) {
		switch(check) {
		case 1:
			return "0";
		case 2:
			cout << "So khong the chuan hoa!!!" << endl;
			break;
		case 3:
			cout << "So vo cung!!!" << endl;
			break;
		case 4:
			cout << "So bao loi!!!" << endl;
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
string ClassQfloat::ConvertDecToBin(string num)
{
	bool check_data = CheckData(num);
	if (check_data == false)
	{
		cout << "Du lieu sai!!!" << endl;
		return "";
	}
	//Kiem tra so nhap vao phai 0 khong?
	bool check_0 = true;
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '-')
		{
			continue;
		}
		if (num[i] != '.') {
			if (num[i] != '0') {
				check_0 = false;
				break;
			}
		}
	}
	if (check_0) {
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
	int pos_dots = num.find('.');
	if (pos_dots < 0) {
		num += ".0";
	}
	pos_dots = num.find('.');
	string IntDec;
	if (num[0] == '-')
		IntDec = num.substr(1, pos_dots - 1);
	else
		IntDec = num.substr(0, pos_dots);
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
		pos_1 = 0; //Nếu có phần nguyên thì số 1 phải ở đầu.

	string FracBin = "";
	string FracDec = "0" + num.substr(pos_dots);
	int Exp;
	int Size_Signif;
	bool check_round = false;
	//Xet xem vi tri so 1 dau tien o dau
	//+ So 1 dau tien ở đầu 1xx,0001100101
	//+ So 1 dau tien chua tim thay 0,00000000001010101....
	if (pos_1 == -1) {
		//Vua chuyen thap phan qua nhi phan vao FracBin vua tim so 1 dau tien
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
		//Khi tim duoc so 1 dau tien thi biet exp, Size_Signif toi da
		Exp = IntBin.length() - pos_1;
		Size_Signif = SIGNIF_SIZE;
		Exp += K;
		int count_size_signif = 0;
		//Tiep tuc
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
			count_size_signif++;
			if (count_size_signif == Size_Signif) {
				if (FracDec != "1") {
					check_round = true;
				}
				break;
			}
		}
	}
	else {
		//Truong hop so 1 dau tien o dau
		Exp = IntBin.length() - 1;
		//So phan tu phan tri toi da
		Size_Signif = SIGNIF_SIZE - Exp;
		Exp += K;
		int count_size_signif = 0;
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
			count_size_signif++;
			if (count_size_signif == Size_Signif)
			{
				if (FracDec != "1") {
					check_round = true;
				}
				break;
			}
		}
	}
	//Exp vuot qua khoang gia tri 
	if (Exp < 0 || Exp > 2 * K)
		return "";

	//Luu vo bien np
	string Bin = IntBin + "." + FracBin;
	//

	string Sign_bin = "";
	string Exp_bin = "";
	string Signif_bin = "";
	if (num[0] == '-')
		Sign_bin += '1';
	else
		Sign_bin += '0';

	//vi tri dau "." trong chuoi nhi phan
	//Chuyen e ra nhi phan
	string Exp_dec = "";
	//Dung bien temp de tinh phan tri
	int temp = Exp - K;
	//Chuyen so mu qua nhi phan roi dua vao chuoi e
	while (Exp != 0) {
		char x = Exp % 10 + '0';
		Exp_dec = x + Exp_dec;
		Exp = Exp / 10;
	}

	//Kich co cua exp
	int Size_exp = 0;
	while (Exp_dec != "0") {
		if ((Exp_dec[Exp_dec.length() - 1] - '0') % 2 == 0) {
			Exp_bin = '0' + Exp_bin;
		}
		else {
			Exp_bin = '1' + Exp_bin;
		}
		Size_exp++;
		if (Size_exp == EXP_SIZE) {
			break;
		}
		Exp_dec = chia2(Exp_dec);
	}

	//Chua du 15 bit thi them 0 vao de du 15 bit
	if (Exp_bin.length() < EXP_SIZE) {
		int n = Exp_bin.length();
		for (int i = 0; i < EXP_SIZE - n; i++) {
			Exp_bin = '0' + Exp_bin;
		}
	}

	//Luu phan tri m
	int temp2 = IntBin.length() - temp;
	if (temp < 0)
		temp2++;
	//Kich co cua m
	int Size_signif = 0;
	for (int i = temp2; i < Bin.length(); i++) {
		if (Bin[i] != '.')
		{
			Signif_bin += Bin[i];
			Size_signif++;
			if (Size_signif == SIGNIF_SIZE)
				break;
		}
	}
	//Neu khong du 112 bit thi them '0' vao cho du 
	if (Signif_bin.length() < SIGNIF_SIZE) {
		int n = Signif_bin.length();
		for (int i = 0; i < SIGNIF_SIZE - n; i++) {
			Signif_bin += '0';
		}
	}

	//Kiểm tra xem có làm tròn số không? Có thì làm tròn số.
	if (check_round) {
		if (Sign_bin == "0") {
			for (int i = Signif_bin.length() - 1; i >= 0; i--) {
				if (Signif_bin[i] == '1')
				{
					Signif_bin[i] = '0';
				}
				else {
					Signif_bin[i] = '1';
					break;
				}
			}
		}
		else {
			for (int i = Signif_bin.length() - 1; i >= 0; i--) {
				if (Signif_bin[i] == '0')
				{
					Signif_bin[i] = '1';
				}
				else {
					Signif_bin[i] = '0';
					break;
				}
			}
		}
	}
	return Sign_bin + Exp_bin + Signif_bin;
}
void ClassQfloat::PrintQfloat(int base)
{
	string bin = "";
	for (int i = 0; i < QFLOAT_SIZE; i++)
	{
		if (getBit(i))
		{
			bin += '1';
		}
		else
			bin += '0';
	}
	if (base == 10)
	{
		string result = ConvertBinToDec(bin);
		cout << result << endl;
	}
	else if (base == 2)
	{
		cout << bin << endl;
	}
}
ClassQfloat ClassQfloat::operator=(ClassQfloat x)
{
	for (int i = 0; i < 4; i++)
		this->data[i] = x.data[i];
	return *this;
}
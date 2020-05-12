#define _CRT_SECURE_NO_WARNINGS
#include "ClassQInt.h"

// Hàm kiểm tra dãy nhị phân có hợp lệ không
bool checkBin(string num)
{
	int index = 0;
	while (num[index] != '\0')
	{
		if (num[index] != '0' && num[index] != '1')
			return 0;
		index++;
	}
	return 1;
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
			return 0;
		index++;
	}
	return 1;
}

// Hàm kiểm tra dãy thập lục phân có hợp lệ không
bool checkHex(string num)
{
	int index = 0;
	while (num[index] != '\0')
	{
		if ((num[index] < 48 || num[index]>57) && (num[index] < 65 || num[index]>70))
			return 0;
		index++;
	}
	return 1;
}

// Hàm đọc file và xuất file	
void ReadFileInt()
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	while (getline(cin, str))
	{
		// Lấy cả chuỗi trên 1 dòng
		//getline(cin, str);
		vector<string> str_temp;
		int start = 0, end = 0;
		// Tách chuỗi và đưa vào vector str_temp, nếu size của Str_temp = 3 thì là chuyển đổi, bằng 4 là tính toán
		while (str[end] != '\0')
		{
			while (str[end] != ' ' && end < str.size() - 1)
			{
				end++;
			}
			if (start == 0)
			{
				str_temp.push_back(str.substr(start, end - start));
			}
			else if (end == str.size() - 1)
			{
				str_temp.push_back(str.substr(start + 1, end - start));
			}
			else
			{
				str_temp.push_back(str.substr(start + 1, end - start - 1));
			}
			start = end;
			end++;
		}
		// Thực hiện chuyển đổi
		if (str_temp.size() == 3)
		{
			string p1, p2, a;
			p1 = str_temp[0];
			p2 = str_temp[1];
			a = str_temp[2];
			QInt qint;
			// Dấu ~ là trường hợp đặc biệt, xử lý riêng
			if (p2 != "~")
			{
				// Thập -> Nhị
				if (p1 == "10" && p2 == "2")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkDec(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Nếu hợp lệ thì đưa dãy nhị phân vào vector<bool>
					if (!qint.Scan(a, 10))
					{
						cout << "Overflow!!!";
						continue;
					}
					else
					{
						vector<bool> temp = qint.convertDecToBin();
						for (int i = 0; i < temp.size(); i++)
						{
							cout << temp[i];
						}
					}
				}
				// Nhị -> Thập
				else if (p1 == "2" && p2 == "10")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkBin(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Nếu hợp lệ thì chuyển nhị phân vào trong vector<bool> 
					if (!qint.Scan(a, 2))
					{
						cout << "Overflow!!!";
						continue;
					}
					// Xuất dãy thập phân
					string lul = qint.convertQIntToDec();
					cout << lul;
				}
				// Nhị -> Thập Lục
				else if (p1 == "2" && p2 == "16")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkBin(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Nếu hợp lệ thì đưa dãy nhị phân vào vector<bool>
					if (!qint.Scan(a, 2))
					{
						cout << "Overflow!!!";
						continue;
					}
					// Xuất dãy thập lục phân
					vector<bool> temp;
					for (int j = a.size() - 1; j >= 0; j--)
					{
						temp.push_back(a[j] - '0');
					}
					string lul = qint.convertBinToHex(temp);
					cout << lul;
				}
				// Thập lục -> Nhị
				else if (p1 == "16" && p2 == "2")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkHex(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Nếu hợp lệ thì chuyển dãy thập lục phân sang thập phân
					if (!qint.Scan(a, 16))
					{
						cout << "Overflow!!!";
						continue;
					}
					// Xuất dãy nhị phân
					vector<bool> temp = qint.convertDecToBin();
					for (int i = 0; i < temp.size(); i++)
					{
						cout << temp[i];
					}
				}
				// Thập -> Thập lục
				else if (p1 == "10" && p2 == "16")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkDec(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Nếu hợp lệ thìxuất dãy thập lục phân
					if (!qint.Scan(a, 10))
					{
						cout << "Overflow!!!";
						continue;
					}
					cout << qint.convertDecToHex();
				}
				// Thập lục -> Thập
				else if (p1 == "16" && p2 == "10")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkHex(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Nếu hợp lệ thì chuyển dãy thập lục phân sang thập phân
					if (!qint.Scan(a, 16))
					{
						cout << "Overflow!!!";
						continue;
					}
					qint.PrintQInt();
				}
			}
			else
			{
				if (p1 == "2")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkBin(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Nếu hợp lệ thì đưa dãy nhị phân vào vector<bool>
					if (!qint.Scan(a, 2))
					{
						cout << "Overflow!!!";
						continue;
					}
				}
				else if (p1 == "10")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkDec(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Nếu hợp lệ thì tính toán luôn
					if (!qint.Scan(a, 10))
					{
						cout << "Overflow!!!";
						continue;
					}
				}
				else if (p1 == "16")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkHex(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Nếu hợp lệ thì chuyển dãy thập lục phân sang thập phân
					if (!qint.Scan(a, 16))
					{
						cout << "Overflow!!!";
						continue;
					}
				}
				QInt rs = ~qint;
				rs.PrintQInt();
			}

		}
		// Thực hiện tính toán
		else if (str_temp.size() == 4)
		{
			string p, a, b, c;
			p = str_temp[0];
			a = str_temp[1];
			b = str_temp[2];
			c = str_temp[3];
			QInt qint;
			// Các phép toán này đi sau sẽ là số int k
			if (b == "<<" || b == ">>" || b == "rol" || b == "ror")
			{
				// Nhị phân
				if (p == "2")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkBin(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Hợp lệ thì chuyển sang thập phân
					if (!qint.Scan(a, 2))
					{
						cout << "Overflow!!!";
						continue;
					}
				}
				// Thập phân
				else if (p == "10")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkDec(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Thập phân ta có thể tính toán được mà không cần chuyển
					if (!qint.Scan(a, 10))
					{
						cout << "Overflow!!!";
						continue;
					}
				}
				// Thập lục
				else if (p == "16")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkHex(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Nếu hợp lệ thì chuyển dãy thập lục phân sang thập phân
					if (!qint.Scan(a, 16))
					{
						cout << "Overflow!!!";
						continue;
					}
				}
				else
				{
					// khác hệ 2,10,16
					cout << "Invalid!!!" << endl;
					continue;
				}
				// number là số int, thể hiện cho các phép toán <<, >>, ror, rol
				int number = atoi(c.c_str());
				if (b == "<<")
				{
					QInt rs = qint << number;
					rs.PrintQInt();
				}
				else if (b == ">>")
				{
					QInt rs = qint >> number;
					rs.PrintQInt();
				}
				else if (b == "ror")
				{
					qint.ror(number);
					qint.PrintQInt();
				}
				else if (b == "rol")
				{
					qint.rol(number);
					qint.PrintQInt();
				}
			}
			// Còn lại sẽ là các phép toán +, -, ...
			else
			{
				QInt qint1;
				QInt qint2;
				// Nhị phân
				if (p == "2")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkBin(a) || !checkBin(c))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Hợp lệ thì chuyển a và c sang thập phân
					if (!qint1.Scan(a, 2))
					{
						cout << "Overflow!!!";
						continue;
					}
					if (!qint2.Scan(c, 2))
					{
						cout << "Overflow!!!";
						continue;
					}
				}
				// Thập phân
				else if (p == "10")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkDec(a) || !checkDec(c))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Thập phân thì có thể tính toán được
					if (!qint1.Scan(a, 10))
					{
						cout << "Overflow!!!";
						continue;
					}
					if (!qint2.Scan(c, 10))
					{
						cout << "Overflow!!!";
						continue;
					}
				}
				// Thập lục phân
				else if (p == "16")
				{
					// Kiểm tra dữ liệu có hợp lệ?
					if (!checkHex(a) || !checkHex(c))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					// Hợp lệ thì chuyển a và c sang thập phân 
					if (!qint1.Scan(a, 16))
					{
						cout << "Overflow!!!";
						continue;
					}
					if (!qint2.Scan(c, 16))
					{
						cout << "Overflow!!!";
						continue;
					}
				}
				else
				{
					// Khác hệ 2,10,16
					cout << "Invalid!!!" << endl;
					continue;
				}
				// Phép toán
				if (b == "+")
				{
					QInt rs = qint1 + qint2;
					rs.PrintQInt();
				}
				else if (b == "-")
				{
					QInt rs = qint1 - qint2;
					rs.PrintQInt();
				}
				else if (b == "*")
				{
					QInt rs = qint1 * qint2;
					rs.PrintQInt();
				}
				else if (b == "/")
				{
					// Chia thì lưu thương
					QInt rs = qint1 / qint2;
					rs.PrintQInt();
				}
				else if (b == "<")
				{
					cout << (qint1 < qint2);
				}
				else if (b == ">")
				{
					cout << (qint1 > qint2);
				}
				else if (b == "==")
				{
					cout << (qint1 == qint2);
				}
				else if (b == "<=")
				{
					cout << (qint1 <= qint2);
				}
				else if (b == ">=")
				{
					cout << (qint1 >= qint2);
				}
				else if (b == "=")
				{
					qint1 = qint2;
					qint1.PrintQInt();
				}
				else if (b == "&")
				{
					QInt rs = qint1 & qint2;
					rs.PrintQInt();
				}
				else if (b == "|")
				{
					QInt rs = qint1 | qint2;
					rs.PrintQInt();
				}
				else if (b == "^")
				{
					QInt rs = qint1 ^ qint2;
					rs.PrintQInt();
				}
			}
		}
		cout << endl;
	}

}

int main()
{

	//string s;
	//cin >> s;
	//for (int i = 0; i < s.length() / 2; i++)
	//	swap(s[i], s[s.length() - i - 1]);
	//cout << QInt::convertHexToDec(s) << endl;
	ReadFileInt();
	/*vector<bool> a;
	string s;
	cin >> s;
	for (int i = s.length() - 1; i >= 0; i--)
		a.push_back((int)(s[i] - '0'));*/
		//QInt b(a);
		//b.PrintQInt();
		//cout << b.convertDecToHex() << endl;
		/*vector<bool> a;
		string s;
		cin >> s;
		for (int i = s.length() - 1; i >= 0; i--)
			a.push_back((int)(s[i] - '0'));
		cout << QInt::convertBinToDec(a) << endl;*/
	/*QInt a;
	string s;
	cin >> s;
	a.ScanQInt(s);
	cout << a.convertDecToHex() << endl;*/
	return 0;

}
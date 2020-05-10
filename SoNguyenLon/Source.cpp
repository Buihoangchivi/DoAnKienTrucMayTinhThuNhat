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
	if (num[index] == '-')
		index++;
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
	// Lấy số dòng n 
	getline(cin, str);
	int num = atoi(str.c_str());
	for (int i = 0; i < num; i++)
	{
		// Lấy cả chuỗi trên 1 dòng
		getline(cin, str);
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
					QInt tmp(a);
					qint = tmp;
					vector<bool> temp = qint.convertDecToBin();
					for (int i = 0; i < temp.size(); i++)
					{
						cout << temp[i];
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
					vector<bool> temp;
					for (int j = a.size() - 1; j >= 0; j--)
					{
						temp.push_back(a[j] - '0');
					}
					// Xuất dãy thập phân
					//cout << qint.convertBinToDec(temp);
					string lul = qint.convertBinToDec(temp);
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
					vector<bool> temp;
					for (int j = a.size() - 1; j >= 0; j--)
					{
						temp.push_back(a[j] - '0');
					}
					// Xuất dãy thập lục phân
					QInt tmp(qint.convertBinToDec(temp));
					qint = tmp;
					cout << qint.convertBinToHex(temp);

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
					string DEC = qint.convertHexToDec(a);
					// Đưa vào qint
					QInt tmp(DEC);
					qint = tmp;
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
					QInt tmp(a);
					qint = a;
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
					string DEC = qint.convertHexToDec(a);
					QInt tmp(DEC);
					qint = tmp;
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
					vector<bool> temp;
					for (int j = a.size() - 1; j >= 0; j--)
					{
						temp.push_back(a[j] - '0');
					}
					string tmp = qint.convertBinToDec(temp);
					qint = tmp;
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
					QInt tmp(a);
					qint = tmp;
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
					string DEC = qint.convertHexToDec(a);
					QInt tmp(DEC);
					qint = tmp;
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
					vector<bool> temp;
					for (int j = a.size() - 1; j >= 0; j--)
					{
						temp.push_back(a[j] - '0');
					}
					QInt tmp(qint.convertBinToDec(temp));
					qint = tmp;
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
					QInt tmp(a);
					qint = tmp;
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
					string DEC = qint.convertHexToDec(a);
					QInt tmp(DEC);
					qint = tmp;
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
					vector<bool> temp1, temp2;
					for (int j = a.size() - 1; j >= 0; j--)
					{
						temp1.push_back(a[j] - '0');
					}
					for (int j = c.size() - 1; j >= 0; j--)
					{
						temp1.push_back(c[j] - '0');
					}
					QInt tmp1(qint1.convertBinToDec(temp1));
					QInt tmp2(qint2.convertBinToDec(temp2));
					qint1 = tmp1;
					qint2 = tmp2;
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
					QInt tmp1(a);
					QInt tmp2(c);
					qint1 = tmp1;
					qint2 = tmp2;

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
					// Nếu hợp lệ thì chuyển dãy thập lục phân sang thập phân
					string DEC1 = qint1.convertHexToDec(a);
					QInt tmp1(DEC1);
					qint1 = tmp1;
					string DEC2 = qint2.convertHexToDec(c);
					QInt tmp2(DEC2);
					qint2 = tmp2;
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
					// Chia thì lưu thương và số dư 
					pair<QInt, QInt> rs = qint1 / qint2;
					rs.first.PrintQInt();
					cout << " ";
					rs.second.PrintQInt();
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
				/*else if (b == "~")
				{
					QInt rs = ~qint1;
					rs.PrintQInt();
				}*/
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
	return 0;

}
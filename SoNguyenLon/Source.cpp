#define _CRT_SECURE_NO_WARNINGS
#include "ClassQInt.h"
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

void ReadFileInt2()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string str;
	getline(cin, str);
	int num = atoi(str.c_str());
	for (int i = 0; i < num; i++)
	{
		getline(cin, str);
		vector<string> str_temp;
		int start = 0, end = 0;
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
		if (str_temp.size() == 3)
		{
			string p1, p2, a;
			p1 = str_temp[0];
			p2 = str_temp[1];
			a = str_temp[2];
			QInt qint(a);
			if (p1 == "10" && p2 == "2")
			{
				if (!checkDec(a))
				{
					cout << "Invalid!!!" << endl;
					continue;
				}
				vector<bool> temp = qint.convertDecToBin();
				for (int i = 0; i < temp.size(); i++)
				{
					cout << temp[i];
				}
			}
			else if (p1 == "2" && p2 == "10")
			{
				if (!checkBin(a))
				{
					cout << "Invalid!!!" << endl;
					continue;
				}
				vector<bool> temp;
				int count = 0;
				while (a[count] != '\0')
				{
					temp.push_back(a[count]);
					count++;
				}
				cout << qint.convertBinToDec(temp);
			}
			else if (p1 == "2" && p2 == "16")
			{
				if (!checkBin(a))
				{
					cout << "Invalid!!!" << endl;
					continue;
				}
				vector<bool> temp;
				int count = 0;
				while (a[count] != '\0')
				{
					temp.push_back(a[count]);
					count++;
				}
				cout << qint.convertBinToHex(temp);
			}
			else if (p1 == "10" && p2 == "16")
			{
				if (!checkDec(a))
				{
					cout << "Invalid!!!" << endl;
					continue;
				}
				cout << qint.convertDecToHex();
			}
		}
		else if (str_temp.size() == 4)
		{
			string p, a, b, c;
			p = str_temp[0];
			a = str_temp[1];
			b = str_temp[2];
			c = str_temp[3];
			QInt qint;
			if (b == "<<" || b == ">>" || b == "rol" || b == "ror")
			{
				if (p == "2")
				{
					if (!checkBin(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					vector<bool> temp;
					int count = 0;
					while (a[count] != '\0')
					{
						temp.push_back(a[count]);
						count++;
					}
					qint.convertBinToDec(temp);
				}
				else if (p == "10")
				{
					if (!checkDec(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
				}
				else if (p == "16")
				{
					if (!checkHex(a))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
					//
				}
				else
				{
					cout << "Invalid!!!" << endl;
					continue;
				}
				//QInt qint(a);
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
			else
			{
				QInt qint1(a);
				QInt qint2(c);
				if (p == "2")
				{
					if (!checkBin(a) || !checkBin(c))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
				}
				else if (p == "10")
				{
					if (!checkDec(a) || !checkDec(c))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
				}
				else if (p == "16")
				{
					if (!checkHex(a) || !checkHex(c))
					{
						cout << "Invalid!!!" << endl;
						continue;
					}
				}
				else
				{
					cout << "Invalid!!!" << endl;
					continue;
				}
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
				else if (b == "~")
				{
					QInt rs = ~qint1;
					rs.PrintQInt();
				}
			}
		}
		cout << endl;
	}

}

int main()
{

	return 0;

}
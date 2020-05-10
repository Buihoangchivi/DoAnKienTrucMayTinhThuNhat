#include "ClassQfloat.h"
#include <time.h>

void ReadFileFlt()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string str;
	getline(cin, str);
	int num = atoi(str.c_str());
	for (int i = 0; i < num; i++)
	{
		double bd = clock();
		//
		getline(cin, str);
		string p1, p2, a;
		int start = 0, end = 0;
		while (str[end] != ' ')
		{
			end++;
		}
		p1 = str.substr(start, end - start);
		start = end;
		end++;
		while (str[end] != ' ')
		{
			end++;
		}

		p2 = str.substr(start + 1, end - start - 1);
		start = end;
		while (str[end] != '\0')
		{
			end++;
		}
		a = str.substr(start + 1, end - start);
		int s1 = atoi(p1.c_str());
		int s2 = atoi(p2.c_str());
		ClassQfloat F;
		F.ScanQfloat(a, s1);
		F.PrintQfloat(s2);
		//
		double kt = clock();
		cout << double(kt - bd) / CLOCKS_PER_SEC << endl;
	}
}
int main()
{
	ReadFileFlt();
	return 0;
}
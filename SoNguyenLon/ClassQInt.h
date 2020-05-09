#pragma once
#include "XuLySoLon.h"
#include <iostream>

class QInt
{

private:
	int data[4];
public:
	QInt();
	QInt(string s);
	bool getBit(int i);
	void setBit(int i, bool bit);
	string convertQIntToDec();
	vector<bool> convertDecToBin();
	static string convertBinToDec(vector<bool> bit);
	static string convertBinToHex(vector<bool> bit);
	string convertDecToHex();
	QInt operator+(QInt x);
	QInt oppositeNumber();
	QInt operator-(QInt x);
	QInt operator*(QInt x);
	//Cap gia tri QInt tra ve trong phep chia la cap thuong va so du
	pair<QInt, QInt> operator/(QInt x);
	bool operator<(QInt x);
	bool operator>(QInt x);
	bool operator==(QInt x);
	bool operator<=(QInt x);
	bool operator>=(QInt x);
	QInt operator=(QInt x);
	QInt operator&(QInt x);
	QInt operator|(QInt x);
	QInt operator^(QInt x);
	QInt operator~();
	QInt operator<<(int k);
	QInt operator>>(int k);
	QInt rol();
	QInt ror();
	int Vitribitdau();
	void ScanQInt();
	void PrintQInt();
};


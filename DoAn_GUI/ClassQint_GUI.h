#pragma once
#include "XuLySoNguyenLon.h"
#include <iostream>

class QInt
{

private:
	//int data[4];
	int* data = new int[4];
public:
	QInt();
	~QInt();
	QInt(string s);
	QInt(vector<bool> vbit);
	bool getBit(int i);
	void setBit(int i, bool bit);
	string convertQIntToDec();
	vector<bool> convertDecToBin();
	static string convertBinToDec(vector<bool> bit);
	static string convertBinToHex(vector<bool> bit);
	string convertDecToHex();
	static string convertHexToDec(string s);
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
	QInt rol(int k);
	QInt ror(int k);
	void ScanQInt();
	void PrintQInt();
	void Scan(string num, int base);
	string getBin();
	string getDec();
	string getHex();
};
#pragma once
#include "XuLySoLon.h"
#include <iostream>

class QInt
{

private:
	//int data[4];
	int *data = new int[4];
public:
	QInt();
	~QInt();
	// Hàm để khởi tạo khi dữ liệu đã hợp lệ, dễ dàng tính toán
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
	// Hàm dùng để đưa dữ liệu vào data và kiểm tra có tràn dữ liệu hay không
	bool ScanQInt(string s);
	void PrintQInt();
	bool Scan(string num, int base);
	string getBin();
	string getDec();
	string getHex();
};


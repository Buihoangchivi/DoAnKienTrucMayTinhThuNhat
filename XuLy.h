#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class QInt
{
private:
	int data[4];
public:
	QInt();
	QInt(string s);
	bool getBit(int i);
	void setBit(int i, bool bit);
	void PrintQInt();
	void ScanQInt();
	QInt operator&(QInt x);
	QInt operator|(QInt x);
	QInt operator^(QInt x);
	QInt operator~();
	QInt operator<<(int k);
	QInt operator>>(int k);
	QInt rol();
	QInt ror();
	bool operator<(QInt x);
	bool operator>(QInt x);
	bool operator==(QInt x);
	bool operator<=(QInt x);
	bool operator>=(QInt x);
	QInt operator=(QInt x);
	int Vitribitdau();
};
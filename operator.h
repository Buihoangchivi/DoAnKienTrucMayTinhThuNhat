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
	bool getBit(int i);
	void setBit(int i, bool bit);
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
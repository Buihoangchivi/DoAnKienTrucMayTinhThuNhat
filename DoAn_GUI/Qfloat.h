#pragma once
#include <iostream>
#include <string>
#include <vector>
#define QFLOAT_SIZE 128
#define K 16383
#define SIGN_SIZE 1
#define EXP_SIZE 15
#define SIGNIF_SIZE 112
using namespace std;
class Qfloat
{
private:
	int* data = new int[4];
public:
	Qfloat();
	Qfloat(string);
	void ScanQfloat(int);
	void ScanQfloat(string, int);
	void PrintQfloat(int);
	static string BinToDec(string);
	static string DecToBin(string);
	string getDec();
	string getBin();
private:
	bool getBit(int index);
	void setBit(int index, bool bit);
	Qfloat operator=(Qfloat);
};

class Qfloat
{
};


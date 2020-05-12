#pragma once
#include <iostream>
#include <string>
#include "XuLySoThucLon.h"
#define QFLOAT_SIZE 128
#define K 16383
#define SIGN_SIZE 1
#define EXP_SIZE 15
#define SIGNIF_SIZE 112
using namespace std;
class ClassQfloat
{
private:
	int* data = new int[4];
public:
	ClassQfloat();
	ClassQfloat(string);
	void ScanQfloat(int);
	void ScanQfloat(string, int);
	void PrintQfloat(int);
	static string ConvertBinToDec(string);
	static string ConvertDecToBin(string);
	string getDec();
	string getBin();
private:
	bool getBit(int index);
	void setBit(int index, bool bit);
	ClassQfloat operator=(ClassQfloat);
};


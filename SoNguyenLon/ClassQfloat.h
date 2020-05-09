#pragma once
#include <iostream>
#include <string>
#include "XuLySoLon.h"
#define QFLOAT_SIZE 128
#define K 16383
#define SIGN_SIZE 1
#define EXP_SIZE 15
#define SIGNIF_SIZE 112
using namespace std;
class ClassQfloat
{
private:
	int *data= new int[4];
public:
	ClassQfloat();
	ClassQfloat(string);
	void ScanQfloat(int);
	void ScanQfloat(string, int);
	void PrintQfloat(int);
	string BinToDec();
	string DectoBin();
private:
	bool getBit(int index);
	void setBit(int index, bool bit);
	string ConvertBinToDec(string);
	string ConvertDecToBin(string);
	ClassQfloat operator=(ClassQfloat);
};


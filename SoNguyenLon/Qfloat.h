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
	int* data = new int[4];
public:
	Qfloat();
	bool getBit(int index);
	void setBit(int index, bool bit);
	void ScanQfloat();
	void PrintQfloat();
	string BinToDec(string);
	string DecToBin(string);	 
	Qfloat operator=(Qfloat x);
};


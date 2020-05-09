#include "ClassQInt.h"
#include "ClassQfloat.h"
int main()
{
	ClassQfloat a;
	a.ScanQfloat("0.1", 10);
	a.PrintQfloat(10);
	a.PrintQfloat(2);
	return 0;
}
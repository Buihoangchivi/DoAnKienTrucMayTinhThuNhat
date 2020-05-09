#include "ClassQInt.h"
#include "ClassQfloat.h"
int main()
{
	ClassQfloat a;
	a.ScanQfloat("10000000000000000000000000000000000000000000000000.1", 10);
	a.PrintQfloat(10);
	a.PrintQfloat(2);
	return 0;
}
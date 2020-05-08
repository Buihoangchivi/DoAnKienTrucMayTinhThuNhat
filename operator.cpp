#include "Xyuly.h"

QInt::QInt()
{

	data[0] = data[1] = data[2] = data[3] = 0;

}

bool QInt::getBit(int i)
{

	return (data[i / 32] >> (31 - i % 32)) & 1;

}

void QInt::setBit(int i, bool bit)
{

	if (bit == 0)
		data[i / 32] = (~(1 << (31 - i))) & data[i / 32];
	else
		data[i / 32] = (1 << (31 - i)) | data[i / 32];

}


QInt QInt::operator&(QInt x)
{
	QInt temp;
	char s;
	for (int i = 0; i < 128; i++)
	{
		s = this->getBit(i) + x.getBit(i);
		if (s == 2)
		{
			temp.setBit(i, 1);
		}
		else
			temp.setBit(i, 0);
	}
	return temp;
}

QInt QInt::operator|(QInt x)   /// OR
{
	QInt temp;
	char s;
	for (int i = 0; i < 128; i++)
	{
		s = this->getBit(i) + x.getBit(i);
		if (s == 0)
		{
			temp.setBit(i, 0);
		}
		else
			temp.setBit(i, 1);
	}
	return temp;
}

QInt QInt::operator^(QInt x)		//XOR
{
	QInt temp;
	char s;
	for (int i = 0; i < 128; i++)
	{
		s = this->getBit(i) + x.getBit(i);
		if (s == 1)
		{
			temp.setBit(i, 1);
		}
		else
			temp.setBit(i, 0);
	}
	return temp;
}


QInt QInt::operator~()
{
	QInt temp;
	for (int i = 0; i < 128; i++)
	{
		if (this->getBit(i) == 0)
			temp.setBit(i, 1);
		else
			temp.setBit(i, 0);
	}
	return temp;
}

int QInt:: Vitribitdau()
{
	for (int i = 127; i >= 0; i--)
	{
		if (this->getBit(i) != this->getBit(i - 1))
			return i - 1;
	}
}
QInt QInt::operator<<(int k)
{
	int tmp;
	QInt temp;
	for (int i = 0; i < k; i++)
	{
		temp.setBit(i, 0);
	}
	for (int i = 0; i < 128-k; i++)
	{
		tmp = this->getBit(i);
		temp.setBit(i + k, tmp);
	}
	return temp;
}

QInt QInt::operator>>(int k)
{
	int tmp, pos = this->Vitribitdau();
	QInt temp;
	for (int i = k; i <= pos; i++)
	{
		tmp = this->getBit(i);
		temp.setBit(i-k, tmp);
	}
	for (int i = pos - k + 1; i < 128; i++)
	{
		temp.setBit(i, 0);
	}
	return temp;
}
QInt QInt::ror()
{
	int temp;
	temp = this->getBit(0);
	for (int i = 0; i < 127; i++)
		this->setBit(i, this->getBit(i + 1));
	this->setBit(127, temp);
	return *this;
}
QInt QInt::rol()
{
	int temp;
	temp = this->getBit(127);
	for (int i = 127; i > 0; i--)
		this->setBit(i, this->getBit(i - 1));
	this->setBit(0, temp);
	return *this;
}

QInt QInt::operator=(QInt x)
{
	for (int i = 0; i < 4; i++)
		this->data[i] = x.data[i];
	return *this;
}
bool QInt::operator==(QInt x)
{
	for (int i = 0; i < 128; i++)
	{
		if (this->getBit(i) != x.getBit(i))
			return false;
	}
	return true;
}

bool QInt::operator<(QInt x)
{
	int pos1, pos2;
	pos1 = this->Vitribitdau();
	pos2 = x.Vitribitdau();
	if (pos1 < pos2)
		return true;
	if (pos1 > pos2)
		return false;
	if(pos1==pos2)
	{
		for (int i = pos1; i >= 0; i--)
		{
			if (this->getBit(i) > x.getBit(i))
				return false;
			if (this->getBit(i) < x.getBit(i))
				return true;
		}
		return false;
	}
}

bool QInt::operator>(QInt x)
{
	int pos1, pos2;
	pos1 = this->Vitribitdau();
	pos2 = x.Vitribitdau();
	if (pos1 > pos2)
		return true;
	if (pos1 < pos2)
		return false;
	if (pos1 == pos2)
	{
		for (int i = pos1; i >= 0; i--)
		{
			if (this->getBit(i) < x.getBit(i))
				return false;
			if (this->getBit(i) > x.getBit(i))
				return true;
		}
		return false;
	}
}

bool QInt::operator<=(QInt x)
{
	int pos1, pos2;
	pos1 = this->Vitribitdau();
	pos2 = x.Vitribitdau();
	if (pos1 < pos2)
		return true;
	if (pos1 > pos2)
		return false;
	if (pos1 == pos2)
	{
		for (int i = pos1; i >= 0; i--)
		{
			if (this->getBit(i) > x.getBit(i))
				return false;
			if (this->getBit(i) < x.getBit(i))
				return true;
		}
		return false;
	}
}

bool QInt::operator>=(QInt x)
{
	int pos1, pos2;
	pos1 = this->Vitribitdau();
	pos2 = x.Vitribitdau();
	if (pos1 > pos2)
		return true;
	if (pos1 < pos2)
		return false;
	if (pos1 == pos2)
	{
		for (int i = pos1; i >= 0; i--)
		{
			if (this->getBit(i) < x.getBit(i))
				return false;
			if (this->getBit(i) > x.getBit(i))
				return true;
		}
		return true;
	}
}


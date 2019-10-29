#include "BinaryPixel.h"

//====================Common functions=================

double toCorrectValue(double value)
{
	if (value > MAX_VALUE) return MAX_VALUE;
	if (value < MIN_VALUE) return MIN_VALUE;
	return value;
}

//====================Constructors=====================

BinaryPixel::BinaryPixel(double data)
{
	this->data = data;
}

//====================Const methods====================

char BinaryPixel::toChar() const
{
	if (data < 0.5) return ' ';
	return 'O';
}

double BinaryPixel::getData() const
{
	return data;
}

//====================Const operators==================

BinaryPixel BinaryPixel::operator+(BinaryPixel other) const
{
	BinaryPixel result = *this;
	result.data = toCorrectValue(result.data + other.data);
	return result;
}

BinaryPixel BinaryPixel::operator-(BinaryPixel other) const
{
	BinaryPixel result = *this;
	result.data = toCorrectValue(result.data - other.data);
	return result;
}

BinaryPixel BinaryPixel::operator*(BinaryPixel other) const
{
	BinaryPixel result = *this;
	result.data = toCorrectValue(result.data * other.data);
	return result;
}

BinaryPixel BinaryPixel::operator/(BinaryPixel other) const
{
	BinaryPixel result = *this;
	result.data = toCorrectValue(result.data / other.data);
	return result;
}

BinaryPixel BinaryPixel::operator+(double other) const
{
	BinaryPixel result = *this;
	result.data = toCorrectValue(result.data + other);
	return result;
}

BinaryPixel BinaryPixel::operator-(double other) const
{
	BinaryPixel result = *this;
	result.data = toCorrectValue(result.data - other);
	return result;
}

BinaryPixel BinaryPixel::operator*(double other) const
{
	BinaryPixel result = *this;
	result.data = toCorrectValue(result.data * other);
	return result;
}

BinaryPixel BinaryPixel::operator/(double other) const
{
	BinaryPixel result = *this;
	result.data = toCorrectValue(result.data / other);
	return result;
}

bool BinaryPixel::operator==(BinaryPixel other) const
{
	return data == other.data;
}

bool BinaryPixel::operator!=(BinaryPixel other) const
{
	return data != other.data;
}

//====================NON-Const operators==============

BinaryPixel BinaryPixel::operator+=(BinaryPixel other)
{
	*this = *this + other;
	return *this;
}

BinaryPixel BinaryPixel::operator-=(BinaryPixel other)
{
	*this = *this - other;
	return *this;
}

BinaryPixel BinaryPixel::operator*=(BinaryPixel other)
{
	*this = *this * other;
	return *this;
}

BinaryPixel BinaryPixel::operator/=(BinaryPixel other)
{
	*this = *this / other;
	return *this;
}

BinaryPixel BinaryPixel::operator=(BinaryPixel other)
{
	data = other.data;
	return *this;
}

BinaryPixel BinaryPixel::operator+=(double other)
{
	*this = *this + other;
	return *this;
}

BinaryPixel BinaryPixel::operator-=(double other)
{
	*this = *this - other;
	return *this;
}

BinaryPixel BinaryPixel::operator*=(double other)
{
	*this = *this * other;
	return *this;
}

BinaryPixel BinaryPixel::operator/=(double other)
{
	*this = *this / other;
	return *this;
}

BinaryPixel BinaryPixel::operator=(double other)
{
	data = toCorrectValue(other);
	return *this;
}

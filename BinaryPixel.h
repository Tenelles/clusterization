#pragma once

constexpr double MIN_VALUE = 0;
constexpr double MAX_VALUE = 1;

//====================Common functions=================

// Converts argument to correct pixel value
double toCorrectValue(double);

class BinaryPixel
{
public:

	//====================Constructors=====================

	BinaryPixel(double = 0);

	//====================Const methods====================

	// Get a symbol by code of pixel
	char toChar() const;
	double getData() const;

	//====================Const operators==================

	BinaryPixel operator+(BinaryPixel) const;
	BinaryPixel operator-(BinaryPixel) const;
	BinaryPixel operator*(BinaryPixel) const;
	BinaryPixel operator/(BinaryPixel) const;
	BinaryPixel operator+(double) const;
	BinaryPixel operator-(double) const;
	BinaryPixel operator*(double) const;
	BinaryPixel operator/(double) const;
	bool operator==(BinaryPixel) const;
	bool operator!=(BinaryPixel) const;

	//====================NON-Const operators==============

	BinaryPixel operator+=(BinaryPixel);
	BinaryPixel operator-=(BinaryPixel);
	BinaryPixel operator*=(BinaryPixel);
	BinaryPixel operator/=(BinaryPixel);
	BinaryPixel operator=(BinaryPixel);
	BinaryPixel operator+=(double);
	BinaryPixel operator-=(double);
	BinaryPixel operator*=(double);
	BinaryPixel operator/=(double);
	BinaryPixel operator=(double);

private:
	//===================Fields============================

	double data;
};
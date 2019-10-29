#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Matrix
{
public:

	//====================Constructors=====================

	Matrix(int);
	Matrix(int, int);
	Matrix(pair<int, int>);
	Matrix(vector<vector<double>>);

	//====================Const methods====================

	Matrix getInverse() const;
	double getDeterminator() const;
	Matrix getTranspose() const;
	void print() const;

	//====================Const operators==================

	Matrix operator+(Matrix) const;
	Matrix operator-(Matrix) const;
	Matrix operator*(Matrix) const;
	Matrix operator+(double) const;
	Matrix operator-(double) const;
	Matrix operator*(double) const;
	Matrix operator/(double) const;

	//====================Non-Const operators==============

	vector<double>& operator[](int);
	Matrix operator+=(Matrix);
	Matrix operator-=(Matrix);
	Matrix operator+=(double);
	Matrix operator-=(double);
	Matrix operator*=(double);
	Matrix operator/=(double);

private:
	//====================Const methods====================

	Matrix getStrikeOut(int, int) const;

	//=====================Fields==========================

	vector<vector<double>> field;
	int height,
		width;
};
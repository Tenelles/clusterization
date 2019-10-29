#include "Matrix.h"
//====================Constructors=====================

Matrix::Matrix(int size)
{
	this->width = size;
	this->height = size;
	for (int i = 0; i < height; i++)
	{
		vector<double> temp;
		for (int j = 0; j < width; j++)
			if (i == j)
				temp.push_back(1);
			else
				temp.push_back(0);

		field.push_back(temp);
	}
}

Matrix::Matrix(int height, int width)
{
	this->width = width;
	this->height = height;
	for (int i = 0; i < height; i++)
	{
		vector<double> temp;
		for (int j = 0; j < width; j++)
			temp.push_back(0);
		field.push_back(temp);
	}
}

Matrix::Matrix(pair<int, int> size) : Matrix(size.first, size.second)
{
}

Matrix::Matrix(vector<vector<double>> matrix)
{
	this->width = matrix[0].size();
	this->height = matrix.size();
	for (auto currentString : matrix)
	{
		field.push_back(currentString);
	}
}

//====================Const methods====================

void Matrix::print() const
{
	for (auto string : field)
	{
		for (auto cell : string)
			cout << cell << '\t';
		cout << endl;
	}
}

double Matrix::getDeterminator() const
{	
	double result = 0;
	if (height == 1 || width == 1) return field[0][0];
	for (int i = 0; i < width; i++)
		result += pow(-1, i) * field[0][i] * getStrikeOut(0, i).getDeterminator();
	return result;
}

Matrix Matrix::getStrikeOut(int string, int column) const
{
	vector<vector<double>> result;
	for (int i = 0; i < height; i++)
	{
		if (i == string) continue;
		vector<double> temp;
		for (int j = 0; j < width; j++)
		{
			if (j == column) continue;
			temp.push_back(field[i][j]);
		}
		result.push_back(temp);
	}
	return Matrix(result);
}

Matrix Matrix::getInverse() const
{
	double determinator = getDeterminator();
	Matrix algebraicAdditions = *this;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			algebraicAdditions[i][j] = getStrikeOut(i, j).getDeterminator();
			if ((i + j) % 2 != 0) algebraicAdditions[i][j] *= (-1);
		}
	return algebraicAdditions.getTranspose() / determinator;
}

Matrix Matrix::getTranspose() const
{
	Matrix result(height, width);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			result[j][i] = field[i][j];
	return result;
}

//====================Const operators==================

Matrix Matrix::operator+(Matrix other) const
{
	Matrix result = *this;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			result[i][j] += other[i][j];
	return result;
}

Matrix Matrix::operator-(Matrix other) const
{
	Matrix result = *this;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			result[i][j] -= other[i][j];
	return result;
}

Matrix Matrix::operator*(Matrix other) const
{
	Matrix result(other.width, height);
	for (int i = 0; i < result.height; i++)
		for (int j = 0; j < result.width; j++)
		{
			double sum = 0;
			for (int c = 0; c < width; c++)
				sum += field[i][c] * other[c][j];
			result[i][j] = sum;
		}
	return result;
}

Matrix Matrix::operator+(double other) const
{
	Matrix result = *this;
	for (auto& currentString : result.field)
		for (auto& currentCell : currentString)
			currentCell += other;
	return result;
}

Matrix Matrix::operator-(double other) const
{
	Matrix result = *this;
	for (auto& currentString : result.field)
		for (auto& currentCell : currentString)
			currentCell -= other;
	return result;
}

Matrix Matrix::operator*(double other) const
{
	Matrix result = *this;
	for (auto& currentString : result.field)
		for (auto& currentCell : currentString)
			currentCell *= other;
	return result;
}

Matrix Matrix::operator/(double other) const
{
	Matrix result = *this;
	for (auto& currentString : result.field)
		for (auto& currentCell : currentString)
			currentCell /= other;
	return result;
}

//====================Non-Const operators==============

vector<double>& Matrix::operator[](int pos)
{
	return field[pos];
}

Matrix Matrix::operator+=(Matrix other)
{
	*this = *this + other;
	return *this;
}

Matrix Matrix::operator-=(Matrix other)
{
	*this = *this - other;
	return *this;
}

Matrix Matrix::operator+=(double other)
{
	*this = *this + other;
	return *this;
}

Matrix Matrix::operator-=(double other)
{
	*this = *this - other;
	return *this;
}

Matrix Matrix::operator*=(double other)
{
	*this = *this * other;
	return *this;
}

Matrix Matrix::operator/=(double other)
{
	*this = *this / other;
	return *this;
}
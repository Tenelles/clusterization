#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "Matrix.h"

using namespace std;

#define IMAGE_HEIGHT 5
#define IMAGE_WIDTH 3

template<class Pixel>
class Image
{
public:

	//====================Constructors=====================

	Image<Pixel>(vector<Pixel>);
	Image<Pixel>();;

	//====================Const methods===================

	void draw() const;
	double getEuclideanDistance(Image<Pixel>) const;
	Matrix toMatrix() const;

	//====================Const operators==================

	Image<Pixel> operator+(Image<Pixel>) const;
	Image<Pixel> operator-(Image<Pixel>) const;
	Image<Pixel> operator*(Image<Pixel>) const;
	Image<Pixel> operator/(Image<Pixel>) const;
	Image<Pixel> operator+(double) const;
	Image<Pixel> operator-(double) const;
	Image<Pixel> operator*(double) const;
	Image<Pixel> operator/(double) const;
	bool operator==(Image<Pixel>) const;
	bool operator!=(Image<Pixel>) const;

	//====================Non-Const operators==============

	Pixel& operator[](int);
	Image<Pixel> operator+=(Image<Pixel>);
	Image<Pixel> operator-=(Image<Pixel>);
	Image<Pixel> operator*=(Image<Pixel>);
	Image<Pixel> operator/=(Image<Pixel>);
	Image<Pixel> operator+=(double);
	Image<Pixel> operator-=(double);
	Image<Pixel> operator*=(double);
	Image<Pixel> operator/=(double);
	Image<Pixel> operator=(Pixel);
	Image<Pixel> operator=(double);

private:

	//====================Fields===========================

	vector<Pixel> pixels;
};

//====================Constructors=====================

template<class Pixel>
inline Image<Pixel>::Image(vector<Pixel> image)
{
	for (auto currentPixel : image)
		pixels.push_back(currentPixel);
}

template<class Pixel>
inline Image<Pixel>::Image()
{
	int imageSize = IMAGE_HEIGHT * IMAGE_WIDTH;
	for (int i = 0; i < imageSize; i++)
		pixels.push_back(0);
}

//====================Const methods===================

template<class Pixel>
inline void Image<Pixel>::draw() const
{
	for (int i = 0; i < IMAGE_HEIGHT; i++)
	{
		for (int j = 0; j < IMAGE_WIDTH; j++)
			cout << pixels[i * IMAGE_WIDTH + j].toChar();
		cout << endl;
	}
	cout << endl;
}

template<class Pixel>
inline double Image<Pixel>::getEuclideanDistance(Image<Pixel> other) const
{
	double result = 0;
	int imageSize = pixels.size();
	for (int i = 0; i < imageSize; i++)
		result += pow(pixels[i].getData() - other[i].getData(), 2);
	result = sqrt(result);
	return result;
}

template<class Pixel>
inline Matrix Image<Pixel>::toMatrix() const
{
	vector<vector<double>> result;
	vector<double> temp;
	for (auto now : pixels)
		temp.push_back(now.getData());
	result.push_back(temp);
	return Matrix(result);
}

//====================Const operators==================

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator+(Image<Pixel> other) const
{
	Image<Pixel> temp;
	int imageSize = pixels.size();
	for (int i = 0; i < imageSize; i++)
		temp[i] += other[i];
	return temp;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator-(Image<Pixel> other) const
{
	Image<Pixel> temp;
	int imageSize = pixels.size();
	for (int i = 0; i < imageSize; i++)
		temp[i] -= other[i];
	return temp;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator*(Image<Pixel> other) const
{
	Image<Pixel> temp;
	int imageSize = pixels.size();
	for (int i = 0; i < imageSize; i++)
		temp[i] *= other[i];
	return temp;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator/(Image<Pixel> other) const
{
	Image<Pixel> temp;
	int imageSize = pixels.size();
	for (int i = 0; i < imageSize; i++)
		temp[i] /= other[i];
	return temp;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator+(double other) const
{
	Image<Pixel> temp;
	int imageSize = pixels.size();
	for (int i = 0; i < imageSize; i++)
		temp[i] += other;
	return temp;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator-(double other) const
{
	Image<Pixel> temp;
	int imageSize = pixels.size();
	for (int i = 0; i < imageSize; i++)
		temp[i] -= other;
	return temp;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator*(double other) const
{
	Image<Pixel> temp;
	int imageSize = pixels.size();
	for (int i = 0; i < imageSize; i++)
		temp[i] *= other;
	return temp;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator/(double other) const
{
	Image<Pixel> temp;
	int imageSize = pixels.size();
	for (int i = 0; i < imageSize; i++)
		temp[i] /= other;
	return temp;
}

template<class Pixel>
inline bool Image<Pixel>::operator==(Image<Pixel> other) const
{
	for (int i = 0; i < IMAGE_HEIGHT * IMAGE_WIDTH; i++)
		if (pixels[i] != other.pixels[i]) return false;
	return true;
}

template<class Pixel>
inline bool Image<Pixel>::operator!=(Image<Pixel> other) const
{
	return !(*this == other);
}

//====================Non-Const operators================

template<class Pixel>
inline Pixel& Image<Pixel>::operator[](int pos)
{
	return pixels[pos];
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator+=(Image<Pixel> other)
{
	*this = *this + other;
	return *this;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator-=(Image<Pixel> other)
{
	*this = *this - other;
	return *this;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator*=(Image<Pixel> other)
{
	*this = *this * other;
	return *this;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator/=(Image<Pixel> other)
{
	*this = *this / other;
	return *this;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator+=(double other)
{
	*this = *this + other;
	return *this;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator-=(double other)
{
	*this = *this - other;
	return *this;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator*=(double other)
{
	*this = *this * other;
	return *this;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator/=(double other)
{
	*this = *this / other;
	return *this;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator=(Pixel other)
{
	for (auto& currentPixel : pixels)
		currentPixel = other;
	return *this;
}

template<class Pixel>
inline Image<Pixel> Image<Pixel>::operator=(double other)
{
	for (auto& currentPixel : pixels)
		currentPixel = other;
	return *this;
}

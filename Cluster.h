#pragma once
#include "Image.h"

template<class Pixel>
vector<Pixel> readPixels(int);

template <class Pixel>
class Cluster
{
public:
	//====================Constructors=====================

	Cluster<Pixel>(Image<Pixel>);

	//====================Const methors====================

	void draw() const;
	double getEuclideanDistance(Image<Pixel>) const;
	Image<Pixel> getCore() const;

	//====================Const operators==================

	Cluster<Pixel> operator+(Cluster<Pixel>) const;
	Cluster<Pixel> operator*(Cluster<Pixel>) const;
	bool operator==(Cluster<Pixel>) const;
	bool operator!=(Cluster<Pixel>) const;
	
	//====================Non-Const methors================

	double getMahalanobisDistance(Image<Pixel>);
	Matrix getCovariations();
	void addImage(Image<Pixel>);
	void recalculateCore();
	void clear();

	//====================Non-Const operators==============

	Cluster<Pixel> operator+=(Cluster<Pixel>);
	Cluster<Pixel> operator*=(Cluster<Pixel>);

private:
	int size;
	vector<Image<Pixel>> images;
	Image<Pixel> core;
};

template<class Pixel>
inline Cluster<Pixel>::Cluster(Image<Pixel> image)
{
	size = 0;
	core = image;
}

template<class Pixel>
inline void Cluster<Pixel>::draw() const
{
	cout << ">>> Cluster begin:" << endl;
	for (auto now : images)
		now.draw();
	cout << ">>> Cluster end." << endl;
}

template<class Pixel>
inline double Cluster<Pixel>::getEuclideanDistance(Image<Pixel> image) const
{
	return image.getEuclideanDistance(core);
}

template<class Pixel>
inline Image<Pixel> Cluster<Pixel>::getCore() const
{
	return core;
}

template<class Pixel>
inline double Cluster<Pixel>::getMahalanobisDistance(Image<Pixel> image)
{
	double result;
	Matrix X = core.toMatrix();
	Matrix Y = image.toMatrix();
	Matrix D = X - Y;
	Matrix E(IMAGE_HEIGHT * IMAGE_WIDTH);
	Matrix S = getCovariations();
	result = sqrt((D * (S + E).getInverse() * D.getTranspose()).getDeterminator());
	return result;
}

template<class Pixel>
inline Cluster<Pixel> Cluster<Pixel>::operator+(Cluster<Pixel> other) const
{
	Cluster<Pixel> result = *this;
	for (auto now: other.images)
	{
		bool isUnique = true;
		for (auto compairing : result.images)
			if (compairing == now)
				isUnique = false;
		if (isUnique)
			result.addImage(now);
	}
	result.recalculateCore();
	return result;
}

template<class Pixel>
inline Cluster<Pixel> Cluster<Pixel>::operator*(Cluster<Pixel> other) const
{
	Cluster<Pixel> result = *this;
	result.clear();
	for (auto now : images)
	{
		bool isInOther = false;
		for (auto compare : other.images)
			if (compare == now)
				isInOther = true;
		if (isInOther) result.addImage(now);
	}
	result.recalculateCore();
	return result;
}

template<class Pixel>
inline bool Cluster<Pixel>::operator==(Cluster<Pixel> other) const
{
	if (size != other.size) return false;
	for (unsigned int i = 0; i < images.size(); i++)
		if (images[i] != other.images[i]) return false;
	return true;
}

template<class Pixel>
inline bool Cluster<Pixel>::operator!=(Cluster<Pixel> other) const
{
	return !(*this == other);
}

template<class Pixel>
inline Matrix Cluster<Pixel>::getCovariations()
{
	int imageSize = IMAGE_HEIGHT * IMAGE_WIDTH;
	Matrix result(imageSize);
	if (size <= 1) return result * 0;
	recalculateCore();
	for (int i = 0; i < imageSize; i++)
		for (int j = 0; j < imageSize; j++)
		{
			double sum = 0;
			for (int k = 0; k < size; k++)
				sum += (images[k][i].getData() - core[i].getData()) * (images[k][j].getData() - core[j].getData());
			result[i][j] = sum / (size - 1);
		}
	return result;
}

template<class Pixel>
inline void Cluster<Pixel>::addImage(Image<Pixel> image)
{
	images.push_back(image);
	size++;
}

template<class Pixel>
inline void Cluster<Pixel>::recalculateCore()
{
	int imageSize = IMAGE_HEIGHT * IMAGE_WIDTH;
	for (int i = 0; i < imageSize; i++)
	{
		double sum = 0;
		for (int j = 0; j < size; j++)
			sum += images[j][i].getData();
		core[i] = Pixel(sum / size);
	}
}

template<class Pixel>
inline void Cluster<Pixel>::clear()
{
	images.clear();
	size = 0;
}

template<class Pixel>
inline Cluster<Pixel> Cluster<Pixel>::operator+=(Cluster<Pixel> other)
{
	*this = *this + other;
	return *this;
}

template<class Pixel>
inline Cluster<Pixel> Cluster<Pixel>::operator*=(Cluster<Pixel> other)
{
	*this = *this * other;
	return *this;
}

template<class Pixel>
inline vector<Pixel> readPixels(int size)
{
	cout << "Enter image: " << endl;
	vector<Pixel> result;
	double t;
	for (int i = 0; i < size; i++)
	{
		cin >> t;
		result.push_back(Pixel(t));
	}
	return result;
}

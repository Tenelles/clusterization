#pragma once
#include "Cluster.h"

template<class Pixel>
class Hierarhy
{
public:
	Hierarhy(int, int);

	void runEuclidean();

	void printStartMessage() const;
private:
	vector<Cluster<Pixel>> clusters;
	int requireïClustersCount;
};

template<class Pixel>
inline Hierarhy<Pixel>::Hierarhy(int groupsCount, int imagesCount)
{
	requireïClustersCount = groupsCount;
	for (int i = 0; i < imagesCount; i++)
	{
		Image<Pixel> image = Image<Pixel>((readPixels(IMAGE_HEIGHT * IMAGE_WIDTH), IMAGE_WIDTH, IMAGE_HEIGHT);
		clusters.push_back(Cluster<Pixel>(image));
		clusters[i].addImage(image);
	}
}


template<class Pixel>
inline void Hierarhy<Pixel>::printInfo() const
{
	cout << "Current clusters:" << endl;
	for (int i = 0; i < K; i++)
	{
		cout << "Cluster #" << i + 1 << endl;
		clusters[i].draw();
		cout << endl;
	}
}
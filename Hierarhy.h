#pragma once
#include "Cluster.h"

template<class Pixel>
class Hierarhy
{
public:

	//====================Constructors=====================

	Hierarhy(int, int);

	//====================Non-Const Methods================

	void runEuclidean();

private:

	//====================Const methors====================

	void printInfo() const;

	//====================Fields===========================

	vector<Cluster<Pixel>> clusters;
	int requireClustersCount;
};

//====================Constructors=====================

template<class Pixel>
inline Hierarhy<Pixel>::Hierarhy(int groupsCount, int imagesCount)
{
	requireClustersCount = groupsCount;
	for (int i = 0; i < imagesCount; i++)
	{
		Image<Pixel> image = Image<Pixel>(readPixels<Pixel>(IMAGE_HEIGHT * IMAGE_WIDTH));
		clusters.push_back(Cluster<Pixel>(image));
		clusters[i].addImage(image);
	}
	printInfo();
}

//====================Non-Const Methods================

template<class Pixel>
inline void Hierarhy<Pixel>::runEuclidean()
{
	if (clusters.size() == requireClustersCount)
	{
		cout << "Solved." << endl;
		return;
	}
	int minIndexA = 0, minIndexB = 1;
	for (unsigned int i = 0; i < clusters.size() - 1; i++)
		for (unsigned int j = i + 1; j < clusters.size(); j++)
			if (clusters[i].getEuclideanDistance(clusters[j].getCore()) <
				clusters[minIndexA].getEuclideanDistance(clusters[minIndexB].getCore()))
			{
				minIndexA = i;
				minIndexB = j;
			}
	clusters[minIndexA] = clusters[minIndexA] + clusters[minIndexB];
	clusters.erase(clusters.begin() + minIndexB);
	printInfo();
	runEuclidean();
}

//====================Const methors====================

template<class Pixel>
inline void Hierarhy<Pixel>::printInfo() const
{
	cout << "Current clusters:" << endl;
	for (unsigned int i = 0; i < clusters.size(); i++)
	{
		cout << "Cluster #" << i + 1 << endl;
		clusters[i].draw();
		cout << endl;
	}
	cout << endl << endl;
}

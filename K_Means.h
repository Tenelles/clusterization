#include "Cluster.h"
#include <cstdlib>

template<class Pixel>
class K_Means
{
public:

	//====================Constructors=====================

	K_Means(int, int);

	//====================Non-Const Methods================

	void runEuclidean();
	void runMahalanobis();

private:

	//====================Const Methods====================
	bool isStabilized() const;
	void printStartMessage() const;
	void printInfo() const;

	//====================Fields===========================

	vector<Cluster<Pixel>> clusters;
	vector<Cluster<Pixel>> prevClusters;
	vector<Image<Pixel>> images;
	int requireClustersCount, imagesCount;
};

template<class Pixel>
inline K_Means<Pixel>::K_Means(int clustersCount, int imagesCount)
{
	this->requireClustersCount = clustersCount;
	this->imagesCount = imagesCount;
	printStartMessage();
	for (int i = 0; i < imagesCount; i++)
	{
		Image<Pixel> image(readPixels<Pixel>(IMAGE_WIDTH * IMAGE_HEIGHT));
		images.push_back(image);
		if (i < requireClustersCount)
			clusters.push_back(image);
	}
	printInfo();
}

template<class Pixel>
inline void K_Means<Pixel>::runEuclidean()
{
	for (auto currentImage : images)
	{
		int nearestClusterIndex = 0;
		for (unsigned int i = 0; i < clusters.size(); i++)
			if (clusters[i].getEuclideanDistance(currentImage) < clusters[nearestClusterIndex].getEuclideanDistance(currentImage))
				nearestClusterIndex = i;
		clusters[nearestClusterIndex].addImage(currentImage);
	}
	if (isStabilized())
	{
		cout << "Finished!" << endl;
		return;
	}
	printInfo();
	prevClusters = clusters;
	system("pause>nul");
	for (auto& current : clusters)
		current.clear();
	runEuclidean();
}

template<class Pixel>
inline void K_Means<Pixel>::runMahalanobis()
{
	for (auto currentImage : images)
	{
		int nearestClusterIndex = 0;
		for (unsigned int i = 0; i < clusters.size(); i++)
			if (clusters[i].getMahalanobisDistance(currentImage) < clusters[nearestClusterIndex].getMahalanobisDistance(currentImage))
				nearestClusterIndex = i;
		clusters[nearestClusterIndex].addImage(currentImage);
	}
	if (isStabilized())
	{
		cout << "Finished!" << endl;
		return;
	}
	printInfo();
	prevClusters = clusters;
	system("pause>nul");
	for (auto& current : clusters)
		current.clear();
	runMahalanobis();
}

template<class Pixel>
inline bool K_Means<Pixel>::isStabilized() const
{
	if (prevClusters.empty())
		return false;
	for (unsigned int i = 0; i < clusters.size(); i++)
		if (clusters[i] != prevClusters[i]) return false;
	return true;
}

template<class Pixel>
inline void K_Means<Pixel>::printStartMessage() const
{
	cout << "Enter images. Be careful, on the first " << requireClustersCount << " images will be based clusters." << endl;
}

template<class Pixel>
inline void K_Means<Pixel>::printInfo() const
{
	cout << "Current clusters:" << endl;
	for (int i = 0; i < requireClustersCount; i++)
	{
		cout << "Cluster #" << i + 1 << endl;
		clusters[i].draw();
		cout << endl;
	}
}

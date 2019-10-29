#include "BinaryPixel.h"
#include "K_Means.h"
#include "Hierarhy.h"

int main() 
{
	Hierarhy<BinaryPixel> machine(3, 10);
	machine.runEuclidean();
	return 0;
}


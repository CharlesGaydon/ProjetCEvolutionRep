#include <stdlib.h>     /* srand, rand */

#include "RandomArray.h"

	RandomArray::RandomArray(int Nsize, double min, double max){
		size_ = Nsize;
		pTab = new double[size_];
		for(int i = 0; i<Nsize; i++){
			pTab[i] = min + (((double) rand())/((double) RAND_MAX))*(max-min);
		}
	}

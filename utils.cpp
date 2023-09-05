#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "utils.hpp"

namespace sort{

	void swap(int* A, int i, int j){
		int aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	int getRandomInt(int min, int max){
		int a = rand() / static_cast<int>(RAND_MAX);
		return static_cast<int>(a * (max - min) + min + 0.5);
	}
	int maxValue(int* A, int n){
		int max = 0;
		for(int i = 1; i < n; i++){
			if(A[i] > max){
				max = A[i];
			}
		}
		return max;
	}

}

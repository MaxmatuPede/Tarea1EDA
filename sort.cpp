#include <iostream>
#include "sort.hpp"
#include "utils.hpp"
using namespace std;
namespace sort{

	void selectionSort(int* A, int n){
		int smallest = 0;
		int i = 0;
		int j = 0;
		for (i = 0; i < n - 1; i++){
			smallest = i;
			for (j = i + 1; j < n; j++){
				if (A[j] < A[smallest]){
					smallest = j;
				}
			}
			swap(A,i,smallest);
		}
	}
	

	int split_qs(int* A, int i, int j){
		/***
		 * split for quicksort
		 * i,j are the endpoints
		 */
		int p = getRandomInt(i, j);

		while (i  < j) {

			while ( i < p && A[i] <= A[p]){
				i = i + 1;
			}

			while ( j > p && A[j] >= A[p]){
				j = j - 1;
			}

			swap(A, i, j);

			if (i == p){
				p = j;
			}
			else if (j == p){
				p = i;
			}
		}
		return p;
	}

	void quickSort(int* A, int i, int j){
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}

	void quickSort(int* A, int n){
		quickSort(A, 0, n - 1);
	}

	void insertionSort(int* A, int n){
			for(int i=1; i<n; i++){
				int elem = A[i];
				int j = i-1;
				while(j>=0 && elem < A[j]){
					A[j+1] = A[j];
					j--;
				}
				A[j+1] = elem;
			}

		}

	void merge(int* A, int const left, int const mid, int const right){
		int const subA1 = mid - left + 1;
		int const subA2 = right - mid;

		auto *leftA = new int[subA1];
		auto *rightA = new int[subA2];
		
		for (auto i = 0; i< subA1; i++)
			leftA[i] = A[left + i];
		for (auto j = 0; j< subA2; j++)
			rightA[j] = A[mid + 1 + j];

		auto indexSubA1 = 0, indexSubA2 = 0;
		int indexMergA = left;

		while (indexSubA1 < subA1 && indexSubA2 < subA2){
			if (leftA[indexSubA1] <= rightA[indexSubA2]){
				A[indexMergA] = leftA[indexSubA1];
				indexSubA1++;
			}
			else{
				A[indexMergA] = rightA[indexSubA2];
				indexSubA2++;
			}
			indexMergA++;
		}

		while (indexSubA1 < subA1){
			A[indexMergA] = leftA[indexSubA1];
			indexSubA1++;
			indexMergA++;
		}

		while (indexSubA2 < subA2){
			A[indexMergA] = rightA[indexSubA2];
			indexSubA2++;
			indexMergA++;
		}

		delete[] leftA;
		delete[] rightA;
	}

	void mergeSort(int* A, int const begin, int const end){
		if(begin >=end){
			return;
		}
		int mid = begin + (end - begin)/2;
		mergeSort(A, begin, mid);
		mergeSort(A, mid + 1, end);
		merge(A, begin, mid, end);
	}


	void countingSort(int* A, int n, int exp){
		int *out = new int[n];
		int i, count[10] = {0};

		for (i=0; i < n; i++){
			count[(A[i]/exp)%10]++;
		}
		for (i=1; i<10 ; i++){
			count[i] += count[i-1];
		}
		for (i= n-1 ; i >= 0; i--){
			out[count[(A[i]/exp)%10]-1] = A[i];
			count[(A[i]/exp)%10]--;
		}
		for (i=0; i< n; i++){
			A[i]= out[i];
		}
		delete[] out;
	}

	void radixSort(int* A, int n){
		int m = maxValue(A, n);
		for (int exp = 1; m/exp > 0; exp *= 10){
			countingSort(A, n, exp);
		}
	}

}
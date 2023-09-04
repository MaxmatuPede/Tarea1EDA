#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

namespace sort {
	void selectionSort(int* A, int n);
	int split_qs(int* A, int i, int j);
	void quickSort(int* A, int i, int j);
	void quickSort(int* A, int n);
	void insertionSort(int* A, int n);
	void merge(int* A, int const left, int const mid, int const right);
	void mergeSort(int* A, int const begin, int const end);
}

#endif

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "Containers.h"
using namespace std;

// ----------MERGE SORT----------
//Slides Module 6: Sorting

// helper function for merge sort; merges the two halves together
void merge(vector<Containers::Song>& arr, int left, int mid, int right) {
	// variables that store length of left half and length of right half
	int l = mid - left + 1;
	int r = right - mid;

	// the two sub arrays that'll be combined
	vector<Containers::Song> X;
	vector<Containers::Song> Y;

	for (int i = 0; i < l; i++) {
		X.push_back(arr[left + i]);
	}
	for (int j = 0; j < r; j++) {
		Y.push_back(arr[mid + 1 + j]);
	}

	// merge the X and Y arrays into arr
	int i = 0, j = 0, k = left;
	while (i < l && j < r) {
		if (X[i].hotness >= Y[j].hotness) {
			arr[k] = X[i];
			i++;
		}
		else {
			arr[k] = Y[j];
			j++;
		}
		k++;
	}

	// if there are remaining elements in either X or Y, append them
	while (i < l) {
		arr[k] = X[i];
		i++;
		k++;
	}
	while (j < r) {
		arr[k] = Y[j];
		j++;
		k++;
	}
}

// merge sort function
void MergeSortRecur(vector<Containers::Song>& arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		MergeSortRecur(arr, left, mid);
		MergeSortRecur(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

vector<Containers::Song> MergeSort(vector<Containers::Song>& songList)
{
	vector<Containers::Song> sL = songList;
	MergeSortRecur(sL, 0, sL.size() - 1);
	return sL;
}

// -----------QUICK SORT----------
//Slides Module 6: Sorting

// helper function for quick sort; sets the partition
int partition(vector<Containers::Song>& songList, int low, int high)
{
	double pivot = songList[low].hotness;
	int up = low, down = high;

	while (up < down)
	{
		for (int i = up; i < high; i++)
		{
			if (songList[up].hotness < pivot)
				break;
			up++;
		}
		for (int i = high; i > low; i--)
		{
			if (songList[down].hotness > pivot)
				break;
			down--;
		}
		if (up < down)
			swap(songList[up], songList[down]);
	}
	swap(songList[low], songList[down]);
	return down;
}

// helper function for quick sort; recursivly sets the partition
void quickSortRecur(vector<Containers::Song>& songList, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(songList, low, high);
		quickSortRecur(songList, low, pivot - 1);
		quickSortRecur(songList, pivot + 1, high);
	}
}

// quick sort function
vector<Containers::Song> QuickSort(vector<Containers::Song>& songList)
{
	vector<Containers::Song> sL = songList;
	quickSortRecur(sL, 0, sL.size() - 1);
	return sL;
}
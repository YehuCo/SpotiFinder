#pragma once
#include <iostream>
#include <vector>
using namespace std;

// temporary class until we figure out how well handle the data
struct Sorter {
	struct Song {
		string title;
		double hotness;
		
		Song(string title, double hotness);
	};
public:
	vector<Song> list;

public:
	void mergeSort(vector<Song>& arr, int left, int right);
	void merge(vector<Song>& arr, int left, int mid, int right);
};

Sorter::Song::Song(string title, double hotness) {
	this->title = title;
	this->hotness = hotness;
}

void Sorter::mergeSort(vector<Song>& arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

void Sorter::merge(vector<Song>& arr, int left, int mid, int right) {
	// variables that store length of left half and length of right half
	int l = mid - left + 1;
	int r = right - mid;
	
	// the two sub arrays that'll be combined
	vector<Song> X;
	vector<Song> Y;

	for (int i = 0; i < l; i++) {
		X.push_back(arr[left + i]);
	}
	for (int j = 0; j < r; j++) {
		Y.push_back(arr[mid + 1 + j]);
	}

	// merge the X and Y arrays into arr
	int i = 0, j = 0, k = left;
	while (i < l && j < r) {
		if (X[i].hotness <= Y[j].hotness) {
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
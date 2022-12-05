#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

// temporary class until we figure out how well handle the data
struct Sorters {
	struct Song {
		string title;
		double hotness;
		
		Song(string title, double hotness);
	};
	vector<Song> songList;
	unordered_map<string, vector<Song>> songTable;

	void mergeSort(int left, int right);
	void merge(int left, int mid, int right);
	void populateData();
};

Sorters::Song::Song(string title, double hotness) {
	this->title = title;
	this->hotness = hotness;
}

void Sorters::mergeSort(int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);

		merge(left, mid, right);
	}
}

void Sorters::merge(int left, int mid, int right) {
	// variables that store length of left half and length of right half
	int l = mid - left + 1;
	int r = right - mid;
	
	// the two sub arrays that'll be combined
	vector<Song> X;
	vector<Song> Y;

	for (int i = 0; i < l; i++) {
		X.push_back(songList[left + i]);
	}
	for (int j = 0; j < r; j++) {
		Y.push_back(songList[mid + 1 + j]);
	}

	// merge the X and Y arrays into arr
	int i = 0, j = 0, k = left;
	while (i < l && j < r) {
		if (X[i].hotness >= Y[j].hotness) {
			songList[k] = X[i];
			i++;
		}
		else {
			songList[k] = Y[j];
			j++;
		}
		k++;
	}

	// if there are remaining elements in either X or Y, append them
	while (i < l) {
		songList[k] = X[i];
		i++;
		k++;
	}
	while (j < r) {
		songList[k] = Y[j];
		j++;
		k++;
	}
}

void Sorters::populateData() {
	fstream myFile("SpotiFinderSubset.csv");
	string line;
	string name;
	string word;
	double pop = 0;

	getline(myFile, line, '\n');

	for (int i = 0; i < 10; i++) {
		getline(myFile, line);
		stringstream s(line);

		while (getline(s, word, ',')) {
			name = "";
			if (word.substr(0, 2) == "0.") {
				pop = stod(word);
			}
			else if (word.substr(0, 1) != "0") {
				name += word;
			}
		}
		if (name != "")
			songList.push_back(Sorters::Song(name, pop));
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~Quick Sort~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int partition(vector<Sorters::Song>& songList, int low, int high)
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

void quickSortRecur(vector<Sorters::Song>& songList, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(songList, low, high);
		quickSortRecur(songList, low, pivot - 1);
		quickSortRecur(songList, pivot + 1, high);
	}
}

void QuickSort(vector<Sorters::Song>& songList)
{
	quickSortRecur(songList, 0, songList.size() - 1);
}
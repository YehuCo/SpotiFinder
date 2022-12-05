#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// temporary class until we figure out how well handle the data
struct Sorter {
	struct Song {
		string title;
		double hotness;
		
		Song(string title, double hotness);
	};
	vector<Song> songList;

	void mergeSort(int left, int right);
	void merge(int left, int mid, int right);
	void populateData();

};

Sorter::Song::Song(string title, double hotness) {
	this->title = title;
	this->hotness = hotness;
}

void Sorter::mergeSort(int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);

		merge(left, mid, right);
	}
}

void Sorter::merge(int left, int mid, int right) {
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

void Sorter::populateData() {
	fstream myFile("SpotiFinderSubset.csv");
	string line;
	string name;
	string word;
	double pop = 0;

	getline(myFile, line, '\n');

	for (int i = 0; i < 1000; i++) {
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
			songList.push_back(Sorter::Song(name, pop));
	}
}
#include <iostream>
#include <string>
#include <vector>
#include "MergeSort.h"

using namespace std;

int main() {
	string word;

	// print welcome screen
	cout << "Wlecome to SpotiFinder." << endl;
	cout << "Please enter the word you'd like to use to find song titles: ";
	cin >> word;

	/*
	TODO: call function in the hash table class to access index where word is stored and retrieve the stored vector of titles
	*/

	/*
	TODO: call function in the graph class to retrieve list of song titles with inputed word
	*/
	
	cout << "Songs containing the word " << word << " stored in the hash table:" << endl;
	// print list of songs from the hash table

	cout << "Songs containing the word " << word << " stored in the graph:" << endl;
	// print list of songs from the graph

	Sorter vec;
	vec.list.push_back(Sorter::Song("yehuda", 0.5));
	vec.list.push_back(Sorter::Song("emma", 0.8));
	vec.list.push_back(Sorter::Song("seany", 0.3));
	vec.list.push_back(Sorter::Song("mario", 0.2));
	vec.mergeSort(vec.list, 0, vec.list.size() - 1);

	for (int i = 0; i < vec.list.size(); i++) {
		cout << vec.list[i].title << " " << vec.list[i].hotness << endl;
	}

	return 0;
}
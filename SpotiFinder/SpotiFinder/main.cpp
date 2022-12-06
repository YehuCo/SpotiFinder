#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "Sorters.h"
using namespace std;


int main() {
	Containers songs;
	songs.populateData();
	string searchWord;
	string sortMethod;
	string restart;
	

	// print welcome screen and prompt for search word
	cout << "--------------------SpotiFinder--------------------\n" << endl;
	while (true) {
		cout << "Please enter the word you'd like to use to find song titles: ";
		cin >> searchWord;

		// ask user if they'd like to sort using MergeSort or QuickSort
		cout << "How would you like the list of songs to be sorted? (quick/merge) ";
		cin >> sortMethod;

		auto start = chrono::system_clock::now();
		// if input is "Quick" call quick sort on the list of songs
		if (sortMethod == "quick") {
			QuickSort(songs.searchMap[searchWord]);
		}
		// call merge sort if the input is "Merge"
		else if (sortMethod == "merge") {
			MergeSort(songs.searchMap[searchWord], 0, songs.searchMap[searchWord].size() - 1);
		}
		auto end = chrono::system_clock::now();
		chrono::duration<double> elapsed_seconds = end - start;

		// print the list of songs to the terminal
		cout << "Song list:" << endl;
		for (auto song : songs.searchMap[searchWord]) {
			cout << "Song name: " << song.name << ". Popularity: " << song.hotness << endl;
		}

		// print the time it took to perform the sort
		cout << "Elapsed time to perform sort: " << elapsed_seconds.count() << "s" << endl;
		
		// ask if user wants to perform another search
		cout << "Would you like to perform another search? (y/n) ";
		cin >> restart;
		if (restart != "y") {
			break;
		}
	}

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "Sorters.h"
using namespace std;

// checks if input is an integer
bool checkIsDigit(string in)
{
	for (char c : in)
		if (!isdigit(c))
			return false;
	return true;
}

// checks if input is a single word
bool isWord(string in)
{
	for (char c : in)
		if (c == ' ')
			return false;
	return true;
}

int main() {
	cout << "Loading Data..." << endl << endl;

	Containers songs;
	songs.populateData();
	string searchWord;
	string resultCountIn;
	int resultCount;
	string sortMethod;
	string restart;


	// print welcome screen and prompt for search word
	cout << "~~~~~~~~~~~~~~~~~~~~SpotiFinder~~~~~~~~~~~~~~~~~~~~\n" << endl;
	while (true) {
		cout << "Enter the word you'd like to use to find song titles: ";

		// validate if input is a valid word, if not prompts user again
		getline(cin, searchWord);
		while (!isWord(searchWord))
		{
			cout << "Please enter a single word." << endl;
			cout << "Enter the word you'd like to use to find song titles: ";
			getline(cin, searchWord);
		}
		cout << endl;

		// validates if input is a valid number, if not prompts user again
		cout << "How many results would you like to see? ";
		getline(cin, resultCountIn);
		while (!checkIsDigit(resultCountIn))
		{
			cout << "Please enter an integer." << endl;
			cout << "How many results would you like to see? ";
			getline(cin, resultCountIn);
		}
		resultCount = stoi(resultCountIn);
		cout << endl;

		// ask user if they'd like to sort using MergeSort or QuickSort
		cout << "How would you like the list of songs to be sorted? (quick/merge) ";
		getline(cin, sortMethod);
		while (sortMethod != "quick" && sortMethod != "merge")
		{
			cout << "Please select a valid sort method." << endl;
			cout << "How would you like the list of songs to be sorted? (quick/merge) ";
			getline(cin, sortMethod);
		}
		cout << endl;

		// temporary vector to perform the sort and print; do this to compare merge and quick sort in a single run
		vector<Containers::Song> outputList;

		// keep track of when algorithm begins
		auto start = chrono::system_clock::now();
		// if input is "Quick" call quick sort on the list of songs
		if (sortMethod == "quick") {
			outputList = QuickSort(songs.searchMap[searchWord]);
			//QuickSort(songs.searchMap[searchWord]);
		}
		// call merge sort if the input is "Merge"
		else if (sortMethod == "merge") {
			outputList = MergeSort(songs.searchMap[searchWord]);
			//MergeSort(songs.searchMap[searchWord]);
		}
		// keep track of when algorithm ends
		auto end = chrono::system_clock::now();
		chrono::duration<double> elapsed_seconds = end - start;

		// print the list of songs to the terminal
		cout << "Songs containing \"" << searchWord << "\":" << endl;
		int count = 0;
		for (auto song : outputList) {
			if (count < resultCount)
			{
				cout << (count + 1) << ". " << song.name << endl;
				count++;
			}
			else
			{
				break;
			}
		}

		// print the time it took to perform the sort
		cout << endl << "Elapsed time to perform sort: " << elapsed_seconds.count() << "s" << endl;
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		// ask if user wants to perform another search
		cout << "Would you like to perform another search? (y/n) ";
		getline(cin, restart);
		while (restart != "y" && restart != "n")
		{
			cout << "Please select a valid option" << endl;
			cout << "Would you like to perform another search? (y/n) ";
			getline(cin, restart);
		}
		cout << endl;
		if (restart == "n") {
			break;
		}
	}

	return 0;
}

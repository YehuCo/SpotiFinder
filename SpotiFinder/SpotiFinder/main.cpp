#include <iostream>
#include <string>
#include <vector>
#include "Sorters.h"

//#include "TempSorters.h"
using namespace std;

int main() {
	Containers songs;
	songs.populateData();
	string word;


	cin >> word;


	// print welcome screen
	//cout << "SpotiFinder." << endl;
	//cout << "Please enter the word you'd like to use to find song titles: ";
	//cin >> word;

	/*
	TODO: call function in the hash table class to access index where word is stored and retrieve the stored vector of titles
	*/

	/*
	TODO: call function in the graph class to retrieve list of song titles with inputed word
	*/
	
	//cout << "Songs containing the word " << word << " stored in the hash table:" << endl;
	// print list of songs from the hash table

	//cout << "Songs containing the word " << word << " stored in the graph:" << endl;
	// print list of songs from the graph


	return 0;
}
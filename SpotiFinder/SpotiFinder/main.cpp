#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MergeSort.h"

using namespace std;

int main() {

	fstream myFile;
	myFile.open("SpotiFinderSubset.csv");
	string line;
	getline(myFile, line, '\n');
	cout << line << endl;
	for (int i = 0; i < 2; i++) {
		getline(myFile, line, '\n');
		cout << line << endl;
	}

















	//string word;

	//// print welcome screen
	//cout << "Wlecome to SpotiFinder." << endl;
	//cout << "Please enter the word you'd like to use to find song titles: ";
	//cin >> word;

	///*
	//TODO: call function in the hash table class to access index where word is stored and retrieve the stored vector of titles
	//*/

	///*
	//TODO: call function in the graph class to retrieve list of song titles with inputed word
	//*/
	//
	//cout << "Songs containing the word " << word << " stored in the hash table:" << endl;
	//// print list of songs from the hash table

	//cout << "Songs containing the word " << word << " stored in the graph:" << endl;
	//// print list of songs from the graph


	return 0;
}
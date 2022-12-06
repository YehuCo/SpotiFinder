#pragma once
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Containers
{
	struct Song
	{
		string name;
		string artist;
		double hotness;

		Song(string _name, double _hotness);
		Song(string _name, string _artist, double _hotness);
	};

	unordered_map<string, vector<Song>> searchMap;

	void populateData();
	void removeNonAlphabeticCharacters(string& s);
};

// default constructor for song without an artist
Containers::Song::Song(string _name, double _hotness)
{
	name = _name;
	artist = "Artist Not Available";
	hotness = _hotness;
}

// default constructor for song with an artist
Containers::Song::Song(string _name, string _artist, double _hotness)
{
	name = _name;
	artist = _artist;
	hotness = _hotness;
}

// populate the data into a temporary vector of songs
void Containers::populateData() {
	fstream myFile("ACTUAL DATASET FINAL DEFINITELY THIS ONE DO NOT USE ANYTHING ELSE.csv");
	string line;
	string name;
	string phrase;
	string word;
	double pop;

	getline(myFile, line, '\n');

	for (int i = 0; i < 200000; i++) {
		getline(myFile, line);
		stringstream s(line);

		while (getline(s, phrase, ',')) {
			name = "";
			if (phrase.substr(0, 2) == "0.") {
				pop = stod(phrase);
			}
			else if (phrase.substr(0, 1) != "0") {
				name += phrase;
			}
		}
		if (name != "")
		{
			Containers::Song song(name, pop);
			stringstream w(name);
			while (getline(w, word, ' ')) {
				removeNonAlphabeticCharacters(word);
				searchMap[word].push_back(song);
			}
		}
	}
}

// removes all non-alphabetic characters from the word to store it properly in the hash table
void Containers::removeNonAlphabeticCharacters(string& s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z') {
			s.erase(i, 1);
			i--;
		}
	}
}
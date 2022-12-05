#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Containers
{
	struct Song
	{
		string name;
		string artist;
		double hotness;

		Song(string _name, double _hotness);
		Song(string _name, string _artist, double _hotness);
	};

	static unordered_map<string, vector<Song&>> searchMap;
	static vector<Song> songList;

public:
	void populateData();
};

Containers::Song::Song(string _name, double _hotness)
{
	name = _name;
	artist = "Artist Not Available";
	hotness = _hotness;
}
Containers::Song::Song(string _name, string _artist, double _hotness)
{
	name = _name;
	artist = _artist;
	hotness = _hotness;
}

void Containers::populateData() {
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
		{
			songList.push_back(Containers::Song(name, pop));
		}
	}
}
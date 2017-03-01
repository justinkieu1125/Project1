#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() {  
		name = "";
		weight = 0;
	};

	Baby(string s, int w) { // constructor
		name = s;
		weight = w;
	}

	// a "getter" method
	int getWeight() {
		return weight; // TO BE COMPLETED
	}

	// a "getter" method
	string getName() {
		return name; // TO BE COMPLETED
	}

private:
	string name;
	int weight;
};

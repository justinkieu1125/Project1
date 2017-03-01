#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		totalbirths = 0;
		lowestweight = 0;
	}

	// destructor
	~MedicalRecord() {
		cout << "Array destroyed." << endl;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {
		int searchArray[1000];
		for (int i = 0; i < totalbirths; i++)
		{
			for (int j = 0; j < totalbirths; j++)
			{
				if (array[i].getName() == array[j].getName())
				{
					searchArray[i]++;
				}
			}
		}

		int  popularName = 0;
		int max = searchArray[0];
		for (int i = 1; i < totalbirths; i++)
		{
			if (searchArray[i] > max)
			{
				max = searchArray[i];
				popularName = i;
			}
		}
		return array[popularName].getName(); 
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return totalbirths; 
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		return lowestweight; 
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		int names = 0;
		for (int i = 0; i < totalbirths; i++)
		{
			if (array[i].getName() == s)
				names++;
		}
		return names; 
	}

private:
	int totalbirths, lowestweight;
	Baby array[1000];
	void addEntry(Baby b) {
		array[totalbirths] = b;
		totalbirths++;
	}

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions

};

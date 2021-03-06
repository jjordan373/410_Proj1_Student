/***
 * KP Utils
 */
#include <unistd.h>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "utilities.h"
#include "stdlib.h"

using namespace std;

//********************** private to this compilation unit **********************


vector <process_stats> stats;
bool cpusort (process_stats, process_stats);
bool procnumsort (process_stats, process_stats);
bool starttimesort (process_stats, process_stats);
bool iotimesort (process_stats, process_stats);

//if myString does not contain a string rep of number returns o
//if int not large enough has undefined behaviour, very fragile
int stringToInt(const char *myString) {
	return atoi(myString);
}

int loadData(const char* filename, bool ignoreFirstRow) {
	ifstream file;
	file.open(filename);
	stats.clear();

	if (!file.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	string ln;
	while(getline(file, ln)) {
		if (ignoreFirstRow) {
			ignoreFirstRow = false;
		}
		else {
			stringstream sstream(ln);
			string curr;
			vector<string> data;
			while (getline(sstream, curr, CHAR_TO_SEARCH_FOR)) {
				data.push_back(curr);
			}

			if (data.size() == 4) {
				if ((std::count(data.begin(), data.end(), "")) == 0 &&
						(std::count(data.begin(), data.end(), " ")) == 0) {
					process_stats stat;
					stat.process_number = stoi(data[0]);
					stat.start_time = stoi(data[1]);
					stat.cpu_time = stoi(data[2]);
					stat.io_time = stoi(data[3]);
					stats.push_back(stat);
				}
			}
		}
	}
	return SUCCESS;
}


//will sort according to user preference
void sortData(SORT_ORDER mySortOrder) {
	if (mySortOrder == CPU_TIME) {
		std::sort(stats.begin(), stats.end(), cpusort);
	}
	else if (mySortOrder == PROCESS_NUMBER) {
		std::sort(stats.begin(), stats.end(), procnumsort);
	}
	else if (mySortOrder == START_TIME) {
		std::sort(stats.begin(), stats.end(), starttimesort);
	}
	else {
		std::sort(stats.begin(), stats.end(), iotimesort);
	}
}

process_stats getNext() {
	process_stats myFirst;
	myFirst = stats.front();
	stats.erase(stats.begin());
	return myFirst;
}

bool cpusort (process_stats x, process_stats y) {
	return (x.cpu_time < y.cpu_time);
}

bool procnumsort (process_stats x, process_stats y) {
	return (x.process_number < y.process_number);
}

bool starttimesort(process_stats x, process_stats y) {
	return (x.start_time < y.start_time);
}

bool iotimesort(process_stats x, process_stats y) {
	return (x.io_time < y.io_time);
}

//returns number of process_stats structs in the vector holding them
int getNumbRows(){
	return stats.size();
}



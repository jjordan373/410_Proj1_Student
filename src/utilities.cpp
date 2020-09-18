/***
 * KP Utils
 */
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

//if myString does not contain a string rep of number returns o
//if int not large enough has undefined behaviour, very fragile
int stringToInt(const char *myString) {
	return atoi(myString);
}

int loadData(const char* filename, bool ignoreFirstRow) {

	return SUCCESS;
}


//will sort according to user preference
void sortData(SORT_ORDER mySortOrder) {
	switch(mySortOrder) {
		case CPU_TIME:

	}
}

process_stats getNext() {
	process_stats myFirst;

	return myFirst;
}

bool cpusort (process_stats x, process_stats y) {
	if (x.cpu_time < y.cpu_time) {
		return true;
	}
	return false;
}

bool procnumsort (process_stats x, process_stats y) {
	if (x.process_number < y.process_number) {
		return true;
	}
	return false;
}

bool starttimesort(process_stats x, process_stats y) {
	if (x.start_time < y.start_time) {
		return true;
	}
	return false;
}

bool iotimesort(process_stats x, process_stats y) {
	if(x.io_time < y.io_time) {
		return true;
	}
	return false;
}

//returns number of process_stats structs in the vector holding them
int getNumbRows(){
	return 0;
}



// Lab07.cpp : Defines the entry point for the console application.
// Kyle Leadbetter COSC2300

#include "stdafx.h"
#include "Lab07-kleadbet.h"
#include "winTimer.h"
#include "RandomUtilities.h"
#include "ContainerPrinting.h"

#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;

vector<double>
getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}


	return theList;
}



int main()
{
	while (true)
	{
		cout << endl << "\tSort Algoritm" << endl
			<< "----------------------------" << endl
		  << "Enter size for numbers: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;
		randomizeSeed();
		

		// Construct a sorted list of numbers
		Timer get;
		get.start();
		vector<double> numbers = getNums(n, 1, 500);
		get.stop();
		cout << "Constructed in " << get() << " seconds"
			<< endl;

		

		// Report a most isolated isolated number
		Timer time;
		time.start();
		//sort(begin(numbers), end(numbers) );
		//bubbleSort(numbers);
		//insertSort(numbers);
		//selectSort(numbers);
		numbers = mergeSort(numbers);
		//numbers = quickSort(numbers);
		time.stop();
		if (n < 10) cout << numbers << endl << endl;
		cout << "Vector sorted in " << time() << " seconds"
			<< endl << endl;
	}
    return 0;
}


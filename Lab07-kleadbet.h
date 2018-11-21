//Kyle Leadbetter
#pragma once

#include <vector>
using namespace std;

void swapDouble(double &first, double &second)
{
	double tmp = first;
	first = second;
	second = tmp;
}

vector<double> bubbleSort(vector<double> &in)
{
	bool change = false;
	int checks = in.size() - 1;
	do
	{
		change = false;
		for (int i = 0; i < checks ; i++)
		{
			if (in[i] > in[i + 1])
			{
				swapDouble(in[i], in[i + 1]);
				change = true;
			}
		}
	} while (change);

	return in;
}


vector<double> insertSort(vector<double> &in)
{
	for (size_t i = 0; i < (in.size() - 1) ; i++)
	{
		double comp = in[i];
		int j = i - 1;
		while (j >= 0 && in[j] > comp)
		{
			in[j + 1] = in[j];
			j--;
		}
		in[j + 1] = comp;
	}
	return in;
}


vector<double> selectSort(vector<double> &in)
{
	for (size_t i = 0; i < in.size(); i++)
	{
		double min(501);
		int minPos(i);

		for (size_t j = i; j < in.size(); j++)
		{
			if (in[j] < min)
			{
				minPos = j;
				min = in[j];
			}
		}
		swapDouble(in[i], in[minPos]);
	}
	return in;
}

vector<double> merge(vector<double> left, vector<double> right)
{
	vector<double> merged;

	while (left.size() > 0 && right.size() > 0)
	{
		if (left.front() <= right.front())
		{
			merged.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			merged.push_back(right.front());
			right.erase(right.begin());
		}
	}
	if (left.size() > 0)
	{
		merged.insert(merged.end(), left.begin(), left.end());
	}
	if (right.size() > 0)
	{
		merged.insert(merged.end(), right.begin(), right.end());
	}

	return merged;
}



vector<double> mergeSort(vector<double> unsorted)
{
	if (unsorted.size() <= 1)
	{
		return unsorted;
	}
	vector<double> left;
	vector<double> right;
	for (size_t i = 0; i < unsorted.size(); i++)
	{
		if (i < (unsorted.size() / 2)) { left.push_back(unsorted[i]); }
		else { right.push_back(unsorted[i]); }
	}

	left = mergeSort(left);
	right = mergeSort(right);

	vector<double> sorted = merge(left, right);


	return sorted;
}



vector<double> quickSort(vector<double> in)
{
	if (in.size() <= 1)
	{
		return in;
	}
	vector<double> less;
	vector <double> equal;
	vector<double> greater;
	double pivot = in[((in.size() - 1) / 2)];
	for (size_t i = 0; i < in.size(); i++)
	{
		if (in[i] > pivot) { greater.push_back(in[i]); }
		else if (in[i] < pivot) { less.push_back(in[i]); }
		else { equal.push_back(in[i]); }
	}

	less = quickSort(less);
	greater = quickSort(greater);

	less.insert(less.end(), equal.begin(), equal.end());
	less.insert(less.end(), greater.begin(), greater.end());
	vector<double> result = less;
	return result;
}

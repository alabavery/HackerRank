//============================================================================
// Name        : HackerRank.cpp
// Author      : Al
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "NonDivisibleSubset.cpp"
using namespace std;


void print_vector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " " << flush;
	}
}


int main() {
	NonDivisibleSub nds = get_data();
	cout << get_maximal_subset(nds);
	return 0;
}

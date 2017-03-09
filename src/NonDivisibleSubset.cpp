/*
 * NonDivisibleSubset.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: alavery
 */

//divide into modulo groups
//decide 'incompatible pairs' of groups and take the maximum of each
	// - may need exception for modulo 0 and just take 1 element from it
// sum of this is answer?

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


struct NonDivisibleSub {
	vector<int> values;
	int k;
};


NonDivisibleSub get_data()
{
	string stdin;
	getline(cin, stdin);
	istringstream line1_stream(stdin);
	int n;
	line1_stream >> n;
	NonDivisibleSub nds;
	line1_stream >> nds.k;

	getline(cin, stdin);
	istringstream values_stream(stdin);

	for (int i = 0; i < n; i++)
	{
		int val;
		values_stream >> val;
		nds.values.push_back(val);
	}
	return nds;
}

vector<int> get_modulo_groups(vector<int> s, int k)
{
	vector<int> modulo_groups(k, 0);
	for(int i = 0; i < s.size(); i++)
	{
		modulo_groups[s[i] % k]++;
	}
	return modulo_groups;
}


int get_maximal_subset(NonDivisibleSub nds)
{
	vector<int> modulo_groups = get_modulo_groups(nds.values, nds.k);
	int maximal_subset;

	if (modulo_groups[0] > 0) maximal_subset = 1;
	else maximal_subset = 0;

	for (int i = 1; i < modulo_groups.size(); i++)
	{
		if (modulo_groups[i] == 0) continue;
		if (nds.k-i == i) {
			maximal_subset++;
			continue;
		}
		cout << "mod " << i <<  " is " << modulo_groups[i] << endl;
		cout << "mod " << nds.k-i <<  " is " << modulo_groups[nds.k-i] << endl;
		if (modulo_groups[i] > modulo_groups[nds.k-i])
		{
			cout << "max is mod " << i << "\n\n";
		} else {
			cout << "max is mod " << nds.k-i << "\n\n";
		}
		int bigger = max(modulo_groups[i], modulo_groups[nds.k-i]);
		maximal_subset += bigger;
		modulo_groups[i] = 0, modulo_groups[nds.k-i] = 0; // so we don't get double-counting
	}
	return maximal_subset;
}

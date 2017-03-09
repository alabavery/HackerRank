/*
 * BigFibonacci.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: alavery
 */
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


vector<int> int_to_vector(int integer)
// Note that this gives you the int in 'reverse' in the vector
{
	string s = to_string(integer);
	vector<int> returned_vector;
	int c;
	for (int i = 0; i < s.length(); i++)
	{
		c = s[i] - '0'; // this is subtracting the ascii value for '0' from ascii for s[i]
						// to 'normalize' to the actual int value
		returned_vector.insert(returned_vector.begin(), c);
	}
	return returned_vector;
}


int * split_digit_and_carry(int product)
{
	float f_ones_place = (float)product/10;
	int carry = (int)f_ones_place;
	f_ones_place -= carry;
	f_ones_place *= 10.01; // necessary .01 b/c of float imprecision

	int i_ones_place = static_cast<int>(f_ones_place);

	int * Ptr_returned_array = new int[2];
	Ptr_returned_array[0] = carry;
	Ptr_returned_array[1] = i_ones_place;
	return Ptr_returned_array;
}


vector<int> vector_multiply(vector<int> int_vector, int multiplier)
{
	int carry = 0;
	int this_product;
	vector<int> new_vector;

	for (int i = 0; i < int_vector.size(); i++)
	{
		this_product = multiplier * int_vector[i] + carry;
		int * split = split_digit_and_carry(this_product);
		new_vector.push_back(split[1]);
		carry = split[0];
		delete [] split;
	}
	if (carry > 0)
	{
		vector<int> carried_vector = int_to_vector(carry);
		new_vector.insert(new_vector.end(), carried_vector.begin(), carried_vector.end());
	}
	return new_vector;
}


vector<int> factorial(vector<int> int_vector, int multiplier)
{
	if (multiplier <= 1) return int_vector;
	else return factorial(vector_multiply(int_vector, multiplier), multiplier - 1);
}

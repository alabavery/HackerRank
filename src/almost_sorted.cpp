#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_sorted(vector<int> vec)
{
    for(int i = 1; i < vec.size(); i++)
    {
        if(vec[i] < vec[i-1]) return false;
    }
    return true;
}

vector<int> swap_vec(vector<int> vec, int first, int second)
{
    int temp = vec[first];
    vec[first] = vec[second];
    vec[second] = temp;
    return vec;
}

vector<int> is_swappable(vector<int> unsorted_vec)
{
    vector<int> swapped, swap_these;
    for(int first = 0; first < unsorted_vec.size() - 1; first++)
    {
        for(int second = first+1; second++)
        {
            swapped = swap_vec(unsorted_vec, first, second);
            if(is_sorted(swapped))
            {
                swap_these.push_back(first);
                swap_these.push_back(second);
                return swap_these;
            }
        }
    }
    return swap_these;
}


vector<int> reverse_vec(vector<int> vec, int start, int end)
{
    int len = end - start;
    vector<int> temp;
    for(int i = end; i >= start; i--) temp.push_back(vec[i]);
    for(int i = start; i <= end; i++) vec[i] = temp[i-start];
    /*for(int i = start; start <= len/2; start++)
    {
        temp = vec[start];
        vec[start] = vec[];
        vec[en]
    }*/
    return vec;
}


vector<int> is_reversable(vector<int> unsorted_vec)
{
    vector<int> reversed, reverse_these;
    if(unsorted_vec.size() <= 2) return reverse_these; // would've been caught by swap
    
    for(int num_to_reverse = 3; num_to_reverse < unsorted_vec.size(); num_to_reverse++) // make sure there is no 'off by one' here
    {
        for(int start_reverse = 0; start_reverse + num_to_reverse < unsorted_vec.size(); start_reverse++)
        {
            reversed = reverse_vec(unsorted_vec, start_reverse, start_reverse + num_to_reverse);
            if(is_sorted(reversed)) 
            {
                reverse_these.push_back(start_reverse);
                reverse_these.push_back(start_reverse + num_to_reverse);
                return reverse_these;
            }
        }
    }
    return reverse_these;
}


void almost_sorted(vector<int> unsorted_vec)
{
    if(is_sorted(unsorted_vec))
    {
        cout << "yes" << endl;
        return;
    } else {
        vector<int> swap_these = is_swappable(unsorted_vec);
        if(swap_these.size() > 0)
        {
            cout << "yes" << endl;
            cout << "swap " << swap_these[0] << " " << swap_these[1] << endl;
            return;
        }
        vector<int> reverse_these = is_reversable(unsorted_vec);
        if(reverse_these.size() > 0)
        {
            cout << "yes" << endl;
            cout << "reverse " << reverse_these[0] << " " << reverse_these[1] << endl;
            return;
        }
    }
    cout << "no" << endl;
}

int main() {
    int len, num;
    cin >> len;
    vector<int> unsorted_vec;
    for(int i = 0; i < len; i++)
    {
        cin >> num;
        unsorted_vec.push_back(num);
    }
    almost_sorted(unsorted_vec);
    return 0;
}

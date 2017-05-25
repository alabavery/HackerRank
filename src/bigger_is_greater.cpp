#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<char> alphabetize_vec_tail(vector<char> vec, int tail_start)
{
    sort(vec.begin()+tail_start, vec.end());
    return vec;
}


int compare_char_to_tail(vector<char> vec, int char_index)
{
    for(int i=vec.size()-1; i>char_index; i--)
    {
        if(vec[i] > vec[char_index]) return i;
    }
    return -1;
}


vector<char> bigger_is_greater(vector<char> target_vec)
{
    // edge case vec of length 1
    for(int reverse_iterator=target_vec.size()-2; reverse_iterator>=0; reverse_iterator--)
    {
        int bigger_char_index = compare_char_to_tail(target_vec, reverse_iterator);
        if(bigger_char_index >= 0)
        {
            char temp = target_vec[reverse_iterator];
            target_vec[reverse_iterator] = target_vec[bigger_char_index];
            target_vec[bigger_char_index] = temp;
            target_vec = alphabetize_vec_tail(target_vec, bigger_char_index-1);
            return target_vec;
        }
    }
    vector<char> empty_vec; // in case, the word was already optimized, return emptyvec
    return empty_vec;
} 


void b_is_g_to_string(vector<char> final_vec)
{
    if(final_vec.size() == 0) cout << "no answer" << endl;
    else {
        for(int i=0; i<final_vec.size(); i++) cout << final_vec[i];
        cout << endl;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num_lines;
    cin >> num_lines;
    int i=0;
    
    string s;
    getline(cin,s);
    while(i < num_lines)
    {
        getline(cin,s);
        vector<char> v;
        for(int char_ctr=0;char_ctr<s.length();char_ctr++) v.push_back(s.at(char_ctr));
        b_is_g_to_string(bigger_is_greater(v));
        i++;
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
 

int get_next_hour(int current_hour) //untested
{
    if(current_hour == 12) return 1;
    return current_hour + 1;
}


string int_to_words(int i) //untested
{
    // this used for EVERYTHING, including hour
    // will never receive anything over 39
    static const string under_twenty_strings[] = {"","one","two","three","four","five","six","seven","eight","nine",
                                "ten","eleven","twelve","thirteen","fourteen","quarter","sixteen",
                                "seventeen","eighteen","nineteen"};
    map<int,string> tens_place_strings = {{2,"twenty"},{3,"thirty"}}; 
 
    if(i < 20) return under_twenty_strings[i];
    if(i == 30) return "half";
    
    // remember, nothing under 20 or over 39 makes it to here, so this WILL be either 2 or 3
    int tens_place = i / 10;
    int ones_place = i % 10;
    return tens_place_strings[tens_place] + " " + under_twenty_strings[ones_place];
}


string get_minute_string(int i) //untested
{
    if(i % 15 == 0) return int_to_words(i); // 15 and 30 will be translated to quarter and half in int_to_words
    return int_to_words(i) + " minutes";
}


void time_to_words(int h, int m) //untested
{
    if(m == 0)
    {
        cout << int_to_words(h) <<" o' clock" << endl;
        return;
    }
    string past_to, hour_string, minute_string;
    if(m < 31)
    {
        past_to = "past";
        minute_string = get_minute_string(m);
        hour_string = int_to_words(h);
    } else {
        past_to = "to";
        minute_string = get_minute_string(60-m);
        hour_string = int_to_words(get_next_hour(h));
    }
    cout << minute_string <<" "<< past_to <<" "<< hour_string << endl;
}



int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;
    time_to_words(h,m);
    return 0;
}


#define _USE_MATH_DEFINES
#include<iostream>
#include<climits>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<queue>
#include<cmath>
#include<map>
#include<array>
#include<regex>
#include<string>

using namespace std;

int main() {

    //one single rotation covers 9 degrees
	#ifndef ONLINE_JUDGE
  		freopen("ip1.txt", "r", stdin);
  		freopen("out1.txt", "w", stdout);
	#endif

   string s;
   while(getline(cin, s)) {

    int totalSpins = 120;

    size_t pos = s.find(" ");
    int initial = stoi(s.substr(0, pos));
    s.erase(0, pos + 1);


    pos = s.find(" ");
    int first = stoi(s.substr(0, pos));
    s.erase(0, pos + 1);

    pos = s.find(" ");
    int second = stoi(s.substr(0, pos));
    s.erase(0, pos + 1);

    pos = s.find(" ");  
    int third = stoi(s.substr(0, pos));
    s.erase(0, pos + 1);

    //Clockwise
    if(initial > first)
        totalSpins += (initial - first);
    
    else
        totalSpins += (initial + (40 - first));
    
    //AntiClockwise
    if(second > first)
        totalSpins += (second - first );

    else
        totalSpins += (40 - first) + second;

    //Clockwise
    if(second > third)
        totalSpins += (third - second);
    
    else
        totalSpins += (second + (40 - third));

    long long result =totalSpins * 9;
    cout<<result<<endl;

   }
   return 0;

}
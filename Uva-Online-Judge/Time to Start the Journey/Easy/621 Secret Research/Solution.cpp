
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




using namespace std;



void solve() { 

    string s;
    cin >> s;


    if(s == "1" || s == "4" || s == "78")
        cout<<"+"<<endl;
    
    else if(regex_match(s, regex("[0-9]*35$")))
        cout<<"-"<<endl;
    
    else if(regex_match(s, regex("^190[0-9]*")))
        cout<<"?"<<endl;
    
    else
        cout<<"*"<<endl;
}



int main() {

    //one single rotation covers 9 degrees
	#ifndef ONLINE_JUDGE
  		freopen("ip1.txt", "r", stdin);
  		freopen("out1.txt", "w", stdout);
	#endif

    int t;
    cin >> t;
    while(t--) {

        solve();
    } 

}
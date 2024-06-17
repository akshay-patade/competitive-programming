
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
    unordered_map<string, string>mp ={{"HELLO","ENGLISH"}, {"HOLA","SPANISH"}, {"HALLO", "GERMAN"},{"BONJOUR", "FRENCH"}, {"CIAO", "ITALIAN"}, {"ZDRAVSTVUJTE", "RUSSIAN"} };


    cout<<mp[s]<<endl;
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
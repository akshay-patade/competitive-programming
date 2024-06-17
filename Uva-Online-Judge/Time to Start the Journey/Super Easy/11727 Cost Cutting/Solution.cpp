
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

    int a, b, c;
    cin >> a >> b >> c;

    if((a > b && a < c) || (a > c && a < b))
        cout<<a<<endl;
    
    else if((b > c && b < a ) || (b > a && b < c))
        cout<<b<<endl;
    
    else
        cout<<c<<endl;

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
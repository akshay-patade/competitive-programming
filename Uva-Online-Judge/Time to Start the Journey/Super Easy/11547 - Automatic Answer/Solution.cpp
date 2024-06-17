
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

    long long  num;
    cin >> num;

    num *= 567;
    num /= 9;
    num += 7492;
    num *= 235;
    num /= 47;
    num -= 498;

    num /= 10;

    cout<<abs(num % 10) <<endl;
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
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

    int n, m;
    cin >> n >> m;

    int rowVal = n - 2;
    int colVal = m - 2;

    long long result = ceil(rowVal / 3.0) * ceil(colVal / 3.0);
    cout<<result<<endl;
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
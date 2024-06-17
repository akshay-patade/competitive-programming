
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

    int k;
    cin >> k;
    int divPointX, divPointY, x, y;
    cin >> divPointX >> divPointY;

    while(k--) {

        string result="";
        cin >> x >> y;
        if(x == divPointX || y == divPointY)
            result = "divisa";
        
        else if(x > divPointX && y > divPointY)
            result = "NE";
        
        else if(x < divPointX && y > divPointY)
            result = "NO";
        
        else if(x < divPointX && y < divPointY)
            result = "SO";
        
        else
            result = "SE";
        
        cout<<result<<endl;
    }

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
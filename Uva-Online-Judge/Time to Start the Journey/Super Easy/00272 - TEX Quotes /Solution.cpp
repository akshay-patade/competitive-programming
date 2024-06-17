
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

	#ifndef ONLINE_JUDGE
  		freopen("ip1.txt", "r", stdin);
  		freopen("out1.txt", "w", stdout);
	#endif

   string s;
   
   while( getline(cin, s)) {

    string result = "";
    int pos = s.find('"');
    bool open = true;
    
    while(pos != -1) {
    
        if(pos != 0)
            result = result + s.substr(0, pos);

        result += open ? "``" : "''";
        open = !open;
        s = s.substr(pos + 1, s.length() - pos);
        pos = s.find('"');
    }

    result += s;
    cout<<result<<endl;
    }
}

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
#include<iomanip>





using namespace std;

const int MAX_ARRAY_INDEX = 100005;

template<typename T>T max(T &a, T &b) {
    
    return a > b ? a : b;
}
template<typename T> bool isPrime(T &a) {

    T temp = 2;
    for(; temp * temp < a; temp++) {

        if((a % temp) == 0)
            return false;
    }
    return true;
}

template<typename T> T gcd(T &a, T &b) {

    if(b == 0)
        return a;
    
    return gcd(b, a % b);
}

template<typename T> long long  power(T &a, T &b) {

    long long  result = 1;
    while(b > 0) {

        if(b & 1)
            result = result * a;
        
        else
            a = a * a;
        
        b >>= 1;
    }

    return result;
}

struct Node{

    int val;
    int count = 0;

    bool operator<(const Node &a) const{

        return this->count < a.count;
    }
};


vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {

    unordered_map<int, long long > map; // Number along with its frequency;
    priority_queue<Node> pq;
    vector<long long > result;

    for(int i = 0; i < nums.size(); i++) {

        //Number is not present in the priority Q
        Node temp;
        temp.val = nums[i];
        map[nums[i]] += freq[i];
        temp.count = map[nums[i]];
        pq.push(temp);

        while(!pq.empty() && map[pq.top().val] != pq.top().count) {

            pq.pop();
        }
        
        result.push_back(pq.top().count);
    }

    return result;
}

void generatePermutations(int i, set<string> &result, vector<char> alphabets, string temp) {

    if(i == alphabets.size()) {

        result.insert(temp);
        return;
    }

    
    for(int j = i; j < alphabets.size(); j++) {

        swap(alphabets[i], alphabets[j]);
        temp.push_back(alphabets[i]);
        generatePermutations(i + 1, result, alphabets, temp);
        swap(alphabets[i], alphabets[j]);
        temp.pop_back();
    }
}

class TrieNode {

    public:
        TrieNode *characters[26];
        int minimumLengthIndex;
        int minimumLength;
    
        TrieNode() {

            for(int i = 0; i < 26; i++) {

                characters[i] = NULL;
                minimumLengthIndex = 0;
                minimumLength = INT_MAX;
            }
        }

};

void insertWord(TrieNode *root, string word, int wordIndex) {

    for(int i = 0; i < word.size(); i++) {

        int indexCharacter = word[i] - 'a';

        if(root->characters[indexCharacter] == NULL)
            root->characters[indexCharacter] = new TrieNode();
        
        if(root->characters[indexCharacter]->minimumLength > word.size()) {

            root->characters[indexCharacter]->minimumLength = word.size();
            root->characters[indexCharacter]->minimumLengthIndex = wordIndex;
        }

        root = root->characters[indexCharacter];
    }
}

int searchWord(TrieNode *root, string word) {

    for(int i = 0; i < word.size(); i++) {

        if(root->characters[word[i] - 'a'] == NULL)
            break;

        root = root->characters[word[i] - 'a'];        
    }

    return root->minimumLengthIndex;
}



vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

    //Reverse each word in the words Container
    for(int i = 0; i < wordsContainer.size(); i++)
        reverse(wordsContainer[i].begin(), wordsContainer[i].end());
    
    //Reverse each word query in the query container
    for(int i = 0; i < wordsQuery.size(); i++)
        reverse(wordsQuery[i].begin(), wordsQuery[i].end());
    
    TrieNode *root = new TrieNode();
    TrieNode *head = root;

    // Insert the words in Trie
    for(int i = 0; i < wordsContainer.size(); i++) {

        int wordSize = wordsContainer[i].length();
        if(root->minimumLength > wordSize) {

            root->minimumLength = wordSize;
            root->minimumLengthIndex = i;
        }

        insertWord(root, wordsContainer[i], i);
    }

    vector<int> result(wordsQuery.size(), 0);
    for(int i = 0; i < wordsQuery.size(); i++)
        result[i] = searchWord(root, wordsQuery[i]);
    

    return result;
}


bool isSubstringPresent(string s) {

    string reverseString = s;
    reverse(reverseString.begin(), reverseString.end());

    for(int i = 0; i < s.length() - 1; i++) {

        string ogString = s.substr(i, 2);
        for(int j = 0; j < reverseString.length() - 1; i++) {

            string revString = s.substr(j, 2);
            if(ogString == revString)
                return true;
        }
    }

    return false;
}

int minimumSubarrayLength(vector<int>& nums, int k) {

    int totalOr = 0;

    int positionMSB = log2(k);
    int maskMSBK = 1 << positionMSB;

    vector<int> positions;

    for(int i = 0; i < nums.size(); i++) {

        totalOr |= nums[i];

        if(nums[i] >= k)
            return 1;
        
        else if( (nums[i] & maskMSBK) > 0)
            positions.push_back(i);
    }
    
    if(totalOr < k)
        return -1;
    
    int length = INT_MAX;

    for(int i = 0; i < positions.size(); i++) {

        //First go left and check if the value is getting increased
        int rightBoundary = positions[i];
        int number = nums[rightBoundary];
        int leftBoundary = rightBoundary - 1;
        while(leftBoundary > -1) {

            number |= nums[leftBoundary--];
            if(number >= k) {

                if(length > (rightBoundary - leftBoundary))
                    length = rightBoundary - leftBoundary;
                
                else
                    break;
            }

            else if((rightBoundary - leftBoundary) > length)
                break;
        }


        //Logic for going right;
        leftBoundary = positions[i];
        number = nums[leftBoundary];
        rightBoundary = leftBoundary + 1;

        while(rightBoundary < nums.size()) {

            number |= nums[rightBoundary++];
            if(number >= k) {

                if(length > (rightBoundary - leftBoundary))
                    length = rightBoundary - leftBoundary;
                
                else
                    break;
            }

            else if((rightBoundary - leftBoundary) > length)
                break;
        }
    }

    if(length == INT_MAX)
        return -1;

    return length;
}

int maxBottlesDrunk(int numBottles, int numExchange) {

    int bottlesDrank = numBottles;
    int currEmptyBottle = numBottles;

    while(currEmptyBottle >= numExchange) {

        int currDrank = currEmptyBottle / numExchange;
        
        bottlesDrank += currDrank;
        currEmptyBottle = currDrank + currEmptyBottle % numExchange;
    }

    return bottlesDrank;
}



vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
    
    vector<vector<pair<int, int>>> graph(n);
    vector<int> result(n);
    for(int i = 0; i < edges.size(); i++) {
        
        int source = edges[i][0];
        int destination = edges[i][1];
        int length = edges[i][2];
        
        graph[source].push_back(make_pair(length, destination));
    }
    
    long long minDistance[n];
    for(int i = 0; i < n; i++)
        minDistance[i] = INT_MAX;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    minDistance[0] = 0;
    pq.push(make_pair(0, 0)); //First pair is the distance and other is the node
    
    while(!pq.empty()) {
    
        
        auto data = pq.top();
        pq.pop();
        
        int node = data.second;

        //Check if that node is not disappered. If not disappeared then we can traverse from that node
        if(disappear[node] <= data.first)
            continue;
        
        //This is a 2d vector
        for(const auto &it: graph[node]) {

            int wt = minDistance[node] + it.first;
            if( wt < minDistance[it.second] && disappear[it.second] >= wt) {
                
                minDistance[it.second] = wt;
                pq.push(make_pair(wt, it.second));
            }
        }
    }
    
    
    for(int i = 1; i < n; i++) {

        if(minDistance[i] >= disappear[i])
            result[i] = -1;
        
        else
            result[i] = minDistance[i];
    }
    
    return result;
}

vector<int> permute(vector<int> &sequence, vector<int> &permutation) {

    vector<int> newSequence(permutation.size());

    for(int i = 1; i <= sequence.size(); i++)
        newSequence[i] = sequence[permutation[i]];
    
    return newSequence;
}


void binaryExponential(vector<int> &sequence, vector<int> &permutation, int k) {

    while(k > 0) {

        //Power is odd. Apply the permutation to the sequence
        if(k & 1)
            sequence = permute(sequence, permutation);
        
        permutation = permute(permutation, permutation);
        k >>= 1;
    }
}

void solve() { 

    int s,b;
    cin >> s >> b;

    vector<int> left(s + 1, -1);
    vector<int> right(s + 1, -1);

    for(int i = 1; i <= s; i++) {

        left[i] = i - 1;
        right[i] = i + 1;
    }

    right[s] = -1;
    left[1] = -1;

    // for(int i = 1;i <= s; i++) {

    //     cout<<"Left neighbour of "<<i <<" is "<<left[i]<<endl;
    //     cout<<"Right neighbour of "<<i <<" is "<<right[i]<<endl;
    // }


    for(int i = 1; i <= b; i++) {

        int l, r;
        cin >> l >> r;

        if(right[r] != -1)
            left[right[r]] = left[l];
        
        if(left[l] != -1)
            right[left[l]] = right[r];

        if(left[l] == -1)
            cout<<"* ";
        
        else
            cout<<left[l]<<" ";
        
        if(right[r] == -1)
            cout<<"* ";
        
        else
            cout<<right[r]<<" ";
        
        cout<<endl;
    }

    cout<<"-"<<endl;


}


int main() {

    //one single rotation covers 9 degrees
	#ifndef ONLINE_JUDGE
  		freopen("ip1.txt", "r", stdin);
  		freopen("out1.txt", "w", stdout);
	#endif
    // int t;
    // cin >> t;
    // while(t--) {

        solve();
    // } 
}
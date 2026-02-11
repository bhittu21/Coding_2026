#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    map<string, int> mp;
    string team;

    while(n--){
        cin >> team;
        mp[team]++;
    }

    string winer;
    int max_goal = 0;

    for(auto ch: mp){
        if(ch.second > max_goal){
            max_goal = ch.second;
            winer = ch.first;
        }
    }

    cout << winer << endl;

    return 0;
}
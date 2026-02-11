#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int s,n;
    cin >> s >> n;

    vector<pair<int, int>> vect(n);

    for(int i=0;i<n;i++){
        cin >> vect[i].first >> vect[i].second;
    }

    sort(vect.begin(), vect.end());

    for(auto i: vect){
        if(s>i.first){
            s+=i.second;
        } else{
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
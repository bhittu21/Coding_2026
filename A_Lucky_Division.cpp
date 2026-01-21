#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int s;
    cin >> s;

    vector<int> vect = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};

    for (int x:vect){
        if(s%x==0){
            cout << "YES" << endl;
            return 0;
        } 
    }

    cout << "NO" << endl;


    return 0;
}
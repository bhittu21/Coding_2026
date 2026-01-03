#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    cin >> s;

    int sum=0;

    for(char ch:s){
        if(ch =='4' || ch=='7'){
            sum++;
        }
    }

    if(sum==4 || sum==7) cout << "YES" << endl;
    else {
        cout << "NO" << endl;
    }

    return 0;
}
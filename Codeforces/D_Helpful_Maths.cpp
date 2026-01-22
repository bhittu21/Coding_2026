#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    cin >> s;

    vector<char> vect;

    for(char ch:s){
        if(ch!='+'){
            vect.push_back(ch);
        }
    }

    sort(vect.begin(), vect.end());

    for(int i=0;i<vect.size();i++){
        cout << vect[i];
        if(i==vect.size()-1){
            break;
        }
        cout << "+";
    }

    return 0;
}
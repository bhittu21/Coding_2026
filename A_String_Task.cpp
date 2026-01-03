#include <bits/stdc++.h>
using namespace std;


int main() {
    
    string s;
    cin >> s;

    for(char &ch:s){

        ch =  tolower(ch);

        if( ch == 'a' || ch == 'A' ||
            ch == 'e' || ch == 'E' ||
            ch == 'i' || ch == 'I' ||
            ch == 'o' || ch == 'O' ||
            ch == 'u' || ch == 'U')
            {
                ch = '.';
            }
    }

    if(s[0] != '.'){
        cout << ".";
    }

    for(int i=0;i<s.length();i++){

        if(i==s.length()-1 && s[i]=='.'){
            break;
        }

        if(s[i+1] && s[i] == '.' && s[i+1]=='.'){
            continue;
        }

        if(i>1 && s[i] != '.' && s[i-1]!='.'){
            cout << ".";
        }

        cout << s[i];
    }

    return 0;
}
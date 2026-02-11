#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    cin >> s;

    bool allUpper = true;

    int size = s.length();

    for(int i=1;i<size;i++){
        if(islower(s[i])){
            allUpper=false;
            break;
        }
    }

    if(allUpper){
        for(char &ch:s){
            if(islower(ch)) ch = toupper(ch);
            else{
                ch=tolower(ch);
            }
        }
    }

    cout << s << endl;

    return 0;
    
}
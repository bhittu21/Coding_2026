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
        if(s[0]>='a' && s[0]<='z'){
            s[0] = toupper(s[0]);
        }

        for(int i=1;i<size;i++){
            s[i] = tolower(s[i]);
        }
    }

    cout << s << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    cin >> s;

    int cap = 0;
    int small = 0;

    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i] <= 'z'){
            small++;
        }
        else if(s[i]>='A' && s[i]<='Z'){
            cap++;
        }
    }

    if(cap>small){
        for(char &ch:s){
            ch = toupper(ch);
        }

        cout << s << endl;
    }

    else {
        for(char &ch:s){
            ch=tolower(ch);
        }

        cout << s << endl;
    }


    return 0;
}
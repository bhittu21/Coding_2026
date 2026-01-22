#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s1,s2,s3;

    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);

    int cnt[26]={0};

    for(char ch:s1) cnt[ch - 'A']++;
    for(char ch:s2) cnt[ch - 'A']++;
    for(char ch:s3) cnt[ch - 'A']--;

    int flag=1;
    for(int i=0;i<26;i++){
        if(cnt[i]!=0){
            flag=0;
            break;
        }
    }

    cout << ((flag==1)?"YES":"NO");

    return 0;
}
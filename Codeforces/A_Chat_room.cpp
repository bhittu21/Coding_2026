#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    cin >> s;

    int size = s.length();

    char arr[100];
    int k=0;

    for(int i=1;i<size-1;i++){
        if(s[i]==s[i-1]) continue;
        else{
            arr[k] = arr[i];
            k++;
        }
    }

    for(int i=0;i<k;i++) cout << arr[i];

    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long n;
    cin >> n;

    long long taxi=0, one=0,two=0;

    while(n--){
        int x;
        cin >> x;

        if(x==4) taxi++;
        else if(x==3){
            taxi++;
            if(one>0) one--;
        } else if(x==2){
            two=0;
            if(two==2){
                taxi++;
                two=0;
            }
        } else {
            one++;
        }

    }

    cout << taxi+1 << endl;

    return 0;
}
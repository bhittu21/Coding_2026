#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int k,n,w;
    cin >> k >> n >> w;

    int needed = 0;

    for(int i=1;i<=w;i++){
        needed+=k*i;
    }

    if(needed>n) cout << needed-n << endl;
    else {
        cout << "0" << endl;
    }

    return 0;
}
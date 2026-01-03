#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    long long x=0;
    long long y=0;
    long long z=0;

    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        x+=a;
        y+=b;
        z+=c;
    }

    if(x==0 && y==0 && z==0) cout << "YES" << endl;
    else {
        cout << "NO" << endl;
    }

    return 0;
}
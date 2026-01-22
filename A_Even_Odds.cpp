#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long x,y;
    cin >> x >> y;

    if(y <= ((x+1)/2)){
        // odd
        cout << (2*y)-1 << endl;
    } else {
        // even
        cout << 2*(y-((x+1)/2)) << endl;
    }

    return 0;
}
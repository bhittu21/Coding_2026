#include <bits/stdc++.h>
using namespace std;

int main() {

    int x,y;
    cin >> x >> y;

    int sum=0;

    while(x<=y){
        x*=3;
        y*=2;
        sum++;
    }

    cout << sum << endl;

    return 0;
}


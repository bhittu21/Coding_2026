#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long int x,y;
    cin >> x >> y;

    while(y--){
        if(x%10!=0) x--;
        else if(x%10==0) x/=10;
    }

    cout << x << endl;

    return 0;
}
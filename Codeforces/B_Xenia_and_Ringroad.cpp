#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long int n,m;
    cin >> n >> m;

    long long int steps = 0;
    long long int curr = 1;

    for(int i=0;i<m;i++){
        int tar;
        cin >> tar;

        if(tar>=curr){
            steps+= tar-curr;
        } else {
            steps+= (n-curr)+tar;
        }
        curr = tar;
    }

    cout << steps << endl;

    return 0;
}
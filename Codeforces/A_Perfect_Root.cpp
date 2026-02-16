#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    while (test_case--) {
        int x,y;
        cin >> x;

        if(x==1){
            cout << "1" << endl;
            continue;
        }

        y = x;

        for(int i=0;i<x-1;i++){
            if(i==0){
                cout << y << " ";
            }
            cout << pow(y,2) << " ";
            y++;
        }

        cout << endl;

    }

    return 0;
}
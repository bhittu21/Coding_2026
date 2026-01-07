#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    while (test_case--) {
        int x,y;
        cin >> x >>y;
        
        int flag=0;
        for(int i=1;i<=100;i++){
        if(i%x!=0 && i%y!=0){
            cout << i << endl;
            flag=1;
            break;
        }
    }

        if(!flag) cout << "-1" << endl; 
        
    }

    return 0;
}
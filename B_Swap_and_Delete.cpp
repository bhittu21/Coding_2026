#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    while (test_case--) {
        
        string s;
        cin >> s;

        int lenS = s.length();

        if(lenS == 1){
            cout << "1" << endl;
            continue;
        }

        int cnt0 = count(s.begin(), s.end(), '0');
        int cnt1 = count(s.begin(), s.end(), '1');

        if(cnt0==cnt1) {
            cout << "0" << endl;
            continue;
        }

        if(lenS > 4){
            if(cnt1 != cnt0){
                cout << max(cnt0, cnt1) << endl;
            }
        }  
        else {
            cout << max(cnt1, cnt0) - min(cnt1, cnt0) << endl;
        }

    }

    return 0;
}
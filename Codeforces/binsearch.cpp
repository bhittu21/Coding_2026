#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    while (test_case--) {
        int x;
        cin >> x;

        string s1,s2;
        cin >> s1 >> s2;

        if(x==1){
            if(s1==s2) cout << "YES" << endl;
            else {
                cout << "NO" << endl;
            }
            continue;
        }
        
        int cnt_1 = count(s1.begin(), s1.end(), '1');
        int cnt_2 = count(s2.begin(), s2.end(), '1');

        if(cnt_1==cnt_2)
        
    }

    return 0;
}
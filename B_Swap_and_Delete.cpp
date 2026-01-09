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

        int cnt_of_t = 0;

        for(int i=0;i<lenS;i++){
            if(s[i] == '0' && cnt1>0){
                cnt1--, cnt_of_t++;
            } else if(s[i] == '1' && cnt0>0){
                cnt0--, cnt_of_t++;
            } else {
                break;
            }
        }

        cout << lenS-cnt_of_t << endl;

    }

    return 0;
}
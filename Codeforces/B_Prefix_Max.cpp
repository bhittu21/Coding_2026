#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    while (test_case--) {
        int x;
        cin >> x;

        vector<int> vect(x);
        for(int i=0;i<x;i++) cin >> vect[i];

        cout << *max_element(vect.begin(), vect.end())*x << endl;
    }

    return 0;
}
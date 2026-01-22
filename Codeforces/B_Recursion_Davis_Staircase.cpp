#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mem;

int stepPerms(int n){
    if(n<3) return n;
    else if(n==3) return 4;

    if(mem.count(n)){
        return mem[n];
    }

    mem[n] = stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3);

    return mem[n];
}

int main() {
    int test_case;
    cin >> test_case;

    while (test_case--) {
        int x;
        cin >> x;
        int out = stepPerms(x);
        cout << out << endl;
    }

    return 0;
}
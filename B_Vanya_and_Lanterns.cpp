#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long n,l;
    cin >> n >> l;

    vector<int> vect(n);

    double d;

    for(int i=0;i<n;i++){
        cin >> vect[i];
    }

    sort(vect.begin(), vect.end());

    d = max((double)vect[0], (double)(l - vect[n-1]));

    for(int i=0;i<n-1;i++) {
        double gap = (vect[i+1]-vect[i])/2.0;
        d = max(d, gap);
    }

    cout << fixed << setprecision(10) << d << endl;

    return 0;
}
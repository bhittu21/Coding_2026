#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<int> vect(n);

    int total_sum=0;

    for(int i=0;i<n;i++) cin >> vect[i], total_sum+=vect[i];

    int my_sum=0, cnt=0;

    sort(vect.rbegin(), vect.rend());

    for(int x:vect){
        my_sum+=x;
        cnt++;
        if(my_sum>(total_sum-my_sum)){
            break;
        }
    }

    cout << cnt << endl;
    
    return 0;
}
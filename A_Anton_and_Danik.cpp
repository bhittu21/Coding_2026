#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    char arr[n];

    int anton = 0;
    int danik = 0;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i] == 'A') anton++;
        else {
            danik++;
        }
    }

    if(anton==danik){
        cout << "Friendship" << endl;
    } else {
        if(anton>danik){
            cout << "Anton" << endl;
        } else {
            cout << "Danik" << endl;
        }
    }

    return 0;
}
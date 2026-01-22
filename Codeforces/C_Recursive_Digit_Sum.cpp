#include <bits/stdc++.h>
using namespace std;

int superDigit(string s, int x){
    
    long long sum=0;
    for(char ch:s) sum+= ch - '0';

    sum*=x;

    if (sum<10) return sum;

    return superDigit(to_string(sum), 1);

}

int main() {
    
    string s;
    int y;
    cin >> s >> y;

    int out = superDigit(s,y);

    cout << out << endl;

    return 0;
}
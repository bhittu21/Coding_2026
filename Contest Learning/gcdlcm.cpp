#include<bits/stdc++.h>

using namespace std;

int gcdGlobal;

void gcd(int x, int y){

    int rem;

    while(y!=0){
        rem=x%y;
        x=y;
        y=rem;
    }

    cout << "GCD is " << x << endl;
    gcdGlobal=x;

}

void lcm(int x1, int x2){

    cout << "LCM is " << (x1*x2)/gcdGlobal << endl;

}

int main(){

    int n1,n2;
    cin >> n1 >> n2;

    gcd(n1, n2);
    lcm(n1, n2);

}

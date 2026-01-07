#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        vector<int> vect;

        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                vect.push_back(i);
                if(i!=n/i){
                    vect.push_back(n/i);
            }

        }

        


    }

        sort(vect.begin(), vect.end());

        for(int x:vect) cout << x << " ";

        //cout << vect.size() << endl;


}
}





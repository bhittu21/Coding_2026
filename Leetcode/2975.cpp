#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1000000007LL;

        // Add fixed boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // Store all possible vertical distances
        unordered_set<long long> vDiff;
        int vsz = vFences.size();
        for (int i = 0; i < vsz; i++) {
            for (int j = i + 1; j < vsz; j++) {
                vDiff.insert((long long)vFences[j] - vFences[i]);
            }
        }

        long long maxSide = -1;

        // Match horizontal distances with vertical ones
        int hsz = hFences.size();
        for (int i = 0; i < hsz; i++) {
            for (int j = i + 1; j < hsz; j++) {
                long long d = (long long)hFences[j] - hFences[i];
                if (vDiff.count(d)) {
                    if (d > maxSide) maxSide = d;
                }
            }
        }

        if (maxSide == -1) return -1;

        return (int)((maxSide % MOD) * (maxSide % MOD) % MOD);
    }
};

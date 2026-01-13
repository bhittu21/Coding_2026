#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        double low = 1e18, high = -1e18;

        for (auto &s : squares) {
            total += 1.0 * s[2] * s[2];
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }

        double target = total / 2.0;

        for (int i = 0; i < 80; i++) {
            double mid = (low + high) / 2.0;
            double below = 0;

            for (auto &s : squares) {
                double h = mid - s[1];
                if (h > 0) {
                    h = min(h, (double)s[2]);
                    below += h * s[2];
                }
            }

            if (below < target) low = mid;
            else high = mid;
        }

        return low;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> squares(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> squares[i][0] >> squares[i][1] >> squares[i][2];
    }

    Solution sol;
    cout << fixed << setprecision(5) << sol.separateSquares(squares) << "\n";
    return 0;
}

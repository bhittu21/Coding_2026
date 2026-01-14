#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<long long> xs;
        vector<array<long long,4>> events;

        for (auto &s : squares) {
            long long x1 = s[0];
            long long x2 = s[0] + s[2];
            long long y1 = s[1];
            long long y2 = s[1] + s[2];
            xs.push_back(x1);
            xs.push_back(x2);
            events.push_back({y1, 1, x1, x2});
            events.push_back({y2, -1, x1, x2});
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto idx = [&](long long x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        int m = xs.size();
        vector<long long> cover(4 * m), cnt(4 * m);

        function<void(int,int,int,int,int,int)> update =
        [&](int node, int l, int r, int ql, int qr, int val) {
            if (ql >= r || qr <= l) return;
            if (ql <= l && r <= qr) {
                cnt[node] += val;
            } else {
                int mid = (l + r) / 2;
                update(node * 2, l, mid, ql, qr, val);
                update(node * 2 + 1, mid, r, ql, qr, val);
            }
            if (cnt[node] > 0) {
                cover[node] = xs[r] - xs[l];
            } else {
                cover[node] = (r - l == 1) ? 0 : cover[node * 2] + cover[node * 2 + 1];
            }
        };

        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });

        long double total = 0;
        long double lastY = events[0][0];

        for (auto &e : events) {
            long double y = e[0];
            total += cover[1] * (y - lastY);
            update(1, 0, m - 1, idx(e[2]), idx(e[3]), e[1]);
            lastY = y;
        }

        long double target = total / 2.0;
        fill(cover.begin(), cover.end(), 0);
        fill(cnt.begin(), cnt.end(), 0);

        long double cur = 0;
        lastY = events[0][0];

        for (auto &e : events) {
            long double y = e[0];
            long double area = cover[1] * (y - lastY);
            if (cur + area >= target) {
                return (double)(lastY + (target - cur) / cover[1]);
            }
            cur += area;
            update(1, 0, m - 1, idx(e[2]), idx(e[3]), e[1]);
            lastY = y;
        }

        return (double)lastY;
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

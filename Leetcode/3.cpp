#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);
        int left = 0;
        int res = 0;
        for (int right = 0; right < s.length(); right++) {
            if (m[s[right]] != -1) {
                left = max(left, m[s[right]] + 1);
            }
            m[s[right]] = right;
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main() {
    Solution sol;

    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";

    cout << "Input: " << s1 << " -> Output: " << sol.lengthOfLongestSubstring(s1) << endl;
    cout << "Input: " << s2 << " -> Output: " << sol.lengthOfLongestSubstring(s2) << endl;
    cout << "Input: " << s3 << " -> Output: " << sol.lengthOfLongestSubstring(s3) << endl;

    return 0;
}
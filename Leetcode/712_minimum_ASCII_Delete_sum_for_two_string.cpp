#include <stdio.h>
#include <string.h>

int minimumDeleteSum(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int dp[n + 1][m + 1];

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }

    for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int a = dp[i - 1][j] + s1[i - 1];
                int b = dp[i][j - 1] + s2[j - 1];
                dp[i][j] = a < b ? a : b;
            }
        }
    }

    return dp[n][m];
}

int main() {
    char s1[1005], s2[1005];
    scanf("%s %s", s1, s2);
    printf("%d\n", minimumDeleteSum(s1, s2));
    return 0;
}

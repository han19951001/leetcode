//
// Created by 韩国庆 on 2024/5/19.
//
class Solution {
public:
    int recursion(int m, int n){
        // base case
        if (m == 1){
            return 1;
        }
        if (n == 1){
            return 1;
        }
        int p1 = recursion(m - 1, n);
        int p2 = recursion(m, n - 1);

        return p1 + p2;
    }

    int uniquePaths(int m, int n) {
        int result = recursion(m, n);

        return result;
    }

    int uniquePaths2(int m, int n) {
        // int result = recursion(m, n);
        int dp[m][n];
        for (int i = 0; i < m; i++){
            dp[i][n - 1] = 1;
        }
        for (int j = 0; j < n; j++){
            dp[m - 1][j] = 1;
        }
        for (int k = m - 2; k >= 0; k--){
            for (int l = n - 2; l >= 0; l--){
                dp[k][l] = dp[k][l + 1] + dp[k + 1][l];
            }
        }

        return dp[0][0];
    }
};

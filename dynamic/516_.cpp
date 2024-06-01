//
// Created by 韩国庆 on 2024/5/30.
//
#include <string>

using namespace std;

class Solution {
public:
    int recursion(int start, int end, string& s) {
        // base case
        if (start == end) {
            return 1;
        }
        if (start > end) {
            return 0;
        }
        if (s[start] == s[end]) {
            return 2 + recursion(start + 1, end - 1, s);
        }
        return max(recursion(start, end - 1, s), recursion(start + 1, end, s));
    }

    int longestPalindromeSubseq(string s) {
        int result = recursion(0, s.size() - 1, s);
        return result;
    }

    int longestPalindromeSubseq2(string s) {
        int dp[s.size()][s.size()];

        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }
        for (int j = 1; j < s.size(); j++) {
            dp[j][j - 1] = 0;
        }
        for (int k = s.size() - 2; k >= 0; k--) {
            for (int l = k + 1; l < s.size(); l++) {
                if (s[k] == s[l]) {
                    dp[k][l] = 2 + dp[k + 1][l - 1];
                } else {
                    dp[k][l] = max(dp[k][l - 1], dp[k + 1][l]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};

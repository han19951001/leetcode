//
// Created by 韩国庆 on 2024/5/31.
//
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        if (s1.empty()) {
            for (const char& elem: s2) {
                sum += static_cast<int>(elem);
            }
            return sum;
        }
        if (s2.empty()) {
            for (const char& elem: s1) {
                sum += static_cast<int>(elem);
            }
            return sum;
        }
        int dp[s1.size()][s2.size()];
        for (int i = 0; i < s2.size(); i++) {
            if (s1[0] != s2[i]) {
                if (i == 0) {
                    dp[0][i] = static_cast<int>(s1[0]) + static_cast<int>(s2[i]);
                } else {
                    dp[0][i] = dp[0][i - 1] + static_cast<int>(s2[i]);
                }
            } else {
                if (i == 0) {
                    dp[0][i] = 0;
                } else {
                    dp[0][i] = dp[0][i - 1] - static_cast<int>(s1[0]);
                    for (int j = i + 1; j < s2.size(); j++) {
                        dp[0][j] = dp[0][j - 1] + static_cast<int>(s2[j]);
                    }
                    break;
                }
            }
        }
        for (int k = 0; k < s1.size(); k++) {
            if (s1[k] != s2[0]) {
                if (k == 0) {
                    dp[k][0] = static_cast<int>(s1[k]) + static_cast<int>(s2[0]);
                } else {
                    dp[k][0] = dp[k - 1][0] + static_cast<int>(s1[k]);
                }
            } else {
                if (k == 0) {
                    dp[k][0] = 0;
                } else {
                    dp[k][0] = dp[k - 1][0] - static_cast<int>(s2[0]);
                    for (int l = k + 1; l < s1.size(); l++) {
                        dp[l][0] = dp[l - 1][0] + static_cast<int>(s1[l]);
                    }
                    break;
                }
            }
        }
        for (int m = 1; m < s1.size(); m++) {
            for (int n = 1; n < s2.size(); n++) {
                if (s1[m] == s2[n]) {
                    dp[m][n] = dp[m - 1][n - 1];
                } else {
                    // int p1 = dp[m - 1][n - 1] + s1[m] + s2[n];
                    int p2 = dp[m - 1][n] + s1[m];
                    int p3 = dp[m][n - 1] + s2[n];
                    // dp[m][n] = min({p1, p2, p3});
                    dp[m][n] = min({p2, p3});
                }
            }
        }
        return dp[s1.size() - 1][s2.size() - 1];
    }
};

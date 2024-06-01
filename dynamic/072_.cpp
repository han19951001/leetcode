//
// Created by 韩国庆 on 2024/5/31.
//
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) {
            return word2.size();
        }
        if (word2.empty()) {
            return word1.size();
        }

        int dp[word1.size()][word2.size()];
        for (int i = 0; i < word2.size(); i++) {
            if (word1[0] != word2[i]) {
                dp[0][i] = i + 1;
            } else {
                dp[0][i] = i;
                for (int j = i + 1; j < word2.size(); j++) {
                    dp[0][j] = j;
                }
                break;
            }
        }
        for (int k = 0; k < word1.size(); k++) {
            if (word1[k] != word2[0]) {
                dp[k][0] = k + 1;
            } else {
                dp[k][0] = k;
                for (int l = k + 1; l < word1.size(); l++) {
                    dp[l][0] = l;
                }
                break;
            }
        }
        for (int m = 1; m < word1.size(); m++) {
            for (int n = 1; n < word2.size(); n++) {
                if (word1[m] == word2[n]) {
                    dp[m][n] = dp[m - 1][n - 1];
                } else {
                    dp[m][n] = min({dp[m - 1][n - 1], dp[m][n - 1], dp[m - 1][n]}) + 1;
                }
            }
        }
        return dp[word1.size() - 1][word2.size() - 1];
    }
};

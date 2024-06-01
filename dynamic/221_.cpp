//
// Created by 韩国庆 on 2024/5/28.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        int dp[h][w];
        for (int i = 0; i < w; i++) {
            if (matrix[0][i] == '0') {
                dp[0][i] = 0;
            } else {
                dp[0][i] = 1;
            }
        }
        for (int j = 1; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (matrix[j][k] == '0') {
                    dp[j][k] = 0;
                } else if (k == 0) {
                    dp[j][k] = 1;
                } else {
                    dp[j][k] = 1 + min({dp[j - 1][k - 1], dp[j - 1][k], dp[j][k - 1]});
                }
            }
        }
        int maxValue = 0;
        for (int m = 0; m < h; m++) {
            for (int n = 0; n < w; n++) {
                maxValue = max(maxValue, dp[m][n]);
                // cout << dp[m][n] << ' ';
            }
            // cout << endl;
        }

        return maxValue * maxValue;
    }
};

int main() {
    Solution s;
    vector<vector<char>> vec = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    int result = s.maximalSquare(vec);
    cout << result << endl;

    return 0;
}

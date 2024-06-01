//
// Created by 韩国庆 on 2024/5/26.
//
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int recursion(int row, int col, vector<vector<int>> &obstacleGrid) {
        // base case
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        if (row == h - 1) {
            for (int i = col; i < obstacleGrid[0].size(); i++) {
                if (obstacleGrid[row][i] == 1) {
                    return 0;
                }
            }
            return 1;
        }
        if (col == w - 1) {
            for (int j = row; j < obstacleGrid.size(); j++) {
                if (obstacleGrid[j][col] == 1) {
                    return 0;
                }
            }
            return 1;
        }
        if (obstacleGrid[row][col] == 1) {
            return 0;
        }
        return recursion(row, col + 1, obstacleGrid) + recursion(row + 1, col, obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int result = recursion(0, 0, obstacleGrid);

        return result;
    }

    int uniquePathsWithObstacles2(vector<vector<int>> &obstacleGrid) {
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        if (obstacleGrid[h - 1][w - 1] == 1) {
            return 0;
        }
        size_t dp[h][w];
        dp[h - 1][w - 1] = 1;
        for (int i = w - 2; i >= 0; i--) {
            if (obstacleGrid[h - 1][i] == 1) {
                dp[h - 1][i] = 0;
            } else {
                dp[h - 1][i] = dp[h - 1][i + 1];
            }
        }
        for (int j = h - 2; j >= 0; j--) {
            if (obstacleGrid[j][w - 1] == 1) {
                dp[j][w - 1] = 0;
            } else {
                dp[j][w - 1] = dp[j + 1][w - 1];
            }
        }
        for (int k = h - 2; k >= 0; k--) {
            for (int l = w - 2; l >= 0; l--) {
                if (obstacleGrid[k][l] == 1) {
                    dp[k][l] = 0;
                } else {
                    dp[k][l] = dp[k][l + 1] + dp[k + 1][l];
                }
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution s;
    vector<vector<int>> vec = {{0, 0},
                               {0, 1}};
    int result = s.uniquePathsWithObstacles2(vec);
    cout << result << endl;

    return 0;
}

//
// Created by 韩国庆 on 2024/5/19.
//
#include <vector>

using namespace std;

class Solution {
public:
    int recursion(vector<vector<int>> &grid) {
        if (grid.size() == 1) {
            int sum = 0;
            for (int i = 0; i < grid[0].size(); i++) {
                sum += grid[0][i];
            }
            return sum;
        }
        if (grid[0].size() == 1) {
            int sum = 0;
            for (int j = 0; j < grid.size(); j++) {
                sum += grid[j][0];
            }
            return sum;
        }
        vector<vector<int>> vec1;
        for (int k = 1; k < grid.size(); k++) {
            vec1.push_back(grid[k]);
        }
        vector<vector<int>> vec2;
        for (int l = 0; l < grid.size(); l++) {
            vector<int> tmp;
            for (int m = 1; m < grid[0].size(); m++){
                tmp.push_back(grid[l][m]);
            }
            vec2.push_back(tmp);
        }
        int p1 = recursion(vec1);
        int p2 = recursion(vec2);

        return grid[0][0] + min(p1, p2);
    }

    int minPathSum(vector<vector<int>> &grid) {
        int result = recursion(grid);

        return result;
    }

    int minPathSum2(vector<vector<int>> &grid) {
        int h = grid.size();
        int w = grid[0].size();
        int dp[h][w];
        dp[h - 1][w - 1] = grid[h - 1][w - 1];
        for (int i = w - 2; i >= 0; i--) {
            dp[h - 1][i] = grid[h - 1][i] + dp[h - 1][i + 1];
        }
        for (int j = h - 2; j >=0; j--){
            dp[j][w - 1] = grid[j][w - 1] + dp[j + 1][w - 1];
        }
        for (int k = h - 2; k >= 0; k--) {
            for (int l = w - 2; l >= 0; l--) {
                dp[k][l] = grid[k][l] + min(dp[k + 1][l], dp[k][l + 1]);
            }
        }
        return dp[0][0];
    }
};

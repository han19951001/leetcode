//
// Created by 韩国庆 on 2024/5/28.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int recursion(int row, int index, vector<vector<int>>& triangle) {
        // base case
        if (triangle.size() == row) {
            return triangle[row - 1][index];
        }
        int p1 = recursion(row + 1, index, triangle);
        int p2 = recursion(row + 1, index + 1, triangle);

        return triangle[row - 1][index] + min(p1, p2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int result = recursion(1, 0, triangle);

        return result;
    }

    int minimumTotal2(vector<vector<int>>& triangle) {
        int h = triangle.size();
        if (h == 1) {
            return triangle[0][0];
        }
        vector<int> vec(triangle[h - 1].begin(), triangle[h - 1].end());
        for (int i = h - 2; i >= 0; i--) {
            vector<int> tmp;
            for (int j = 0; j < triangle[i].size(); j++) {
                tmp.push_back(triangle[i][j] + min(vec[j], vec[j + 1]));
            }
            vec = tmp;
        }

        return vec[0];
    }
};

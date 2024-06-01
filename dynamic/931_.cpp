//
// Created by 韩国庆 on 2024/5/28.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        vector<int> vec(matrix[0].begin(), matrix[0].end());
        for (int i = 1; i < h; i++) {
            vector<int> tmp;
            for (int j = 0; j < w; j++) {
                if (j == 0) {
                    tmp.push_back(matrix[i][j] + min(vec[j], vec[j + 1]));
                } else if (j == w - 1) {
                    tmp.push_back(matrix[i][j] + min(vec[j], vec[j - 1]));
                } else {
                    tmp.push_back(matrix[i][j]+ min({vec[j - 1], vec[j], vec[j + 1]}));
                }
            }
            vec = tmp;
        }

        return *min_element(vec.begin(), vec.end());
    }
};

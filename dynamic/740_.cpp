//
// Created by 韩国庆 on 2024/5/12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int recursion(int start, int end, vector<int> &nums) {
        if (start == end - 1) {
            return nums[start];
        } else if (start > end - 1) {
            return 0;
        }
        int p1 = nums[start];
        int i = start + 1;
        while (i < end && nums[i] == nums[start]) {
            p1 += nums[start];
            i++;
        }
        if (i == end) {
            return p1;
        } else if (nums[i] - nums[start] > 1) {
            return p1 + recursion(i, end, nums);
        }
        int p2 = recursion(i, end, nums);
        while (i < end && nums[i] - nums[start] == 1) {
            i++;
        }
        if (i == end) {
            return max(p1, p2);
        }

        return max(p1 + recursion(i, end, nums), p2);

    }

    int deleteAndEarn(vector<int> &nums) {
        // base case
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        // 1. 排序
        sort(nums.begin(), nums.end());
        int result = recursion(0, nums.size(), nums);

        return result;
    }

    int deleteAndEarn2(vector<int> &nums) {
        // base case
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        int dp[nums.size()];
        dp[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i + 1] - nums[i] > 1) {
                dp[i] = nums[i] + dp[i + 1];
                continue;
            }
            if (nums[i + 1] - nums[i] == 1) {
                int j = i + 2;
                while (j < nums.size() && nums[j] - nums[i] == 1) {
                    j++;
                }
                if (j == nums.size()) {
                    dp[i] = max(nums[i], dp[i + 1]);
                    continue;
                }
                dp[i] = max(nums[i] + dp[j], dp[i + 1]);
                continue;
            }
            if (nums[i + 1] == nums[i]) {
                int k = i + 2;
                int p = 2 * nums[i];
                while (k < nums.size() && nums[k] == nums[i]) {
                    p += nums[i];
                    k++;
                }
                if (k == nums.size()) {
                    dp[i] = nums[i] + dp[i + 1];
                    continue;
                }
                if (nums[k] - nums[i] > 1) {
                    dp[i] = nums[i] + dp[i + 1];
                    continue;
                }
                while (k < nums.size() && nums[k] == nums[i] + 1) {
                    k++;
                }
                if (k == nums.size()) {
                    dp[i] = max(p, dp[i + 1]);
                    continue;
                }
                dp[i] = max(p + dp[k], dp[i + 1]);
                continue;
            }
        }
        return dp[0];
    }
};

int main() {
    // cout << "Hello C++!" << endl;
    Solution s = Solution();
    vector<int> v = {12, 32, 93, 17, 100, 72, 40, 71, 37, 92, 58, 34, 29, 78, 11, 84, 77, 90, 92, 35, 12, 5, 27, 92, 91,
                     23, 65, 91, 85, 14, 42, 28, 80, 85, 38, 71, 62, 82, 66, 3, 33, 33, 55, 60, 48, 78, 63, 11, 20, 51,
                     78, 42, 37, 21, 100, 13, 60, 57, 91, 53, 49, 15, 45, 19, 51, 2, 96, 22, 32, 2, 46, 62, 58, 11, 29,
                     6, 74, 38, 70, 97, 4, 22, 76, 19, 1, 90, 63, 55, 64, 44, 90, 51, 36, 16, 65, 95, 64, 59, 53, 93};
    // int result = s.deleteAndEarn(v);
    int result = s.deleteAndEarn2(v);
    cout << result << endl;

    return 0;
}

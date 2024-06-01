//
// Created by 韩国庆 on 2024/5/29.
//
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isInWordDict(string &s, vector<string> &wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            if (s == wordDict[i]) {
                return true;
            }
        }

        return false;
    }

    bool dfs(int index, string &s, vector<string> &wordDict, unordered_set<int>& mySet) {
        // base case
        if (index >= s.size()) {
            // 索引越界则符合条件
            return true;
        }
        for (int i = index; i < s.size(); i++) {
            // 指针左边的字符串
            string substr = s.substr(index, i - index + 1);

            if (isInWordDict(substr, wordDict)) {
                if (mySet.find(i + 1) != mySet.end()) {
                    continue;
                }

                if (dfs(i + 1, s, wordDict, mySet)) {
                    return true;
                }

                mySet.insert(i + 1);
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<int> mySet;

        bool result = dfs(0, s, wordDict, mySet);

        return result;
    }
};

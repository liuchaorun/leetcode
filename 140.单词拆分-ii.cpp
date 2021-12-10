#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
private:
    vector<string> ans;
    int minLength, maxLength;

public:
    void dfs(int start, string s, unordered_set<string> wordSet, string& res) {
        int sLength = s.size();
        if (start == sLength) {
            res.pop_back();
            ans.push_back(res);
        }
        for (int i = minLength; i <= min(maxLength, sLength - start); i++) {
            string temp = s.substr(start, i);
            if (wordSet.find(temp) != wordSet.end()) {
                string t = res + temp + ' ';
                dfs(start + i, s, wordSet, t);
            }
        }
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        maxLength = minLength = wordDict[0].length();
        for (auto& words:wordDict) {
            int length = words.length();
            if (length < minLength) {
                minLength = length;
            } else if (length > maxLength) {
                maxLength = length;
            }
        }
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        string temp;
        dfs(0, s, wordSet, temp);
        return ans;
    }
};
// @lc code=end

int main() {
    string s = "catsandog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    Solution solution;
    vector<string> res = solution.wordBreak(s, wordDict);
    cout<<"f";
    return 0;
}

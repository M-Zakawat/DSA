class Solution {
public:
    vector<string> ans;

    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtrack(string &digits, int index, string current) {

        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mp[digits[index]];

        for (char ch : letters) {
            backtrack(digits, index + 1, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        backtrack(digits, 0, "");

        return ans;
    }
};

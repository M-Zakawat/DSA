class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        backtrack(res, cur, n, 0, 0);
        return res;
    }

private:
    void backtrack(vector<string>& res, string& cur, int n, int open, int close) {
        if (cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }

        // Add '(' if we still have some left
        if (open < n) {
            cur.push_back('(');
            backtrack(res, cur, n, open + 1, close);
            cur.pop_back();
        }

        // Add ')' only if it won't exceed the number of '('
        if (close < open) {
            cur.push_back(')');
            backtrack(res, cur, n, open, close + 1);
            cur.pop_back();
        }
    }
};

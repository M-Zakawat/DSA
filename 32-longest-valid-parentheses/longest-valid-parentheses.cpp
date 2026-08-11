class Solution {
public:
    int longestValidParentheses(string s) {
        int n = (int)s.size();
        int maxLen = 0;
        stack<int> st;
        st.push(-1);  // base index for first valid substring

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else { // s[i] == ')'
                st.pop();
                if (st.empty()) {
                    st.push(i);  // new base
                } else {
                    int len = i - st.top();
                    if (len > maxLen) maxLen = len;
                }
            }
        }

        return maxLen;
    }
};